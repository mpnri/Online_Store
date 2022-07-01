#include "Receipt.h"

Receipt::Receipt(const product_map &products, const item_counter &item_cnt)
    : product_list(products)
{
    for (auto item : item_cnt)
        this->items.push_back(item);
}

float Receipt::get_total_price()
{
    float total = 0;
    for (auto item : this->items)
        total += product_list.find(item.first)->second.price * item.second;
    return total;
}