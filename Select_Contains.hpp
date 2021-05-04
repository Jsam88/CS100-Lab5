#ifndef __SELECT_CONTAINS_HPP__
#define __SELECT_CONTAINS_HPP__

#include "select.hpp"
#include "spreadsheet.hpp"
#include <string>
#include <iostream>
#include <sstream>

class Select;
class Select_Column;
class Spreadsheet;

class Select_Contains : public Select_Column {
	protected:
        	std::string substring;

	public:

        Select_Contains( const Spreadsheet* sheet, const std::string& column_name, const std::string& user_input) : Select_Column(sheet, column_name) {
                substring = user_input;
        }

        virtual bool select(const std::string& string) const {
                if(string.find(substring) != std::string::npos)
                {
                        return true;
                }

                return false;
        }
};
#endif
