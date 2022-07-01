/**
>>> In The Name Of GOD
**/
#include <iostream>
#include <string>
#include "Store.h"

using namespace std;

int main()
{
    Store Aut;
    // todo: read from file
    while (true)
    {
        string order;
        cin >> order;
        //cout << "--- " << order << endl;
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

        if (order == "checkout")
        {
            int customer_id;
            string tmp;
            cin >> tmp >> customer_id;
            Aut.check_out(customer_id);
        }
    }
    // todo: save to file
    return 0;
}
