#include<stdio.h>
#include<string.h>

#include "ItemToPurchase.h"

void MakeItemBlank(ItemToPurchase itemToPurchase) {
    itemToPurchase.itemName[MAX_STRING_LENGTH] = "none";
    itemToPurchase.itemDescription[MAX_STRING_LENGTH] = *"none";
    itemToPurchase.itemPrice = 0;
    itemToPurchase.itemQuantity = 0;
}

void PrintItemCost(ItemToPurchase itemToPurchase) {
    int totalCost = itemToPurchase.itemPrice * itemToPurchase.itemQuantity;
    printf("%s %d @ $%d = $%d\n", itemToPurchase.itemName, itemToPurchase.itemQuantity, itemToPurchase.itemPrice, totalCost);
}

void PrintItemDescription(ItemToPurchase itemToPurchase) {
    printf("%s: %s.\n", itemToPurchase.itemName, itemToPurchase.itemDescription);
}