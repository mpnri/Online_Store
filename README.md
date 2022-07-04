# Online Store C++ Project

authored by @Mpnri

## Run Project with command line

```if ($?) { g++ main.cpp Store.cpp Cart.cpp Customer.cpp Date.cpp Receipt.cpp Stock.cpp -o main } ; if ($?) { .\main }```

## Guid commands

* **```add product```**: adding product

  write: id, name, price, brand, expire date, quantity
  
<br>

* **```add customer```**: adding customer

  write: id, name, phone number, address, balance
  
<br>

* **```customer {id} add {product_id}```**: add product to customer's card

<br>

* **```customer {id} remove {product_id}```**: remove product from customer's card

<br>

* **```customer {id} reset```**: clear customer's card

<br>

* **```customer {id} status```**: customer status

<br>

* **```product list```**: show product list(all of them)

<br>

* **```stock list```**: show stock list(available products)

<br>

* **```checkout customer {id}```**: convert card to receipt(buy items)

<br>

* **```sales report```**: report sales from start time to end time

<br>

* **```save data```**: save data to "data"

## input example
```
data loaded!
add product
- ID: 122
- name: Galaxy S22 Ultra
- price: 1200
- brand: Phone
- Expire date: 2024/06/01
- In stock: 200
Product 122 added successfully!
------------------------------------------------------

add customer
- ID: 12
This ID has already been selected.
Arian
09121234567
Amirkabir University of Technology, Tehran, Iran
120000

customer 12 add 122
action done!
-> ID: 122
-> name: Galaxy S22 Ultra
-> price: 1200
-> brand: Phone
-> expire date: June 1, 2024
-> Quantity : 1

total price: 1200
------------------------------------------------------
customer 12 add 122
action done!
-> ID: 122
-> name: Galaxy S22 Ultra
-> price: 1200
-> brand: Phone
-> expire date: June 1, 2024
-> Quantity : 2

total price: 2400
------------------------------------------------------
checkout customer 12
Customer 12 checkout successfully!
-> total purchase amount: 9700
------------------------------------------------------

customer 12 status
Cart:
total price: 0

Receipts History:
*** Date: July 2, 2022:
-> ID: 122
-> name: Galaxy S22 Ultra
-> price: 1200
-> brand: Phone
-> expire date: June 1, 2024
-> Quantity : 2

total price: 2400
+++++++++++++++++++++++
*** Date: July 2, 2022:
-> ID: 122
-> name: Galaxy S22 Ultra
-> price: 1200
-> brand: Phone
-> expire date: June 1, 2024
-> Quantity : 1

-> ID: 146
-> name: Asus 504i
-> price: 1850
-> brand: Laptop
-> expire date: January 9, 2024
-> Quantity : 2

total price: 4900
+++++++++++++++++++++++
*** Date: July 2, 2022:
-> ID: 122
-> name: Galaxy S22 Ultra
-> price: 1200
-> brand: Phone
-> expire date: June 1, 2024
-> Quantity : 2

total price: 2400
+++++++++++++++++++++++

-----> balance: 110300
------------------------------------------------------

add product
- ID: 146
- name: Asus 504i
- price: 1850
- brand: Laptop
- Expire date: 2024/01/09
- In stock: 18
Product 146 added successfully!
------------------------------------------------------

customer 12 add 146
action done!
-> ID: 146
-> name: Asus 504i
-> price: 1850
-> brand: Laptop
-> expire date: January 9, 2024
-> Quantity : 1

total price: 1850
------------------------------------------------------
customer 12 add 122
action done!
-> ID: 122
-> name: Galaxy S22 Ultra
-> price: 1200
-> brand: Phone
-> expire date: June 1, 2024
-> Quantity : 1

-> ID: 146
-> name: Asus 504i
-> price: 1850
-> brand: Laptop
-> expire date: January 9, 2024
-> Quantity : 1

total price: 3050
------------------------------------------------------
customer 12 add 146
action done!
-> ID: 122
-> name: Galaxy S22 Ultra
-> price: 1200
-> brand: Phone
-> expire date: June 1, 2024
-> Quantity : 1

-> ID: 146
-> name: Asus 504i
-> price: 1850
-> brand: Laptop
-> expire date: January 9, 2024
-> Quantity : 2

total price: 4900
------------------------------------------------------
checkout customer 12
Customer 12 checkout successfully!
-> total purchase amount: 14600
------------------------------------------------------

sales report
start date: 2022.6.30
end date: 2022.7.3
Sales Report:
2022.6.30:
2022.7.1:
2022.7.2: ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++
------------------------------------------------------

customer 12 status
Cart:
total price: 0

Receipts History:
*** Date: July 2, 2022:
-> ID: 122
-> name: Galaxy S22 Ultra
-> price: 1200
-> brand: Phone
-> expire date: June 1, 2024
-> Quantity : 2

total price: 2400
+++++++++++++++++++++++
*** Date: July 2, 2022:
-> ID: 122
-> name: Galaxy S22 Ultra
-> price: 1200
-> brand: Phone
-> expire date: June 1, 2024
-> Quantity : 1

-> ID: 146
-> name: Asus 504i
-> price: 1850
-> brand: Laptop
-> expire date: January 9, 2024
-> Quantity : 2

total price: 4900
+++++++++++++++++++++++
*** Date: July 2, 2022:
-> ID: 122
-> name: Galaxy S22 Ultra
-> price: 1200
-> brand: Phone
-> expire date: June 1, 2024
-> Quantity : 2

total price: 2400
+++++++++++++++++++++++
*** Date: July 2, 2022:
-> ID: 122
-> name: Galaxy S22 Ultra
-> price: 1200
-> brand: Phone
-> expire date: June 1, 2024
-> Quantity : 1

-> ID: 146
-> name: Asus 504i
-> price: 1850
-> brand: Laptop
-> expire date: January 9, 2024
-> Quantity : 2

total price: 4900
+++++++++++++++++++++++

-----> balance: 105400
------------------------------------------------------
exit
data saved!
```
