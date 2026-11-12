

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase() {
    itemName = "none";
    itemPrice = 0;
    itemQuantity = 0;
    itemDescription = "none";
}

ItemToPurchase::ItemToPurchase(string item, string desrip, double price = 0.0, int quantity = 0) {
    itemName = item;
    itemDescription = desrip;
    itemPrice = price;
    itemQuantity = quantity;
}

void ItemToPurchase::SetName(string name) {
    itemName = name;
}
string ItemToPurchase::GetName() const {
    return itemName;
}
void ItemToPurchase::SetPrice(double price) {
    itemPrice = price;
}
double ItemToPurchase::GetPrice() const {
    return itemPrice;
}
void ItemToPurchase::SetQuantity(int quantity) {
    itemQuantity = quantity;
}
int ItemToPurchase::GetQuantity() const {
    return itemQuantity;
}


void ItemToPurchase::SetDescription(string description) {
    itemDescription = description;
}
string ItemToPurchase::GetDescription() const {
    return itemDescription;
}
void ItemToPurchase::PrintItemCost(ostream& os) {
    os << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $"
       << itemPrice * itemQuantity;
}
void ItemToPurchase::PrintItemDescription(ostream& os) {
    os << itemName << ": " << itemDescription;
}

