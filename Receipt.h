#ifndef RECEIPT_H_INCLUDED
#define RECEIPT_H_INCLUDED

#include "Date.h"
#include "Product.h"
#include <utility>
#include <vector>
#include <map>

typedef std::map<int, Product> product_map;
typedef std::map<int, int> item_counter;

class Receipt
{
    friend class Store;

private:
    std::vector<std::pair<int, int>> items; //! id & quantity
    Date date;                              // TODO: handle date & system date
    const product_map &product_list;

public:
    Receipt(const product_map &, const item_counter &, const Date &);
    float get_total_price();
    void print();
    Date get_date();
};

#endif // RECEIPT_H_INCLUDED
