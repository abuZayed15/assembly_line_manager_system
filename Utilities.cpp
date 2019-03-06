// Name: Abu Zayed Kazi Masudan Nabi
// Seneca Student ID: 109297176
// Seneca email: azkazi-masudan-nabi@myseneca.ca
// Date of completion: 
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#include "Utilities.h"

char Utilities::m_delimiter;

void Utilities::setFieldWidth(size_t setWd) {
	m_widthField = setWd;
}

size_t Utilities::getFieldWidth() const {

	return m_widthField;
}

const std::string Utilities::extractToken(const std::string & str, size_t & next_pos, bool & more) {
	//std::ifstream file;
		//file >>
		//getline(file, str, )
	more = true;
	std::string extToken = "";
	size_t size = 0; //, fieldW;
	if (str.find(extToken, next_pos) != std::string::npos) {
		size = str.find(m_delimiter, next_pos);
		extToken = str.substr(next_pos, size - next_pos); // finds the string starting from next_pos's position unti the width - position
		if (extToken.length() == 0) {
			throw std::string("Two delimiters found");
		}
	}

	if (extToken.length() == 0) {
		more = false;
	}
	m_widthField = extToken.length();

	
	return extToken;
}

void Utilities::setDelimiter(const char del) {
	m_delimiter = del;
}

const char Utilities::getDelimiter() const {
	return m_delimiter;
}