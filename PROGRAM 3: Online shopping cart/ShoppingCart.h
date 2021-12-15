#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "ItemToPurchase.h"

class ShoppingCart {

    public:
        ShoppingCart();
        ShoppingCart(string inputname, string inputdate);
        string customerName() const;
        string date() const;
        void addItem(ItemToPurchase input_item);
        void removeItem(string itemname);
        void modifyItem(ItemToPurchase modifyinput);
        int numItemsInCart();
        int costOfCart();
        void printTotal();
        void printDescriptions();


    private:
        string CustomerName = "none";
        string currentDate = "January 1, 2016";
        vector <ItemToPurchase> cartItems;
};
#endif