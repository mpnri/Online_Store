/**
>>> In The Name Of GOD
**/
#include <iostream>
#include <string>
#include "Store.h"
#include <ctime>

using namespace std;

int main()
{
    Store Aut;
    while (true)
    {
        string order;
        cin >> order;
        if (order == "exit")
            break;
        if (order == "add")
        {
            string tmp;
            cin >> tmp;
            if (tmp == "product")
                Aut.add_product();
            else
                Aut.add_customer();
        }

        if (order == "customer")
            Aut.customer_action();

        if (order == "product") //* list
            Aut.view_products();

        if (order == "stock") //* list
            Aut.stock_status();

        if (order == "sales") //* report
        {
            string tmp;
            cin >> tmp;
            Aut.sales_report();
        }

        if (order == "save") //* data
            Aut.save_to_file();
        if (order == "checkout")
        {
            int customer_id;
            string tmp;
            cin >> tmp >> customer_id;
            Aut.check_out(customer_id);
        }
    }

    return 0;
}
