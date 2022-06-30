#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

#include <string>
#include <vector>
#include "Receipt.h"

class Customer
{
private:
    int id;
    std:: string name;
    std:: string phone_number;
    std:: vector <Receipt> history;
    std:: string address;
    // Card
    float balance;

public:
    Customer(/* args */) {}
    void convert_cart_to_receipt();
    float get_total_purchase_amount(); 
    ~Customer() {}
};

#endif // CUSTOMER_H_INCLUDED
