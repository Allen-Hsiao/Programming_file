#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H
#include <iostream>
#include <string>
using namespace std;

class ItemToPurchase {

    public:
        ItemToPurchase();
        ItemToPurchase(string inputname, string inputdescription, int inputprice, int inputquantity);
        void setName(string input_name);
        void setPrice(int input_price);
        void setQuantity(int input_quantity);
        string name()const;
        int price() const;
        int quantity() const;
        void setDescription(string input_description);
        string description() const;
        void printItemCost() const;
        void printItemDescription() const;



    private:
        string Name;
        int Price;
        int Quantity;
        string Description;

};
#endif