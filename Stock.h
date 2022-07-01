#ifndef STOCK_H_INCLUDED
#define STOCK_H_INCLUDED

#include <map>

class Stock
{
private:
    std::map<int, int> item_cnt;
public:
    Stock(/* args */) {}
    int get_count(int);
    void change_count_by(int, int);
    ~Stock() {}
};

#endif // STOCK_H_INCLUDED
