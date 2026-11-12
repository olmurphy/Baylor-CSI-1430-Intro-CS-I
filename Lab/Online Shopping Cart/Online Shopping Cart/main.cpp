#include <iostream>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"
#include <string>
using namespace std;

void printMenuFunc(ShoppingCart);
void printMenu();

int main () {
   
    ItemToPurchase item ("Bottled Water", "Deer Park, 12 oz.", 1, 10);
   
    string customerName;
    string date;
    string line;
    
    cout << "Enter customer's name:" << endl;
    getline(cin, customerName);
    cout << "Enter today's date:" << endl << endl;
    getline(cin, date);
    
    cout << "Customer name: " << customerName << endl;
    cout << "Today's date: " << date << endl << endl;
    
    ShoppingCart customer(customerName, date);
    
    
    
    printMenuFunc(customer);

    
   return 0;
}

void printMenuFunc(ShoppingCart cart) {
    
    char key;
    int n;
    string line1, line2;
    do {
        printMenu();
        
        do {
            cout << "Choose an option:" << endl;
            cin >> key;
        } while (key != 'q' && key != 'a' && key != 'd' && key != 'c' && key != 'i'
                 && key != 'o');
        
        switch (key) {
            case 'o': {
                cout << "OUTPUT SHOPPING CART" << endl;
                cout << cart.GetCustomerName() << "'s Shopping Cart - "
                     << cart.GetDate() << endl;
                cout << "Number of Items: " << cart.GetNumItemsInCart() << endl
                     << endl;
                cart.PrintTotal();
                break;
            }
                
            case 'i': {
                cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
                cout << cart.GetCustomerName() << "'s Shopping Cart - "
                     << cart.GetDate() << endl << endl
                     << "Item Descriptions" << endl;
                cart.PrintDescriptions();
                cout << endl;
                break;
            }
                
            case 'a': {
                string line1, line2;
                int n;
                double b;
                cout << endl << "ADD ITEM TO CART" << endl;
                cout << "Enter the item name:" << endl;
                cin.ignore();
                getline(cin, line1);
                cout << "Enter the item description:" << endl;
                getline(cin, line2);
                cout << "Enter the item price:" << endl;
                cin >> b;
                cout << "Enter the item quantity:" << endl << endl;
                cin >> n;
                cart.AddItem(ItemToPurchase(line1, line2, b, n));
                break;
            }
                
            case 'd': {
                cout << "REMOVE ITEM FROM CART" << endl; // #12
                cout << "Enter name of item to remove:" << endl;
                cin.ignore();
                getline(cin, line1);
                cart.RemoveItem(line1);
                break;
            }
            
            case 'c': {
                cout << endl << endl << "CHANGE ITEM QUANTITY" << endl; // # 13
                cout << "Enter the item name:" << endl;
                cin.ignore();
                getline(cin, line1);
                cout << "Enter the new quantity:" << endl;
                cin >> n;
                ItemToPurchase newItem;
                newItem.SetName(line1);
                newItem.SetQuantity(n);
                cart.ModifyItem(newItem);
                
                
                
                break;
            }
                
        }
    } while (key != 'q');
    
    
}

void printMenu() {
    cout << "MENU\n";
    cout << "a - Add item to cart\n";
    cout << "d - Remove item from cart\n";
    cout << "c - Change item quantity\n";
    cout << "i - Output items' descriptions\n";
    cout << "o - Output shopping cart\n";
    cout << "q - Quit\n" << endl;
}

