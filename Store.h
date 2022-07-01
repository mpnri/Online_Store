#ifndef STORE_H_INCLUDED
#define STORE_H_INCLUDED

#include <map>
#include "Product.h"
#include "Stock.h"
#include "Customer.h"

typedef std::map<int, Product> product_map;
typedef std::map<int, Customer> customer_map;

class Store
{
private:
    product_map products;
    Stock stock;
    customer_map customers;
public:
    Store(); // todo: read from file
    void customer_action();
    void stock_status();
    void check_out(int);
    void add_customer();
    void add_product();
    void view_products();
    void save_to_file(); // todo
    void sales_report();
    ~Store(); // todo: save to file
};

#endif // STORE_H_INCLUDED
