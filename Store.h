#ifndef STORE_H_INCLUDED
#define STORE_H_INCLUDED

#include <vector>
#include <utility>
#include "Product.h"
#include "Stock.h"
#include "Customer.h"

class Store
{
private:
    std::vector<Product> products;
    Stock stock;
    std::vector<Customer> customers;
public:
    Store(/* args */) {}
    void check_out(const Customer&);
    void add_customer();
    void add_product();
    void view_products();
    void save_to_file();
    void sales_report(const Date&, const Date&);
    ~Store() {}
};

#endif // STORE_H_INCLUDED
