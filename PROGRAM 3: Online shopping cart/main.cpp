#include <iostream>

using namespace std;

// #include "ItemToPurchase.h"
#include "ShoppingCart.h"
// #include "ItemToPurchase.cpp"
// #include "ShoppingCart.cpp"

void printMenu(){
    cout << "MENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
    cout << "Choose an option: " << endl;
}

int main() {
    string Username;
    string Todaydate;
    cout << "Enter customer's name: " << endl;
    getline(cin, Username);

    cout << "Enter today's date: " << endl;
    getline(cin, Todaydate);
    cout << endl;

    ShoppingCart Usershoppingcart(Username, Todaydate);

    cout << "Customer name: " << Username << endl;
    cout << "Today's date: " << Todaydate << endl;

    cout << endl;
    char input_option;
    printMenu();

    cin >> input_option;
    cin.ignore();
    while (input_option != 'a' && input_option != 'd'&& input_option != 'c'&& input_option != 'i' && input_option != 'o' && input_option != 'q'){
        cout << "Choose an option: " << endl;
        cin >> input_option;
        cin.ignore();
    }
    while (input_option != 'q'){
        if (input_option == 'o'){
            cout << endl;
            cout << "OUTPUT SHOPPING CART" << endl;
            Usershoppingcart.printTotal();
        }
        else if (input_option == 'i'){
            cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
            Usershoppingcart.printDescriptions();
        }
        else if (input_option == 'a'){
            string itemname;
            string itemdescription;
            int itemprice;
            int itemquantity;
            ItemToPurchase additem;
            cout << "ADD ITEM TO CART" << endl;
            cout << "Enter the item name: " << endl;
            getline(cin, itemname);
            cout << "Enter the item description: " << endl;
            getline(cin, itemdescription);
            cout << "Enter the item price: " << endl;
            cin >> itemprice;
            cout << "Enter the item quantity: " << endl;
            cin >> itemquantity;
            cin.ignore();
            cout << endl;

            additem.setName(itemname);
            additem.setDescription(itemdescription);
            additem.setPrice(itemprice);
            additem.setQuantity(itemquantity);
            Usershoppingcart.addItem(additem);
        }
        else if (input_option == 'd'){
            string removename;
            cout << "REMOVE ITEM FROM CART" << endl;
            cout << "Enter name of item to remove: " << endl;
            getline(cin, removename);
            Usershoppingcart.removeItem(removename);
        }
        else if (input_option == 'c'){
            string changeitem;
            int changequantity;
            ItemToPurchase changeitem_class;
            cout << "CHANGE ITEM QUANTITY" << endl;
            //Not finish step 10
            cout << "Enter the item name: " << endl;
            getline(cin, changeitem);
            cout << "Enter the new quantity: " << endl;
            cin >> changequantity;
            cin.ignore();
            changeitem_class.setName(changeitem);
            changeitem_class.setQuantity(changequantity);
            Usershoppingcart.modifyItem(changeitem_class);
        }

        printMenu();
        cin >> input_option;
        cin.ignore();
    }

return 0;
}