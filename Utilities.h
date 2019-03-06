// Name: Abu Zayed Kazi Masudan Nabi
// Seneca Student ID: 109297176
// Seneca email: azkazi-masudan-nabi@myseneca.ca
// Date of completion: 
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#pragma once
#ifndef MS_UTILITIES_H
#define MS_UTILITIES_H
#include <iostream>
#include <fstream>
#include <string>


class Utilities {

	size_t m_widthField = 1; //length of token extracted
	static char m_delimiter; //separates the token from given string

public:
	Utilities() {};// : m_widthField{ 0 } {};
	~Utilities() {};
	void setFieldWidth(size_t);
	size_t getFieldWidth() const;
	const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	static void setDelimiter(const char);
	const char getDelimiter() const;

};


#endif // !MS_UTILITIES_H
