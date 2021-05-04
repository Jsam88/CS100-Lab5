#ifndef __SELECTAND_HPP__
#define __SELECTAND_HPP__ 

#include "select.hpp"
#include "spreadsheet.hpp"
#include <iostream>

class Select_And: public Select{

protected:
	Select *location1;
	Select *location2;
public:

	Select_And(Select* l1, Select* l2) {
		location1 = l1;
		location2 = l2;
	}

	~Select_And() {
		delete location1;
		delete location2;
	}

	virtual bool select(const Spreadsheet* sheet, int row) const{
		if (location1->select(sheet,row) == true && location2->select(sheet, row) == true) {
			return true;
		}
		else {
			return false;
		}
   	}
};


#endif

