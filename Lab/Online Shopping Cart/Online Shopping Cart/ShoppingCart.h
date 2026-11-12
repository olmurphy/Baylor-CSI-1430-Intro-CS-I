

#ifndef ShoppingCart_h
#define ShoppingCart_h

#include <string>
#include "ItemToPurchase.h"
#include <vector>
using namespace std;


class ShoppingCart {
private:
    string customerName;
    string currentDate;
    vector<ItemToPurchase> cartItems;
public:
    ShoppingCart();
    ShoppingCart(string, string);
    
    string GetCustomerName() const;
    string GetDate() const;
    
    
    
    void AddItem(const ItemToPurchase);
    void RemoveItem(const string);
    
    void ModifyItem(const ItemToPurchase);
    
    int GetNumItemsInCart() const;
    double GetCostOfCart() const;
    
    void PrintTotal() const;
    void PrintDescriptions() const;
};

#endif /* ShoppingCart_h */
