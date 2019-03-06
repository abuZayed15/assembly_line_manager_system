// Name: Abu Zayed Kazi Masudan Nabi
// Seneca Student ID: 109297176
// Seneca email: azkazi-masudan-nabi@myseneca.ca
// Date of completion: 
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.
#include "Item.h"

size_t Item::m_widthField = 0;
size_t Item::max;

Item::Item(const std::string& str) {
	Utilities util;
	bool result = false;
	size_t next_pos = 0;

	m_name = util.extractToken(str, next_pos, result);
	next_pos += util.getFieldWidth() + 1;
	if (util.getFieldWidth() > max) {
		max = util.getFieldWidth();
	}

	m_serialNumber = std::stoi(util.extractToken(str, next_pos, result));
	next_pos += util.getFieldWidth() + 1;

	m_quantity = std::stoi(util.extractToken(str, next_pos, result));
	next_pos += util.getFieldWidth() + 1;

	m_description = util.extractToken(str, next_pos, result);
	next_pos += util.getFieldWidth() + 1;
}

const std::string & Item::getName() {
	return m_name;
}

const unsigned int Item::getSerialNumber() {
	return m_serialNumber++;
	//return m_serialNumber;
}

const unsigned int Item::getQuantity() {
	return m_quantity;
}

void Item::updateQuantity() {
	if (getQuantity() > 0) {
		m_quantity--;
	}

	/*else {
		m_quantity;
	}*/
}

void Item::display(std::ostream & os, bool full) const {

	os << std::setw(max) << std::left << m_name << " [" << std::setw(m_widthField) << std::setw(6) << std::setfill('0') << std::right << m_serialNumber << "]" << std::setfill(' ') << std::left;


	if (!full) {
		os << std::endl;
	}

	else if (full) {
		os << " Quantity: " << std::setw(max) << std::left << m_quantity << " Description: " << m_description << std::endl;

	}
}