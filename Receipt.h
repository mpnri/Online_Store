#ifndef RECEIPT_H_INCLUDED
#define RECEIPT_H_INCLUDED

#include "Date.h"
#include "Product.h"
#include <utility>
#include <vector>
#include <map>

typedef std::map<int, Product> product_map;

class Receipt
{
private:
    std::vector<std::pair<int, int>> items; //! id & quantity
    Date date;
    const product_map &product_list;

public:
    Receipt(const product_map &);
    float get_total_price();
};

#endif // RECEIPT_H_INCLUDED
