#include "Cart.h"
#include <stdexcept>
#include <iostream>

Cart::Cart(const product_map &products)
    : product_list(products)
{}

void Cart::add(int id, int cnt)
{
    //! From Stock???
    this->item_cnt[id] += cnt;
}

void Cart::remove(int id)
{
    if (this->item_cnt.find(id) == this->item_cnt.end())
        throw std::invalid_argument("Invalid Product ID");
    this->item_cnt.erase(this->item_cnt.find(id));
}

void Cart::reset()
{
    this->item_cnt.clear();
}

float Cart::get_total_price()
{
    float total = 0;
    for (auto item : this->item_cnt)
        total += product_list.find(item.first)->second.price * item.second;
    return total;
}

void Cart::print()
{
    for (auto item : this->item_cnt)
        std::cout << product_list.find(item.first)->second << std::endl
                  << "-> Quantity : " << item.second << std::endl << std::endl;
    std::cout << "total price: " << this->get_total_price() << std::endl;
}
