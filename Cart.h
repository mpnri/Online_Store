#ifndef CART_H_INCLUDED
#define CART_H_INCLUDED

#include <map>
#include "Product.h"

typedef std::map<int, Product> product_map;
typedef std::map<int, int> item_counter;

class Cart
{
    friend class Customer;
    friend class Store;

private:
    item_counter item_cnt;
    const product_map &product_list;

public:
    Cart(const product_map &);
    void add(int, int);
    void remove(int);
    void reset();
    float get_total_price();
    void print();
    ~Cart() {}
};

#endif // CART_H_INCLUDED
