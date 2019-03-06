// Name: Abu Zayed Kazi Masudan Nabi
// Seneca Student ID: 109297176
// Seneca email: azkazi-masudan-nabi@myseneca.ca
// Date of completion: 
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#ifndef MS_LINEMANAGER_H
#define MS_LINEMANAGER_H
#include <vector>
#include <fstream>
#include "Task.h"


class LineManager {

public:
	LineManager() : AssemblyLine{ nullptr }, ToBeFilled{ 0 }, m_cntCustomerOrder{ 0 } {};
	~LineManager() {};
	LineManager(const std::string&, std::vector<Task*>&, std::vector<CustomerOrder>&); //reading the AssemblyLine.dat
	bool run(std::ostream&);
	void displayCompleted(std::ostream&) const;
	void validateTasks() const;


private:
	std::vector<Task*> AssemblyLine;
	std::deque<CustomerOrder> ToBeFilled;
	std::deque<CustomerOrder> Completed;
	unsigned int m_cntCustomerOrder;

};

#endif