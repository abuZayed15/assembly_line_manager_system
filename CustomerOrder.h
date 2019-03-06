// Name: Abu Zayed Kazi Masudan Nabi
// Seneca Student ID: 109297176
// Seneca email: azkazi-masudan-nabi@myseneca.ca
// Date of completion: 
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#ifndef MS_CUSTOMERORDER_H
#define MS_CUSTOMERORDER_H
#include "Item.h"
#include "Utilities.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

struct ItemInfo {
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_fillState = false;

	ItemInfo(std::string src) : m_itemName(src) {};

};

class CustomerOrder {

public:
	CustomerOrder() : m_name{ "" }, m_product{ "" }, m_cntItem{ 0u }, m_lstItem{ nullptr } {};
	~CustomerOrder();
	CustomerOrder(const std::string&);
	CustomerOrder(CustomerOrder&& nMove)noexcept;//calls move assingment operator
	CustomerOrder(const CustomerOrder& nCopy);//throws error message
	CustomerOrder & operator=(const CustomerOrder& nCopy) = delete;//not implemented
	CustomerOrder & operator=(CustomerOrder&& nMove);//has move code
	bool getItemFillState(std::string) const;
	bool getOrderFillState() const;
	void fillItem(Item& item, std::ostream&);
	void display(std::ostream&) const;

private:
	std::string m_name; //name of customer
	std::string m_product; //name of the product assembling
	unsigned int m_cntItem; //count of the number of items for customer's order
	ItemInfo** m_lstItem; //dynamic allocation of array of pointers
	static size_t m_widthField; //maximum width of the field

};
#endif 