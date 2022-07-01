#include "Customer.h"

Customer::Customer(const product_map &product_list, int id, const std::string &name,
                   const std::string &phone_number, const std::string &address, float balance)
    : id(id), name(name), phone_number(phone_number),
      address(address), balance(balance), cart(product_list), product_list(product_list)
{} //! Cart problem!!

void Customer::convert_cart_to_receipt(Stock &stock)
{
    for (auto item : this->cart.item_cnt)
        stock.change_count_by(item.first, item.second);
    this->balance -= this->cart.get_total_price();
    Receipt receipt(product_list, this->cart.item_cnt); //todo: Set Date && add h m s to Date
    this->history.push_back(receipt);
    this->cart.reset();
}

float Customer::get_total_purchase_amount()
{
    float total = 0;
    for (auto receipt:this->history)
        total += receipt.get_total_price();
    return total;
}

void Customer::status()
{
    std::cout<< "Cart:" << std::endl;
    this->cart.print();
    std::cout << std::endl
    << "Receipts History: " << std::endl;
    for (auto receipt:this->history)
        receipt.print();
    std::cout << std::endl << "-----> balance: "  << this->balance << std::endl;
}