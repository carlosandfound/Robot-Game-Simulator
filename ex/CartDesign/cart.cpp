#include "cart.h"

CartEntry::CartEntry( float p, int q) {
  price = p;
  quantity = q;
}

Order::Order( CartContents c, float s ) {
  cart = c;
  salesTax = s;
}

float Order::OrderTotal() {
  float cartTotal = 0;
  for (int i=0; i < cart.itemCount; i++) {
    cartTotal += cart.items[i].price * cart.items[i].quantity;
  }
  cartTotal += cartTotal * salesTax;
  return cartTotal;
}
