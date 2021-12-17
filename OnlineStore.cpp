#include "OnlineStore.h"
#include <string>
#include <iostream>

// Item class functions.
Item::Item(std::string name, long id, double price, int quantity)
	:	name{ validateItemName(name) }, 
		id{ validateNumber(id, "Id") },
		price{ validateNumber(price, "Price")},
		quantity{ validateNumber(quantity, "Quantity") } 
	{ }

Item::Item() : name{ "-placeholder-" }, id{ 0 }, price{ 0.0 }, quantity{ 0 } { }

std::string Item::validateItemName(std::string name) const {
	if (name == "" || name == "-placeholder-") {
		std::cout << "Item name is required and cannot be '-placeholder-' - setting name to 'Unknown item'.\n";
		return "Unknown item";
	}
	else {
		return name;
	}
}

template<typename T> T Item::validateNumber(T userNumber, std::string dataName) const {
	if (userNumber < 0) {
		std::cout << dataName << " cannot be negative. " << dataName << " will be 1.\n";
		return 1;
	}
	else {
		return userNumber;
	}
}

std::string Item::getItemName() const {
	return name;
}

long Item::getItemId() const {
	return id;
}

double Item::getItemPrice() const {
	return price;
}

int Item::getItemQuantity() const {
	return quantity;
}

void Item::decreaseQuantity(int itemsBought) {
	if (quantity <= itemsBought) {
		quantity = 0;
	}
	else {
		quantity -= itemsBought;
	}
}

std::ostream& operator<<(std::ostream& out, const Item& item) {
	out << "Item name: " << item.getItemName() << "\n" <<
		"ID: " << item.getItemId() << "\n" <<
		"Price: " << item.getItemPrice() << "\n" <<
		"Quantity: " << item.getItemQuantity() << "\n";

	return out;
}


// Store class functions.
Store::Store () { } 

void Store::addStoreItem(Item item) {
	for (int i = 0; i < 100; i++) {
		if (storeItemList[i].getItemName() == "-placeholder-") {
			storeItemList[i] = item;
			break;
		}
	}
}

std::string Store::getStoreContent() const {
	std::string storeContentString = "Store: \n";

	for (int i = 0; i < 100; i++) {
		if (storeItemList[i].getItemName() != "-placeholder-") {
			storeContentString += storeItemList[i].getItemName() + " x " + 
				std::to_string(storeItemList[i].getItemQuantity()) + "\n";
		}
	}

	return storeContentString;
}

Item Store::getListItemAtIndex(int index) const {
	return storeItemList[index];
}

void Store::processOrder(const Order& order) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 100; j++) {
			if (order.getOrderItemAtIndex(i).getItemId() == getListItemAtIndex(j).getItemId()) {
				storeItemList[j].decreaseQuantity(order.getOrderItemAtIndex(i).getItemQuantity());
				break;
			}
		}
	}
}

std::ostream& operator<<(std::ostream& out, const Store& store) {
	out << store.getStoreContent() << "\n";

	return out;
}


// Order class functions.
Order::Order() : orderTotalPrice{ 0.0 } { }

void Order::addOrderItem(Item item) {
	for (int i = 0; i < 10; i++) {
		if (orderItemList[i].getItemName() == "-placeholder-") {
			orderItemList[i] = item; // Add item to the order list.
			orderTotalPrice += item.getItemPrice() * item.getItemQuantity(); // Add item cost.
			break;
		}
	}
}

double Order::getOrderTotalPrice() const {
	return orderTotalPrice;
}

Item Order::getOrderItemAtIndex(int index) const {
	return orderItemList[index];
}