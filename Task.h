// Name: Abu Zayed Kazi Masudan Nabi
// Seneca Student ID: 109297176
// Seneca email: azkazi-masudan-nabi@myseneca.ca
// Date of completion: 
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#ifndef MS_TASK_H
#define MS_TASK_H
#include <iostream>
#include <deque>
#include <string>
#include <iomanip>
#include "Item.h"
#include "CustomerOrder.h"

class Task : public Item
{
public:
	Task() : m_orders{ 0 }, m_pNextTask{ nullptr } {};
	~Task();
	Task(const std::string&);
	void runProcess(std::ostream&);
	bool moveTask(); //moves the last CustomerOrder in the queue to the next task in the assembly line 
	void setNextTask(Task&); //stores the provided Task object's reference to the m_pNextTask pointer
	bool getCompleted(CustomerOrder&); //removes the last CustomerOrder from the queue
	void validate(std::ostream&); //writes the name of the item 
	Task& operator+=(CustomerOrder&&); //moves the parameter into the front of the CustomerOrder queue


private:
	//m_order with a double ended queue with new CustomerOrder 
	//coming from one side and exiting out the other once filled
	std::deque<CustomerOrder> m_orders;
	Task * m_pNextTask; //pointer to the next task in the assembly line
};
	

#endif
