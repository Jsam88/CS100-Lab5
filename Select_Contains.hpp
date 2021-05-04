#ifndef __SELECT_CONTAINS_HPP__
#define __SELECT_CONTAINS_HPP__
#include "select.hpp"
#include "spreadsheet.hpp"
#include <string>
#include <iostream>
#include <sstream>

class Spreadsheet;
class Select;
class Select_Column;

class Select_Contains: public Select{

protected:
	std::string tarName;
    	const Spreadsheet* userSheet;
    	int column;
public:

        Select_Contains(const Spreadsheet* sheet, const std::string& col_name, const std::string& name){
   		column = sheet->get_column_by_name(col_name);
        	tarName = name;
   		userSheet = sheet;
        }

    virtual bool select(const Spreadsheet* sheet, int row)const{
    	std::string sheetStr = sheet->cell_data(row,column);
        if(sheetStr.find(tarName) != std::string::npos){
            return true;
        }
        else{
            return false;
        }
    }

};

#endif
