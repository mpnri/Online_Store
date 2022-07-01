#include "Store.h"
#include <string>
#include <iostream>

void Store::check_out(int customer_id)
{
    if (this->customers.find(customer_id) == this->customers.end())
        throw std::invalid_argument("Invalid Customer ID");
    this->customers.find(customer_id)->second.convert_cart_to_receipt(this->stock);
    std::cout << "Customer " << customer_id << " checkout successfully!" << std::endl
    << "-> total purchase amount: " << this->customers.find(customer_id)->second.get_total_purchase_amount() << std::endl
    << "------------------------------------------------------" << std::endl;
}

void Store::customer_action()
{
    int customer_id, product_id;
    std::string action;
    std::cin >> customer_id >> action;
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

void Store::add_customer()
{
    int id;
    std::string name, phone_number, address;
    float balance;

    std::cout << "- ID: ";
    std::cin >> id;

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
    std::cout << "Customer " << id << " added successfully!" << std::endl << "------------------------------------------------------" << std::endl;
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
    //std::cout << quantity << std::endl;
    Product product(id, name, price, brand, expire_date);
    
    this->products.insert({id, product});
    this->stock.change_count_by(id, quantity);
    std::cout << "Product " << id << " added successfully!" << std::endl << "------------------------------------------------------" << std::endl;
}

void Store::view_products()
{
    for (auto item:this->products)
        std::cout << item.second << std::endl << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
}

void Store::save_to_file() //todo
{

}

void Store::sales_report(const Date &start, const Date &end) //todo
{

}
