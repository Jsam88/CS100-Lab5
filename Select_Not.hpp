#ifndef __SELECT_NOT_HPP__
#define __SELECT_NOT_HPP__

#include "select.hpp"
#include "spreadsheet.hpp"
#include <iostream>

class Select_Not: public Select{

protected:
	Select *contains;
public:

	Select_Not(Select* select_contains) {
		contains = select_contains;
	}

	bool select(const Spreadsheet* sheet, int row) const{
		if (contains -> select(sheet,row) == true) {
			return false;
		}
		else {
			return true;
		}
   	}
	
	virtual ~Select_Not() {
		delete contains;
	}
};


#endif
