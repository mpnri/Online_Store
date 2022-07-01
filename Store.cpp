#include "Store.h"
#include <string>
#include <iostream>
#include <fstream>

typedef std::map<int, int> item_counter;

Store::Store()
{
    std::fstream data("data");
    if (!data)
        return;
    std::cout << "data loaded!" << std::endl;
    int customer_size;
    data >> customer_size;
    for (int i = 0; i < customer_size; i++)
    {
        int id;
        std::string name, phone_number, address;
        float balance;

        data >> id;

        data.ignore();
        std::getline(data, name);

        data >> phone_number;

        data.ignore();
        std::getline(data, address);

        data >> balance;

        Customer customer(this->products, id, name, phone_number, address, balance);

        int size;
        //* Cart
        data >> size;
        for (int j = 0; j < size; j++)
        {
            int item_id, item_cnt;
            data >> item_id >> item_cnt;
            customer.cart.add(item_id, item_cnt);
        }

        //* History
        data >> size;
        for (int j = 0; j < size; j++)
        {
            Date date;
            item_counter counter;
            int receipt_size;
            data >> receipt_size;
            data >> date;
            for (int k = 0; k < receipt_size; k++)
            {
                int item_id, item_cnt;
                data >> item_id >> item_cnt;
                counter.insert({item_id, item_cnt});
            }
            Receipt receipt(this->products, counter, date);
            customer.history.push_back(receipt);
        }
        this->customers.insert({id, customer});
    }

    //* Products
    int product_size;
    data >> product_size;
    for (int i = 0; i < product_size; i++)
    {
        int id, quantity;
        std::string name, brand;
        float price;
        Date expire_date;

        data >> id;

        data.ignore();
        std::getline(data, name);

        data >> price;

        data.ignore();
        std::getline(data, brand);

        data >> expire_date;

        data >> quantity;

        Product product(id, name, price, brand, expire_date);
        this->products.insert({id, product});
        this->stock.change_count_by(id, quantity);
    }
}

Store::~Store()
{
    this->save_to_file();
}

void Store::check_out(int customer_id)
{
    if (this->customers.find(customer_id) == this->customers.end())
        throw std::invalid_argument("Invalid Customer ID");
    this->customers.find(customer_id)->second.convert_cart_to_receipt(this->stock);

    //? message
    std::cout << "Customer " << customer_id << " checkout successfully!" << std::endl
              << "-> total purchase amount: " << this->customers.find(customer_id)->second.get_total_purchase_amount() << std::endl
              << "------------------------------------------------------" << std::endl;
}

void Store::customer_action()
{
    int customer_id, product_id;
    std::string action;
    std::cin >> customer_id >> action;
    if (this->customers.find(customer_id) == this->customers.end())
        throw std::invalid_argument("Invalid Customer ID");
    if (action == "reset")
        this->customers.find(customer_id)->second.cart.reset();
    else if (action == "status")
    {
        this->customers.find(customer_id)->second.status();
        std::cout << "------------------------------------------------------" << std::endl;
        return;
    }
    else
    {
        std::cin >> product_id;
        if (action == "add")
            this->customers.find(customer_id)->second.cart.add(product_id, 1);
        else if (action == "remove")
            this->customers.find(customer_id)->second.cart.remove(product_id);
    }
    std::cout << "action done!" << std::endl;
    this->customers.find(customer_id)->second.cart.print();
    std::cout << "------------------------------------------------------" << std::endl;
}

void Store::stock_status()
{
    std::cout << "Stock: " << std::endl;
    for (auto item : this->products)
        if (this->stock.get_count(item.first))
            std::cout << item.second << std::endl
                      << "-> Quantity: " << this->stock.get_count(item.first) << std::endl
                      << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
}

void Store::add_customer()
{
    int id;
    std::string name, phone_number, address;
    float balance;

    std::cout << "- ID: ";
    std::cin >> id;

    if (this->customers.find(id) != this->customers.end())
    {
        std::cout << "This ID has already been selected." << std::endl;
        return;
    }

    std::cout << "- name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "- phone_number: ";
    std::cin >> phone_number;

    std::cout << "- address: ";
    std::cin.ignore();
    std::getline(std::cin, address);

    std::cout << "- balance: ";
    std::cin >> balance;

    Customer customer(this->products, id, name, phone_number, address, balance);
    this->customers.insert({id, customer});
    std::cout << "Customer " << id << " added successfully!" << std::endl
              << "------------------------------------------------------" << std::endl;
}

void Store::add_product()
{
    int id, quantity;
    std::string name, brand;
    float price;
    Date expire_date;

    std::cout << "- ID: ";
    std::cin >> id;

    std::cout << "- name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "- price: ";
    std::cin >> price;

    std::cin.ignore();
    std::cout << "- brand: ";
    std::getline(std::cin, brand);

    std::cout << "- Expire date: ";
    std::cin >> expire_date;

    std::cout << "- In stock: ";
    std::cin >> quantity;
    // std::cout << quantity << std::endl;
    Product product(id, name, price, brand, expire_date);

    this->products.insert({id, product});
    this->stock.change_count_by(id, quantity);
    std::cout << "Product " << id << " added successfully!" << std::endl
              << "------------------------------------------------------" << std::endl;
}

void Store::view_products()
{
    for (auto item : this->products)
        std::cout << item.second << std::endl
                  << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
}

void Store::save_to_file()
{
    std::ofstream data("data");
    data << this->customers.size() << std::endl;
    for (auto customer : this->customers)
    {
        data << customer.second.id << std::endl;
        data << customer.second.name << std::endl;
        data << customer.second.phone_number << std::endl;
        data << customer.second.address << std::endl;
        data << customer.second.balance << std::endl;

        data << customer.second.cart.item_cnt.size() << std::endl;
        for (auto item : customer.second.cart.item_cnt)
            data << item.first << ' ' << item.second << std::endl;

        data << customer.second.history.size() << std::endl;

        for (auto receipt : customer.second.history)
        {
            data << receipt.items.size() << std::endl;
            data << receipt.date.to_str() << std::endl;
            for (auto item : receipt.items)
                data << item.first << ' ' << item.second << std::endl;
        }
    }

    data << this->products.size() << std::endl;
    for (auto product : this->products)
    {
        data << product.second.id << std::endl;
        data << product.second.name << std::endl;
        data << product.second.price << std::endl;
        data << product.second.brand << std::endl;
        data << product.second.expire_date.to_str() << std::endl;
        data << this->stock.get_count(product.second.id) << std::endl;
    }
    std::cout << "data saved!" << std::endl
              << std::endl;
}

void Store::sales_report()
{
    Date start, end;
    std::cout << "start date: ";
    std::cin >> start;

    std::cout << "end date: ";
    std::cin >> end;

    std::cout << "Sales Report: " << std::endl;
    std::map<std::string, float> sales;
    for (auto customer : this->customers)
        for (auto receipt : customer.second.history)
            sales[receipt.get_date().to_str()] += receipt.get_total_price();
    for (auto date = start; date.to_str() != end.to_str(); date++)
    {
        std::cout << date.getYear() << '.' << date.getMonth() << '.' << date.getDay() << ": ";
        while (sales[date.to_str()] >= 100)
            std::cout << "++ ", sales[date.to_str()] -= 100;
        std::cout << std::endl;
    }
    std::cout << "------------------------------------------------------" << std::endl;
}
