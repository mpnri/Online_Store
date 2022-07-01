#include "Customer.h"
#include <stdexcept>
#include <ctime>

Customer::Customer(const product_map &product_list, int id, const std::string &name,
                   const std::string &phone_number, const std::string &address, float balance)
    : id(id), name(name), phone_number(phone_number),
      address(address), balance(balance), cart(product_list), product_list(product_list)
{
} //! Cart problem!!

void Customer::convert_cart_to_receipt(Stock &stock)
{
    for (auto item : this->cart.item_cnt)
        if (stock.get_count(item.first) < item.second)
            throw std::out_of_range("Not enough stock");
    for (auto item : this->cart.item_cnt)
        stock.change_count_by(item.first, -item.second);
    this->balance -= this->cart.get_total_price();
    time_t now = time(0);
    auto local = localtime(&now);

    Date date(1900 + local->tm_year, 1 + local->tm_mon, local->tm_mday);
    Receipt receipt(product_list, this->cart.item_cnt, date); // todo: Set Date && add h m s to Date
    this->history.push_back(receipt);
    this->cart.reset();
}

float Customer::get_total_purchase_amount()
{
    float total = 0;
    for (auto receipt : this->history)
        total += receipt.get_total_price();
    return total;
}

void Customer::status()
{
    std::cout << "Cart:" << std::endl;
    this->cart.print();
    std::cout << std::endl
              << "Receipts History: " << std::endl;
    for (auto receipt : this->history)
        receipt.print();
    std::cout << std::endl
              << "-----> balance: " << this->balance << std::endl;
}