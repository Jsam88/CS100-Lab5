#ifndef __SELECTOR_HPP__
#define __SELECTOR_HPP__ 

#include "select.hpp"
#include "spreadsheet.hpp"
#include <iostream>

class Select_Or: public Select{

protected:
        Select *location1;
        Select *location2;
public:

        Select_Or(Select* l1, Select* l2) {
                location1 = l1;
                location2 = l2;
        }

        ~Select_Or() {
                delete location1;
                delete location2;
        }

        bool select(const Spreadsheet* sheet, int row) const{
                if (location1->select(sheet,row) == true || location2->select(sheet, row) == true) {
                        return true;
                }
                else {
                        return false;
                }
        }
};


#endif


