#ifndef RECEIPT_H_INCLUDED
#define RECEIPT_H_INCLUDED

#include "Date.h"
#include <utility>
#include <vector>

class Receipt
{
private:
    std::vector <std::pair<int,int>> items;  //! id & quantity?
    Date date;

public:
    Receipt();
    float get_total_price();
    
};

#endif // RECEIPT_H_INCLUDED
