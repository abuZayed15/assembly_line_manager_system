#include "LineManager.h"

LineManager::LineManager( const std::string& str, std::vector<Task*>& task, std::vector<CustomerOrder>& cOrder) {
	Utilities utl;
	bool result;
	size_t next_pos , item_pos = 0;
	std::ifstream file(str);
	//std::vector<Task*> _vTask;
	m_cntCustomerOrder = 0;

	if (!file) {
		throw("Entering LineManager throw");
	}

	else {
		while (!file.eof()) {
			m_cntCustomerOrder = 0;
			result = true;
			next_pos = 0;
			std::string _line , _ext, _item;

			std::getline(file, _line);
			//cout << ext << endl;
			_ext = "";
			_ext = utl.extractToken(_line, next_pos, result);
			next_pos += utl.getFieldWidth() + 1;
			//std::cout << _ext << std::endl;

			_item = "";
			//std::string item;
			if (result) {
				_item = utl.extractToken(_line, next_pos, result);
				//std::cout << _item << std::endl;

				for (size_t i = 0; i < task.size(); i++) {
					if (task[i]->getName() == _ext) {
						item_pos = i;
						break;
					}
				}

				/*for (size_t i = 0; i < task.size(); i++) {
					if (task[i]->getName() == _item) {
						task[item_pos]->setNextTask
						item_pos = i;
						break;
					}
				}*/

				//if (_ext.size() != 0) {
				for (size_t i = 0; i < task.size(); i++) {
					if (task[i]->getName() == _item) {
						task[item_pos]->setNextTask(*task[i]);
						break;
					}
					
				}
				//}
			}

			/*else {
				task[item_pos]->setNextTask(*AssemblyLine[0]);
			}*/
			
			
		}

		//std::cout << item_pos << std::endl;
		for (size_t i = 0; i < task.size(); i++) {
			AssemblyLine.push_back(task[i]);
			//AssemblyLine[item_pos] = task[item_pos];
		}

		for (size_t i = 0; i < cOrder.size(); i++) {
			ToBeFilled.push_front(std::move(cOrder[i]));
			m_cntCustomerOrder++;
		}		

	}

}

bool LineManager::run(std::ostream& os) {
	CustomerOrder obj;
	if (!ToBeFilled.empty()) {
		//for (int i = 0; i < ToBeFilled.size(); i++) {
			*AssemblyLine[4] += std::move(ToBeFilled.back());
			ToBeFilled.pop_back();
		//}
	}
	//
	//trying to identifythe starting position of the Assemly line
	//*AssemblyLine.begin(std::move(ToBeFilled.back()));
	/*for (size_t i = 0; i < ToBeFilled.size(); i++) {
		*AssemblyLine[0] += std::move(ToBeFilled[i]);
		Completed.emplace_back();	
	}*/
	

	for (size_t i = 0; i < AssemblyLine.size(); i++) {
		AssemblyLine[i]->runProcess(os);	 
	}
	//
	for (size_t i = 0; i < AssemblyLine.size(); i++) {
		if (AssemblyLine[i]->moveTask() == true) {
			if (AssemblyLine[i]->getCompleted(obj) == true) {
				Completed.push_back(std::move(obj));
			}
		}
	}

	if (!ToBeFilled.size() && Completed.size() == m_cntCustomerOrder) { //
		return true;
	}
	
	//else {
	return false;
	//}
}

void LineManager::displayCompleted(std::ostream& os) const {
	for (size_t i = 0; i < Completed.size(); i++) {
		Completed[i].display(os); //all the orders filled and completed
	}
}

void LineManager::validateTasks() const {
	for (size_t i = 0; i < AssemblyLine.size(); i++) {
		AssemblyLine[i]->validate(std::cout);
	}
}
