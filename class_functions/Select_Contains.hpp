#ifndef __SELECT_CONTAINS_HPP__
#define __SELECT_CONTAINS_HPP__

#include "select.hpp"
#include "spreadsheat.hpp"
#include <iostream>

class Select
class Select_Column
class Spreadsheet

class Select_contains: public select {

	virtual bool select(const Spreadsheet* sheet, string label , string user_input); 
	int column_number = sheet.Select_Column(label);
		for(int i = 0, i < row.size(), i++){
			if(sheet.cell_data(i, column_number)== user_input){
				return true;
			}	 
		}
		return 1;
#endif
