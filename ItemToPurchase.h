#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H
#define MAX_STRING_LENGTH 100
#define MAX_DESCRIPTION_LENGTH 80

/* Defines the attributes of the ItemToPurchase struct*/
typedef struct ItemToPurchase{
    char itemName[MAX_STRING_LENGTH];
    char itemDescription[MAX_DESCRIPTION_LENGTH]; 
    int itemPrice;
    int itemQuantity;
} ItemToPurchase;

/**
 * Takes in a parameter that points to ItemToPurchase
 * Sets items to default setting, Sets item's name = "none", item's price = 0, item's quantity = 0
*/
void MakeItemBlank(ItemToPurchase itemToPurchase);

/**
 * Takes in a parameter that points to ItemToPurchase
 * Prints out ItemToPurchase with the following format:
 * <itemName> <itemQuantity> @ $<itemPrice> = <itemQuantity> * <itemPrice>
*/
void PrintItemCost(ItemToPurchase itemToPurchase);

/**
 * The following takes in a parameter that points to ItemToPurchase
 * the function then prints out a description of the item as follows:
 * <itemName>: <itemDescription>.
*/
void PrintItemDescription(ItemToPurchase itemToPurchase);

#endif