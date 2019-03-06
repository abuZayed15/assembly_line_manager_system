#include "Task.h"

Task::~Task() {
	m_pNextTask = nullptr;
	delete[] m_pNextTask;
}

//custom cons param uses 
Task::Task(const std::string & str) : Item::Item(str) {
	//Task object represents a single location	in the assembly line 
	//for filled items
	//Task obj cannot copy or move
	//Task obj;
	m_pNextTask = nullptr;
}

void Task::runProcess(std::ostream & os) {
	//int size = m_order.size(); 
	//checking to see if the orders are empty 
	if (!m_orders.empty()) {
		if (!(m_orders.back().getOrderFillState())) {
			//If the name of the item has not been filled
			while (!m_orders.back().getItemFillState(getName())) {
				m_orders.back().fillItem(*this, os);
			}
		}
	}
}

bool Task::moveTask() {
	CustomerOrder orders;
	if (m_orders.empty()) {
		return false;
	}

	else {
		//if the order has been filled
		if (m_orders.back().getItemFillState(this->getName()) == true) { //if the orders in the item has been filled, its true
			if (m_pNextTask != nullptr) { //if the pointer has data
				m_pNextTask->m_orders.push_front(std::move(m_orders.back())); //push data to the front of the array
				m_orders.pop_back();
			}
			return true;
		}
	}
	return false;
}

void Task::setNextTask(Task & nTask) {
	if (m_pNextTask == nullptr) {
		m_pNextTask = &nTask; //pointing to the next task reference
	}
}

bool Task::getCompleted(CustomerOrder & cOrder) {
	if (m_orders.empty()) {
		return false;
	}

	else {
		if (m_orders.back().getOrderFillState()) {
			//removes the last CustomerOrder from the queue and places it in the parameter
			///m_order.back() = { 0 };
			//moving the last order to the parameter 
			cOrder = std::move(m_orders.back());
			m_orders.pop_back();
			return true;
		}
	}
	return false;
}

void Task::validate(std::ostream & os) {
	//Item item;
	if (m_pNextTask != nullptr) {
		os << getName() << " --> " << m_pNextTask->getName() << std::endl;
	}

	else {
		os << getName() << " --> " << "END OF LINE" << std::endl;
	}
}

Task & Task::operator+=(CustomerOrder && qOrder) {
	m_orders.push_front(std::move(qOrder));
	// TODO: insert return statement here
	return *this;
}


