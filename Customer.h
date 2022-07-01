#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

#include <string>
#include <vector>
#include "Receipt.h"
#include "Cart.h"
#include "Stock.h"

typedef std::map<int, Product> product_map;

class Customer
{
    friend class Store;

private:
    int id;
    std::string name;
    std::string phone_number;
    std::vector<Receipt> history;
    std::string address;
    Cart cart;
    float balance;
    const product_map &product_list;

public:
    Customer(const product_map &, int, const std::string & = "Ali",
             const std::string & = "09146385429", const std::string & = "Iran/Tehran", float = 0);
    void convert_cart_to_receipt(Stock &);
    float get_total_purchase_amount();
    void status();

    ~Customer() {}
};

#endif // CUSTOMER_H_INCLUDED
