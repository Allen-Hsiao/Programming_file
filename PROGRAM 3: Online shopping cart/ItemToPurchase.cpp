#include <iostream>
#include <string>
using namespace std;

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase(){
    Name = "none";
    Price = 0;
    Quantity = 0;
    Description = "none";
}
ItemToPurchase::ItemToPurchase(string inputname, string inputdescription, int inputprice, int inputquantity){
    Name = inputname;
    Price = inputprice;
    Quantity = inputquantity;
    Description = inputdescription;
}

void ItemToPurchase::setName(string input_name){
    Name = input_name;
}
void ItemToPurchase::setPrice(int input_price){
    Price = input_price;
}
void ItemToPurchase::setQuantity(int input_quantity){
    Quantity = input_quantity;
}
string ItemToPurchase::name()const{
    return Name;
}
int ItemToPurchase::price() const{
    return Price;
}
int ItemToPurchase::quantity() const{
    return Quantity;
}

void ItemToPurchase::setDescription(string input_description){
    Description = input_description;
}
string ItemToPurchase::description() const{
    return Description;
}
void ItemToPurchase::printItemCost() const{
    cout << Name << " " << Quantity << " @ $" << Price << " = $" << Quantity*Price << endl;
}
void ItemToPurchase::printItemDescription() const{
    cout << Name << ": " << Description << endl;
}