#include "Receipt.h"

using namespace std;

Receipt::Receipt(const product_map &products)
    : product_list(products) {}

float Receipt::get_total_price()
{
    float total = 0;
    for (auto item : this->items)
        total += product_list.find(item.first)->second.price * item.second;
    return total;
}