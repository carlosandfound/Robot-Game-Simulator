#include <iostream>

#include "cart.h"

int main() {

  // Create an array of CartEntry's to put in the cart
  // Arbitrary values for price and quantity
  CartEntry inCart[5];
  for (int i=0; i<5; i++) {
    inCart[i].price = i*2;
    inCart[i].quantity = i;
  }

  // Place the CartEntry array in a CartContents
  CartContents purchases;
  purchases.items = inCart;
  purchases.itemCount = 5;

  // Make this an order with associated tax
  Order order1(purchases, .077);

  // Get total price of order
  std::cout << '$' << order1.OrderTotal() << std::endl;

  return 0;
}
