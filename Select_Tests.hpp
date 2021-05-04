#ifndef __SELECT_TEST_HPP__
#define __SELECT_TEST_HPP__

#include "gtest/gtest.h"
#include "select.hpp"
#include "spreadsheet.hpp"
#include "Select_Contains.hpp"
#include "Select_Not.hpp"
#include "selectAnd.hpp"
#include "selectOr.hpp"
#include <string>
#include <sstream>

TEST(SpreadsheetTest, emptySheet) { //base case of empty sheet
    Spreadsheet sheet;
    std::stringstream ss;
    sheet.print_selection(ss);
    std::string test = ss.str();
    EXPECT_EQ(test, "");
}

TEST(SelectContainsTest, lowercaseTest) {
    Spreadsheet sheet;
    sheet.set_column_names({"Food"});
    sheet.add_row({"apple"});
    sheet.add_row({"apples"});
    sheet.add_row({"APPLE"});
    sheet.add_row({"snapple"});
    sheet.add_row({"app"});

    sheet.set_selection(new Select_Contains(&sheet, "Food", "apple"));

    std::stringstream ss;
    sheet.print_selection(ss);
    std::string test = ss.str();
    EXPECT_EQ(test, "apple \napples \nsnapple \n");
}

TEST(SelectContainsTest, uppercaseTest) {
    Spreadsheet sheet;
    sheet.set_column_names({"Food"});
    sheet.add_row({"apple"});
    sheet.add_row({"apples"});
    sheet.add_row({"APPLE"});
    sheet.add_row({"snapple"});
    sheet.add_row({"app"});

    sheet.set_selection(new Select_Contains(&sheet, "Food", "APPLE"));

    std::stringstream ss;
    sheet.print_selection(ss);
    std::string test = ss.str();
    EXPECT_EQ(test, "APPLE \n");
}

TEST(SelectContainsTest, ContainsTest1) {
    Spreadsheet sheet;
    sheet.set_column_names({"Food"});
    sheet.add_row({"apple"});
    sheet.add_row({"apples"});
    sheet.add_row({"APPLE"});
    sheet.add_row({"snapple"});
    sheet.add_row({"app"});
    sheet.add_row({"mango"});

    sheet.set_selection(new Select_Contains(&sheet, "Food", "mango"));

    std::stringstream ss;
    sheet.print_selection(ss);
    std::string test = ss.str();
    EXPECT_EQ(test, "mango \n");
}

TEST(SelectContainsTest, ContainsTest2) {
    Spreadsheet sheet;
    sheet.set_column_names({"Food"});
    sheet.add_row({"apple"});
    sheet.add_row({"apples"});
    sheet.add_row({"APPLE"});
    sheet.add_row({"snapple"});
    sheet.add_row({"app"});
    sheet.add_row({"mango"});

    sheet.set_selection(new Select_Contains(&sheet, "Food", "yay"));

    std::stringstream ss;
    sheet.print_selection(ss);
    std::string test = ss.str();
    EXPECT_EQ(test, "");
}


TEST(SelectNotTest, NotTest1) {
    Spreadsheet sheet;
    sheet.set_column_names({"Food"});
    sheet.add_row({"apple"});
    sheet.add_row({"apples"});
    sheet.add_row({"APPLE"});
    sheet.add_row({"banana"});
    sheet.add_row({"bananas"});

    sheet.set_selection(
	new Select_Not(	
		new Select_Contains(&sheet, "Food", "banana")));

    std::stringstream ss;
    sheet.print_selection(ss);
    std::string test = ss.str();
    EXPECT_EQ(test, "apple \napples \nAPPLE \n");
}

TEST(SelectNotTest, NotTest2) {
    Spreadsheet sheet;
    sheet.set_column_names({"Food"});
    sheet.add_row({"apple"});
    sheet.add_row({"apples"});
    sheet.add_row({"APPLE"});
    sheet.add_row({"banana"});
    sheet.add_row({"bananas"});

    sheet.set_selection(
	new Select_And(
        	new Select_Contains(&sheet, "Food", "banana"),
		new Select_Not(
               		new Select_Contains(&sheet, "Food", "bananas"))));

    std::stringstream ss;
    sheet.print_selection(ss);
    std::string test = ss.str();
    EXPECT_EQ(test, "banana \n");
}

