// A class for a single element in a cart
class CartEntry {
public:
  float price;
  int quantity;
  CartEntry( float p=0, int q=0);
};

// A collection of elements in a cart
// CartContents "has a" CartEntry - using composition
class CartContents{
public:
  int itemCount; // number of elements in cart
  CartEntry* items;
};

// An order is the combination of a cart and tax
// different states apply different salesTax rates.
class Order {
private:
  CartContents cart;
  float salesTax;
public:
  Order(CartContents cart, float salesTax);
  float OrderTotal();
};
