// Name: Abu Zayed Kazi Masudan Nabi
// Seneca Student ID: 109297176
// Seneca email: azkazi-masudan-nabi@myseneca.ca
// Date of completion: 
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#ifndef MS_ITEM_H
#define MS_ITEM_H
#include "Utilities.h"
#include <iostream>
#include <string>
#include <iomanip>

class Item {

	std::string m_name;
	std::string m_description;
	long m_serialNumber;
	int m_quantity;
	static size_t m_widthField;
	static size_t max;

public:
	Item() {};
	~Item() {};
	Item(const std::string&);
	const std::string& getName();
	const unsigned int getSerialNumber();
	const unsigned int getQuantity();
	void updateQuantity();
	void display(std::ostream& os, bool full) const;

};

#endif // !MS_ITEM_H
