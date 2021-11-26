#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <utility>

#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

using namespace std;

class Parser
{
public:
    /**
     * @brief Macro of assert to print specific messages
     * @param expr a boolean that will be the expression to test
     * @param msg a string that will explain the error
     *
     * This method does the same job of assert, and print custom messages for each error
     */
    static void M_Assert(bool expr, const string& msg);

    /**
     * @brief Explode method to split strings
     * @param s the string to explode
     * @param delim the char used to separate the string
     *
     * This method explode a string by using the char delim, and stores the results in a vector of string
     */
    static vector<string> explode(const string& s, char delim);
};

#endif // PARSER_H_INCLUDED
