#ifndef CART_H_INCLUDED
#define CART_H_INCLUDED

#include <vector>
#include <utility>

class Cart
{
private:
    std::vector<std::pair<int,int>> items;
public:
    Cart(/* args */) {}
    void add(int, int);
    void remove(int);
    void reset();
    float get_total_price();
    void print();
    ~Cart() {}
};

#endif // CART_H_INCLUDED
