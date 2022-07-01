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
    Store(/* args */) {}
    void customer_action();
    void check_out(int);
    void add_customer();
    void add_product();
    void view_products();
    void save_to_file(); // todo
    void sales_report(const Date&, const Date&); // todo
    ~Store() {}
};

#endif // STORE_H_INCLUDED
