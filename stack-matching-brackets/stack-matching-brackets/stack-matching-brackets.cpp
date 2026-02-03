#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string line;
    getline(cin, line);

	stack<size_t> openingBrackets;

    for (size_t idx = 0; idx < line.length(); idx++) 
    {
        char curChar = line[idx];

        switch (curChar)
        {
        case '(': openingBrackets.push(idx); break;
        case ')': 
            {
                size_t matchingBracketPosition = openingBrackets.top();
                openingBrackets.pop();
                string expression = line.substr(matchingBracketPosition, idx - matchingBracketPosition + 1);
				cout << expression << endl;
                break;
            }
        }
    }
}