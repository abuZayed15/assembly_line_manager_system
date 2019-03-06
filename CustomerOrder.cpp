#include "CustomerOrder.h"

size_t CustomerOrder::m_widthField;

CustomerOrder::CustomerOrder(const std::string& str) :CustomerOrder() {
	Utilities u_obj;
	size_t next_pos = 0;
	bool result = true;

	m_name = u_obj.extractToken(str, next_pos, result);
	//as next_pos is going to be zero everytime, setting it to itself + the width field will get it just until the end of the word, and then + 1 for the pointer to start from the first letter of the next string
	next_pos += u_obj.getFieldWidth() + 1;
	m_product = u_obj.extractToken(str, next_pos, result);
	next_pos += u_obj.getFieldWidth() + 1;

	size_t temPos = 0;
	temPos = next_pos;

	m_cntItem = 0;
	std::string tempStr = "";
	//std::ifstream filename;
	while (next_pos < str.length()) {

		tempStr = u_obj.extractToken(str, next_pos, result);
		if (m_widthField < u_obj.getFieldWidth()) {

			m_widthField = u_obj.getFieldWidth();
		}
		next_pos += u_obj.getFieldWidth() + 1;
		m_cntItem++;
	}

	m_lstItem = new ItemInfo*[m_cntItem];

	for (size_t i = 0; i < m_cntItem; i++) {
		tempStr = u_obj.extractToken(str, temPos, result);
		temPos += u_obj.getFieldWidth() + 1;
		m_lstItem[i] = new ItemInfo(tempStr);
	}
}

CustomerOrder::CustomerOrder(CustomerOrder && nMove)noexcept {
	*this = std::move(nMove);
}

CustomerOrder::CustomerOrder(const CustomerOrder & nCopy) {
	/*if (this != &nCopy) {
		throw std::string("entering throw");
	}*/
}


CustomerOrder& CustomerOrder::operator=(CustomerOrder && nMove) {

	if (this != &nMove) {
		m_name = nMove.m_name;
		m_product = nMove.m_product;
		m_cntItem = nMove.m_cntItem;
		//m_widthField = nMove.m_widthField;
		m_lstItem = nMove.m_lstItem;

		nMove.m_name = "";
		nMove.m_product = "";
		nMove.m_cntItem = 0;
		nMove.m_lstItem = nullptr;
	}

	return *this;
}

bool CustomerOrder::getItemFillState(std::string str) const {
	//ItemInfo item;
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == str) {
			return m_lstItem[i]->m_fillState;
		}
	}
	return true;
}

bool CustomerOrder::getOrderFillState() const {

	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_fillState != true) {
			return false;
		}
	}
	return true;
}

void CustomerOrder::fillItem(Item & item, std::ostream & os) {
	if (m_lstItem != nullptr) {
		/*for (size_t i = 0; i < m_cntItem; i++)
		{
			if (!(m_lstItem[i]->m_itemName == item.getName()))
			{
				return;
			}
		}*/
		if (item.getQuantity() > 0)
		{
			for (size_t i = 0; i < m_cntItem; i++) {
				if (m_lstItem[i]->m_itemName == item.getName()) {
					item.updateQuantity();
					m_lstItem[i]->m_serialNumber = item.getSerialNumber();
					m_lstItem[i]->m_fillState = true;
					os << "Filled " << m_name << ", " << m_product << "["
						<< m_lstItem[i]->m_itemName << "]" << std::endl;
				}
			}
		}

		else
		{
			/*item.updateQuantity();
			item.getSerialNumber();
			m_lstItem[i]->m_fillState = true;*/
			os << "Unable to fill" << m_name << ", " << m_product << "["
				<< item.getName() << "]" << std::endl;
		}
	}
}

void CustomerOrder::display(std::ostream & os) const {

	os << m_name << " - " << m_product << std::endl;

	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_serialNumber <= 0) {
			os << "[" << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << std::setfill(' ') << "] "
				<< std::setw(16) << std::left << m_lstItem[i]->m_itemName << " - ";
		}	
		else {
			os << "[" << std::right << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << /*std::setfill(' ') <<*/ "] "
				<< std::left << std::setfill(' ') << std::setw(16) << m_lstItem[i]->m_itemName << " - ";
		}

		os << (m_lstItem[i]->m_fillState ? "FILLED" : "MISSING") << std::endl; 

		/*if (m_lstItem[i]->m_fillState == 1) {
			os << "FILLED" << std::endl;
		}
		else {
			os << "MISSING" << std::endl;
		}*/
	}
}

CustomerOrder::~CustomerOrder() {

	m_lstItem = nullptr;
	delete[] m_lstItem;
}
