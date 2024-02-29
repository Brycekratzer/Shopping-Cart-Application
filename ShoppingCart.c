#include<stdio.h>
#include<string.h>
#include "ShoppingCart.h"

ShoppingCart AddItem(ItemToPurchase item, ShoppingCart cart){
    if(cart.cartSize == MAX_CART_SIZE){
        printf("Item was not added; the cart is full\n");
    } else {
        cart.cartItems[cart.cartSize] = item;
        cart.cartSize++;
    }
    return cart;
}

ShoppingCart RemoveItem(char name[], ShoppingCart cart){
    int itemFound = -1; //error handling for non existant item
    for(int i = 0; i < cart.cartSize; i++){
        if (strcmp(cart.cartItems[i].itemName,name) == 0){
            for(int j = i; j < cart.cartSize - 1; j++){
                cart.cartItems[j] = cart.cartItems[j + 1]; //shifts elements based on where item was found
            }
            itemFound = 1;
            break;
        } 
    }
    if (itemFound == -1) {
        printf("Error: item not found in cart\n");
    } else {
        cart.cartSize--;
    }
    return cart;
}

int GetNumItemsInCart(ShoppingCart cart) {
    int totalNumItems = 0;
    for(int i = 0; i < cart.cartSize; i++){ //loops through array and adds all quantity's up
        totalNumItems += cart.cartItems[i].itemQuantity;
    }
    return totalNumItems;
}

int GetCostOfCart(ShoppingCart cart){
    int totalCost = 0;
    for(int i = 0; i < cart.cartSize; i++){
        totalCost += cart.cartItems[i].itemPrice * cart.cartItems[i].itemQuantity;
    }
    return totalCost;
}

void PrintInvoice(ShoppingCart cart){
    printf("%s's Shopping Cart - %s\n", cart.customerName, cart.currentDate);
    printf("Number of Items: %d\n\n", GetNumItemsInCart(cart));

    for(int i = 0; i < cart.cartSize; i++){
        PrintItemCost(cart.cartItems[i]);
    }
    printf("Total: $%d", GetCostOfCart(cart));
}

void PrintDescriptions(ShoppingCart cart){
    printf("%s's Shopping Cart - %s\n\n", cart.customerName, cart.currentDate);
    printf("Item Descriptions\n");
    for(int i = 0; i < cart.cartSize; i++){ //loops through array to get all cart items
        PrintItemDescription(cart.cartItems[i]);
    }
}