#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

#include <string>
#include <vector>
#include "Receipt.h"
#include "Cart.h"

typedef std::map<int, Product> product_map;

class Customer
{
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
    Customer(int, const product_map&,  const std::string & = "Ali",
             const std::string & = "09146385429", const std::string & = "Iran/Tehran", float = 0);
    void convert_cart_to_receipt();
    float get_total_purchase_amount();
    ~Customer() {}
};

#endif // CUSTOMER_H_INCLUDED
