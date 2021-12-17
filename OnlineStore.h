#pragma once
#include <string>
#include <ostream>

class Item; class Store; class Order;

// First class represents an item.
class Item {
public:
	Item(std::string name, long id, double price, int quantity);
	Item(); // Default constructor to make placeholder items in storeItemList.

	// Functions to validate user input.
	std::string validateItemName(std::string name) const;
	template<typename T> T validateNumber(T userNumber, std::string dataName) const;

	// Getter functions.
	std::string getItemName() const;
	long getItemId() const;
	double getItemPrice() const;
	int getItemQuantity() const;

	// Decrease quantity when items are ordered.
	void decreaseQuantity(int itemsBought);

private:
	std::string name;
	long id;
	double price;
	int quantity;
};

// Non-member output stream overload to print item information.
std::ostream& operator<<(std::ostream& out, const Item& item);


// Second class represents a store.
class Store {
public:
	Store();

	// Add item to store list.
	void addStoreItem(Item item);

	// Getter functions.
	std::string getStoreContent() const;
	Item getListItemAtIndex(int index) const;

	// Member function which removes items from store according to an order.
	void processOrder(const Order& order);
	
private:
	Item storeItemList[100]; // Item information initialized with default Item constructor.
};

// Non-member output stream overload to print store content. (Replaces printStoreContent() function.)
std::ostream& operator<<(std::ostream& out, const Store& store);


// Third class represents an order.
class Order {
public:
	Order();

	// Add an item to the order list.
	void addOrderItem(Item item);

	// Getter functions.
	double getOrderTotalPrice() const;
	Item getOrderItemAtIndex(int index) const;

private:
	Item orderItemList[10]; // Item information initialized with default Item constructor.
	double orderTotalPrice;
};
