#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "ShoppingCart.h"

ShoppingCart::ShoppingCart(){
    CustomerName = "none";
    currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string inputname, string inputdate){
    CustomerName = inputname;
    currentDate = inputdate;
}
string ShoppingCart::customerName() const{
    return CustomerName;
}
string ShoppingCart::date() const{
    return currentDate;
}
void ShoppingCart::addItem(ItemToPurchase input_item){
    cartItems.push_back(input_item);
}
void ShoppingCart::removeItem(string itemname){
    int index = 0;
    int count = 0;
    for (unsigned i = 0; i < cartItems.size(); ++i){
        if (itemname == cartItems.at(i).name()){
            count += 1;
            index = i;
        }
    }

    if (count == 1){
        cout << endl;
        cartItems.erase(cartItems.begin() + index);
    }
    else{
        cout << "Item not found in cart. Nothing removed." << endl;
        cout << endl;
    }
}
void ShoppingCart::modifyItem(ItemToPurchase modifyinput){
    int count = 0;
    for (unsigned i = 0; i < cartItems.size(); ++i){
        if (modifyinput.name() == cartItems.at(i).name()){
            count += 1;
            if(cartItems.at(i).description() != "none" && cartItems.at(i).price() != 0 && cartItems.at(i).quantity() != 0){
                modifyinput.setPrice(cartItems.at(i).price());
                cartItems.at(i) = modifyinput;
            }
        }
    }
    if (count == 0){
        cout << "Item not found in cart. Nothing modified." << endl;
        cout << endl;
    }
}
int ShoppingCart::numItemsInCart(){
    int total_quantity = 0;
    for (unsigned i =0; i < cartItems.size(); ++i){
        total_quantity += cartItems.at(i).quantity();
    }
    return total_quantity;
}
int ShoppingCart::costOfCart(){
    int total_cost = 0;
    for (unsigned i = 0; i < cartItems.size(); ++i){
        total_cost += cartItems.at(i).quantity()*cartItems.at(i).price();
    }
    return total_cost;
}
void ShoppingCart::printTotal(){
    cout << CustomerName << "'s Shopping Cart - " << currentDate << endl;
    if (numItemsInCart() == 0){
        cout << "Number of Items: " << numItemsInCart() << endl;
        cout << endl;
        cout << "SHOPPING CART IS EMPTY" << endl;
    }
    else{
        cout << "Number of Items: " << numItemsInCart() << endl;
        cout << endl;
    }
    for (unsigned i = 0; i < cartItems.size(); ++i){
        cartItems.at(i).printItemCost(); 
    }

    cout << endl;
    cout << "Total: $" << costOfCart() << endl;
    cout << endl;
}
void ShoppingCart::printDescriptions(){
    cout << CustomerName << "'s Shopping Cart - " << currentDate << endl;
    cout << endl;
    cout << "Item Descriptions" << endl;
    for (unsigned i = 0; i < cartItems.size(); ++i){
        cartItems.at(i).printItemDescription(); 
    }
    cout << endl;
}