#include "Stock.h"
#include <stdexcept>

int Stock::get_count(int id)
{
    if (this->item_cnt.find(id) == this->item_cnt.end())
        throw std::invalid_argument("Invalid Product ID");
    return this->item_cnt[id];
}

void Stock::change_count_by(int id, int count)
{
    this->item_cnt[id] += count;
}