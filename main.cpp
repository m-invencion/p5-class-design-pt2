#include "WebURL.h"
#include "ImageMetadata.h"
#include "OnlineStore.h"
#include <iostream>

int main() {
	const WebURL site1{ "https://highline.edu/about" };

	std::cout << site1 << "\n";


	const ImageMetadata image1{
		"Cobble bridge",
		"JPEG",
		"02/29/2012",
		5.409,
		"",
		1200,
		840,
		500,
		6000,
		1300,
		false
	};

	std::cout << image1 << "\n";


	const Item item1{ "First item", 1001, 10.00, 20 };
	const Item item2{ "Second item", 1002, 15.20, 20 };
	const Item buyItem1{ "First item", 1001, 10.00, 3 };
	const Item buyItem2{ "Second item", 1002, 15.20, 7 };

	Store store1{};
	store1.addStoreItem(item1);
	store1.addStoreItem(item2);

	std::cout << item1 << "\n";
	std::cout << item2 << "\n";
	std::cout << store1;

	Order order1{};
	order1.addOrderItem(buyItem1);
	order1.addOrderItem(buyItem2);
	std::cout << "Total cost of order: $" << order1.getOrderTotalPrice() << "\n\n";

	store1.processOrder(order1);

	std::cout << store1;
}