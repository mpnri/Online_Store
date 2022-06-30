#ifndef STOCK_H_INCLUDED
#define STOCK_H_INCLUDED

#include <vector>
#include <utility>

class Stock
{
private:
    std::vector<std::pair<int, int>> items;
public:
    Stock(/* args */) {}
    int get_count(int);
    void change_count_by(int, int);
    ~Stock() {}
};

#endif // STOCK_H_INCLUDED
