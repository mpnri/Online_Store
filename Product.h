#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED

#include <string>
#include "Date.h"

class Product
{
    friend class Receipt;
private:
    int id;
    std::string name;
    float price;
    std::string brand;
    Date expire_date;
};

#endif // PRODUCT_H_INCLUDED
