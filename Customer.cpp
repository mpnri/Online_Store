#include "Customer.h"

Customer::Customer(int id, const product_map &product_list,const std::string &name,
                   const std::string &phone_number, const std::string &address, float balance)
    : id(id), name(name), phone_number(phone_number),
      address(address), balance(balance), cart(product_list), product_list(product_list)
{} //! Cart problem!!

void Customer::convert_cart_to_receipt()
{
    this->balance -= this->cart.get_total_price();
    Receipt receipt(product_list, this->cart.get_cart_list());
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
