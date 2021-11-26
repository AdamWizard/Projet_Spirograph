#include "../headers/Parser.h"

using namespace std;

void Parser::M_Assert(bool expr, const string& msg)
{
    if (!expr)
    {
        cout << "Assert failed:\t" << msg << endl;
        abort();
    }
}

vector<string> Parser::explode(const string& s, char delim)
{
    vector<string> result;
    std::istringstream iss(s);

    for (string token; getline(iss, token, delim); )
    {
        result.push_back(move(token));
    }

    return result;
}