TEST(SelectNotTest, NotTest3) {
    Spreadsheet sheet;
    sheet.set_column_names({"Food"});
    sheet.add_row({"apple"});
    sheet.add_row({"apples"});
    sheet.add_row({"APPLE"});
    sheet.add_row({"banana"});
    sheet.add_row({"bananas"});

    sheet.set_selection(
        new Select_And(
                new Select_Contains(&sheet, "Food", ""),
                new Select_Not(
                        new Select_Contains(&sheet, "Food", "s"))));

    std::stringstream ss;
    sheet.print_selection(ss);
    std::string test = ss.str();
    EXPECT_EQ(test, "apple \nAPPLE \nbanana \n");
}


TEST(SelectAndTest, AndTest1) { //we want to get nothing
    Spreadsheet sheet;
    sheet.set_column_names({"Food"});
    sheet.add_row({"apple"});
    sheet.add_row({"apples"});
    sheet.add_row({"APPLE"});
    sheet.add_row({"banana"});
    sheet.add_row({"bananas"});

    sheet.set_selection(
        new Select_And(
                new Select_Contains(&sheet, "Food", "banana"),
                new Select_Contains(&sheet, "Food", "APPLE")));

    std::stringstream ss;
    sheet.print_selection(ss);
    std::string test = ss.str();
    EXPECT_EQ(test, "");
}

TEST(SelectAndTest, AndTest2) {
    Spreadsheet sheet;
    sheet.set_column_names({"Food"});
    sheet.add_row({"apple"});
    sheet.add_row({"apples"});
    sheet.add_row({"APPLE"});
    sheet.add_row({"banana"});
    sheet.add_row({"bananas"});

    sheet.set_selection(
        new Select_And(
                new Select_Contains(&sheet, "Food", "banana"),
                new Select_Contains(&sheet, "Food", "banana")));

    std::stringstream ss;
    sheet.print_selection(ss);
    std::string test = ss.str();
    EXPECT_EQ(test, "banana \nbananas \n");
}

TEST(SelectAndTest, AndTest3) {
    Spreadsheet sheet;
    sheet.set_column_names({"Food"});
    sheet.add_row({"apple"});
    sheet.add_row({"apples"});
    sheet.add_row({"banana"});
    sheet.add_row({"bananas"});

    sheet.set_selection(
        new Select_And(
                new Select_Contains(&sheet, "Food", "banana"),
		new Select_Not(
                	new Select_Contains(&sheet, "Food", "apple"))));

    std::stringstream ss;
    sheet.print_selection(ss);
    std::string test = ss.str();
    EXPECT_EQ(test, "banana \nbananas \n");
}


TEST(SelectOrTest, OrTest1) {
    Spreadsheet sheet;
    sheet.set_column_names({"Food"});
    sheet.add_row({"apple"});
    sheet.add_row({"apples"});
    sheet.add_row({"APPLE"});
    sheet.add_row({"banana"});
    sheet.add_row({"bananas"});

    sheet.set_selection(
        new Select_Or(
                new Select_Contains(&sheet, "Food", "bananas"),
                new Select_Contains(&sheet, "Food", "APPLE")));

    std::stringstream ss;
    sheet.print_selection(ss);
    std::string test = ss.str();
    EXPECT_EQ(test, "APPLE \nbananas \n");
}

TEST(SelectOrTest, OrTest2) {
    Spreadsheet sheet;
    sheet.set_column_names({"Food"});
    sheet.add_row({"apple"});
    sheet.add_row({"apples"});
    sheet.add_row({"APPLE"});
    sheet.add_row({"banana"});
    sheet.add_row({"bananas"});

    sheet.set_selection(
        new Select_Or(
                new Select_Contains(&sheet, "Food", "banana"),
		new Select_Or(
                	new Select_Contains(&sheet, "Food", "APPLE"),
			new Select_Contains(&sheet, "Food", "apple"))));

    std::stringstream ss;
    sheet.print_selection(ss);
    std::string test = ss.str();
    EXPECT_EQ(test, "apple \napples \nAPPLE \nbanana \nbananas \n");
}

TEST(SelectOrTest, OrTest3) {
    Spreadsheet sheet;
    sheet.set_column_names({"Food"});
    sheet.add_row({"apple"});
    sheet.add_row({"apples"});
    sheet.add_row({"APPLE"});
    sheet.add_row({"banana"});
    sheet.add_row({"bananas"});

    sheet.set_selection(
        new Select_Or(
                new Select_Contains(&sheet, "Food", "beb"),
                new Select_Contains(&sheet, "Food", "")));

    std::stringstream ss;
    sheet.print_selection(ss);
    std::string test = ss.str();
    EXPECT_EQ(test, "apple \napples \nAPPLE \nbanana \nbananas \n");
}


#endif
