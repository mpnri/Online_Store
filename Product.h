#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED

#include <string>
#include "Date.h"
#include <iostream>

class Product
{
    friend class Receipt;
    friend class Cart;
    friend class Store;
    friend std::ostream &operator<<(std::ostream &output, const Product &product)
    {
        output << "-> ID: " << product.id << std::endl
               << "-> name: " << product.name << std::endl
               << "-> price: " << product.price << std::endl
               << "-> brand: " << product.brand << std::endl
               << "-> expire date: " << product.expire_date;
        return output;
    }

private:
    int id;
    std::string name;
    float price;
    std::string brand;
    Date expire_date;

public:
    Product(int id, const std::string &name, float price, const std::string &brand, const Date &expire_date)
        : id(id), name(name), price(price), brand(brand), expire_date(expire_date)
    {
    }
};

#endif // PRODUCT_H_INCLUDED
