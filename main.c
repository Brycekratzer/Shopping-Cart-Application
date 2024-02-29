#include<stdio.h>
#include<string.h>

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

/**
 * The following prints out a menu for the user and then prompts them to 
 * Input a certain value
 * 
 * @param userChoice - is the users choice variable
*/
void PrintMenu(char* userChoice) {

   printf("\n\nMENU\n");
   printf("a - Add item to cart\nr - Remove item from cart");
   printf("\ni - Output item descriptions\no - Output shopping cart\nq - Quit\n\n");
   printf("Choose an option:\n");
   scanf("%*[\n]"); //clears buffer from previous input
   scanf("%c", userChoice); 
}

/**
 * The following adds an item(s) to user's cart
 * 
 * @param userCart - user's cart
*/
void AddItemToCart(ShoppingCart *userCart) {
    ItemToPurchase userItem;
    printf("ADD ITEM TO CART\n");

    printf("Enter the item name:\n");

    scanf("%*[\n]");
    fgets(userItem.itemName, MAX_STRING_LENGTH, stdin);
    userItem.itemName[strlen(userItem.itemName) - 1] = '\0';//removes new line

    printf("Enter the item description:\n");
    fgets(userItem.itemDescription, MAX_DESCRIPTION_LENGTH, stdin);
    userItem.itemDescription[strlen(userItem.itemDescription) - 1] = '\0';

    printf("Enter the item price:\n");
    scanf("%d", &userItem.itemPrice);

    printf("Enter the item quantity:\n");
    scanf("%d", &userItem.itemQuantity);

    *userCart = AddItem(userItem, *userCart); //updates cart with item
}

/**
 * The following function removes an item from 
 * the users cart
 * 
 * @param userCart - the user's cart where item will be removed
*/
void RemoveItemFromCart(ShoppingCart *userCart){
    char itemToRemove[MAX_STRING_LENGTH];
    if(userCart->cartSize != 0) {
        printf("Enter name of item to remove\n");
        scanf("%*[\n]");//clears buffer from '\n'
        fgets(itemToRemove, MAX_STRING_LENGTH, stdin);
        itemToRemove[strlen(itemToRemove) - 1] = '\0';

        *userCart = RemoveItem(itemToRemove, *userCart);
    } else {
        printf("Error: There are no items to remove");
    }
}

int main(void) {
    ShoppingCart userCart;
    userCart.cartSize = 0;
    char userChoice = 'd';

    printf("Enter Customer's Name:\n");
    fgets(userCart.customerName, MAX_CUSTOMER_NAME_SIZE, stdin);
    userCart.customerName[strlen(userCart.customerName) - 1] = '\0';

    printf("Enter Today's Date:\n");
    fgets(userCart.currentDate, MAX_CURRENT_DATE_SIZE, stdin);
    userCart.currentDate[strlen(userCart.currentDate) - 1] = '\0';

    printf("\nCustomer Name: %s\n", userCart.customerName);
    printf("Today's Date: %s\n", userCart.currentDate);

    while(userChoice != 'q') { //if user enter 'q' loop ends
      PrintMenu(&userChoice);
      if(userChoice == 'a') {
        printf("\n");
        AddItemToCart(&userCart);
      } else if(userChoice == 'r'){
        printf("\n");
        RemoveItemFromCart(&userCart);
      } else if(userChoice == 'i'){
        printf("\n");
        PrintDescriptions(userCart);
      } else if(userChoice == 'o'){
        printf("\n");
        PrintInvoice(userCart);
      } else if(userChoice != 'q'){
        printf("\n");
        printf("Error: Unknown option selected");
      }
   }
   return 0;
}
