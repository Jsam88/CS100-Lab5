#ifndef __SELECT_NOT_HPP__
#define __SELECT_NOT_HPP__

#include "select.hpp"
#include "spreadsheet.hpp"
#include <iostream>

class Select_Not: public Select{

protected:
	Select *location1;
	Select *location2;
public:

	Select_Not(Select* l1, Select* l2) {
		location1 = l1;
		location2 = l2;
	}

	~Select_Not() {
		delete location1;
		delete location2;
	}

	bool select(const Spreadsheet* sheet, int row) const{
		if (location1->select(sheet,row) == true && location2->select(sheet, row) == true) {
			return false;
		}
		else {
			return true;
		}
   	}
};


#endif
