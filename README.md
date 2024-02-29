# Shopping Cart Application
This is a simple console-based shopping cart application written in C. It allows users to add and remove items from their shopping cart, view item descriptions, and print an invoice with the total cost.

## How to Use

### Prerequisites
- Ensure you have a C compiler installed on your system.
### Running the Program
1. Clone the repository to your local machine.
2. Compile the program using a C compiler.
3. Run the compiled executable file.
### Functionality
- Add Item to Cart: Allows the user to add items to their shopping cart. The user is prompted to enter the item name, description, price, and quantity.
- Remove Item from Cart: Enables the user to remove an item from their shopping cart by entering the item name.
- Output Item Descriptions: Prints a list of item descriptions in the user's shopping cart.
- Output Shopping Cart: Prints an invoice with the customer's name, today's date, the number of items in the cart, a list of items with their quantities and costs, and the total cost.
## File Structure

### Main File: main.c
Contains the main program logic.
Displays a menu to the user and handles user input.
### Header Files
- ItemToPurchase.h: Defines the structure for an item to be purchased.
- ShoppingCart.h: Defines the structure for a shopping cart and contains function prototypes for cart operations.
### Supporting Files
- ItemToPurchase.c: Implements functions related to items to be purchased.
- ShoppingCart.c: Implements functions related to shopping cart operations.
### Usage Example

    bash
    Copy code
    $ ./shopping_cart
    Enter Customer's Name:
    John Doe  
    Enter Today's Date:
    February 26, 2024
  
    Customer Name: John Doe
    Today's Date: February 26, 2024

  MENU
  a - Add item to cart
  r - Remove item from cart
  i - Output item descriptions
  o - Output shopping cart
  q - Quit

  Choose an option:
## Contributors

Bryce Kratzer
