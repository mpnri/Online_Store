#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED

#include <string>
#include "Date.h"
#include <iostream>

class Product
{
    friend class Receipt;
    friend class Cart;
    friend std::ostream& operator<<(std::ostream &output, const Product &product)
    {
        std::cout << "ID: " << product.id << std::endl
                  << "name: " << product.name << std::endl
                  << "brand: " << product.brand << std::endl
                  << "price: " << product.price << std::endl
                  << "expire date: " << product.expire_date;
        return output;
    }
private:
    int id;
    std::string name;
    float price;
    std::string brand;
    Date expire_date;
};

#endif // PRODUCT_H_INCLUDED
