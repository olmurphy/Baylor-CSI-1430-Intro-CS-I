
#ifndef ItemToPurchase_h
#define ItemToPurchase_h
#include <string>
#include <iostream>
#include <ostream>
using namespace std;

class ItemToPurchase {
private:
    string itemDescription;
    string itemName;
    double itemPrice;
    int itemQuantity;
    
    
public:
    ItemToPurchase();
    ItemToPurchase(string item, string desrip, double price, int quantity);
    void SetName(string);
    string GetName() const;
    void SetPrice(double);
    double GetPrice() const;
    void SetQuantity(int);
    int GetQuantity() const;
    void SetDescription(string);
    string GetDescription() const;
    void PrintItemCost(ostream&);
    void PrintItemDescription(ostream&);
};


#endif /* ItemToPurchase_h */
