#ifndef __SELECT_TEST_HPP__
#define __SELECT_TEST_HPP__

#include "gtest/gtest.h"
#include "select.hpp"
#include "spreadsheet.hpp"
#include <string>
#include <sstream>

TEST(SpreadsheetTest, emptySheet) { //base case of empty sheet
    Spreadsheet sheet;
    std::striingstream ss;
    sheet.pring_selection(ss);
    std::string test = ss.str();
    EXPECT_EQ(test, "");
}

TEST(SelectContainsTest, lowercaseTest) {
    Spreadsheet sheet;
    sheet.add_row({"apple"});
    sheet.add_row({"apples"});
    sheet.add_row({"APPLE"});
    sheet.add_row({"snapple"});
    sheet.add_row({"app"});

    sheet.set_selection(new Select_Contains(&sheet, "Food", "apple"));

    std::stringstream ss;
    sheet.print_selection(ss);
    std::string test = ss.str();
    EXPECT_EQ(test, "apple \n apples \n Snapple \n")
}

#endif