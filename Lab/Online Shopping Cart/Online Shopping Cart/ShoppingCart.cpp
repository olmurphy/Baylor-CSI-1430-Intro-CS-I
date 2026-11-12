

#include "ShoppingCart.h"

ShoppingCart::ShoppingCart() {
    customerName = "none";
    currentDate = "January 1, 2016";
}
ShoppingCart::ShoppingCart(string name, string date) {
    customerName = name;
    currentDate = date;
}

string ShoppingCart::GetCustomerName() const {
    return customerName;
}
string ShoppingCart::GetDate() const {
    return currentDate;
}

void ShoppingCart::AddItem(const ItemToPurchase itemName) {
    cartItems.push_back(itemName);
}
void ShoppingCart::RemoveItem(const string itemName) {
    unsigned int i;
    bool itemFound = false;
    if(cartItems.size() > 0) {
        for (i = 0; i < cartItems.size(); ++i) {
            if(itemName == cartItems.at(i).GetName()) {
                itemFound = true;
                cartItems.erase(cartItems.begin() + i);
                cout << endl;
            }
        }
    }
    if (!itemFound) {
        cout << "Item not found in cart. Nothing removed." << endl << endl;
    }
    
}

void ShoppingCart::ModifyItem(const ItemToPurchase item) {
    unsigned int i;
    bool itemFound = false;
    if (cartItems.size() > 0) {
        for(i = 0; i < cartItems.size(); ++i) {
            if(item.GetName() == cartItems.at(i).GetName()) {
                itemFound = true;
                cartItems.at(i).SetQuantity(item.GetQuantity());
            }
        }
    }
    if(!itemFound) {
        cout << "Item not found in cart. Nothing modified." << endl << endl;
    }
}

int ShoppingCart::GetNumItemsInCart() const {
    int totalQ = 0;
    unsigned int i;
    for (i = 0; i < cartItems.size(); ++i) {
        totalQ += cartItems.at(i).GetQuantity();
    }
    return totalQ;
}

double ShoppingCart::GetCostOfCart() const {
    double totalCost = 0;
    unsigned int i;
    if(cartItems.size() > 0) {
        for(i = 0; i < cartItems.size(); ++i) {
            totalCost += (cartItems.at(i).GetPrice()
                          * cartItems.at(i).GetQuantity());
        }
    }
    
    return totalCost;
}

void ShoppingCart::PrintTotal() const {
    double totalCost;
    
    totalCost = GetCostOfCart();
    if(totalCost > 0) {
        unsigned int i;
        if(cartItems.size() > 0) {
            for (i = 0; i < cartItems.size(); ++i) {
                cout << cartItems.at(i).GetName() << " "
                     << cartItems.at(i).GetQuantity() << " @ $"
                     << cartItems.at(i).GetPrice() << " = $"
                     << (cartItems.at(i).GetPrice() *
                         cartItems.at(i).GetQuantity()) << endl;
            }
        }
        
        cout << endl << "Total: $" << totalCost << endl << endl;
    }
    else {
        cout << "SHOPPING CART IS EMPTY" << endl << endl;
        cout << "Total: $" << totalCost << endl << endl;
    }
}
void ShoppingCart::PrintDescriptions() const {
    unsigned int i;
    
    if (cartItems.size() > 0) {
        for(i = 0; i < cartItems.size(); ++i) {
            cout << cartItems.at(i).GetName() << ": "
                 << cartItems.at(i).GetDescription() << endl;
        }
    }
}
