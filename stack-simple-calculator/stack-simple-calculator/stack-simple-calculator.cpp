#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

void operationsType(stack <int>& numbers, stack <char>& operations, char operation, int number);

int main()
{
    int number;
    int sum=0;
    char operation;

    stack<int> numbers;
    stack<char> operations;

    string buffer;
    getline(cin, buffer);
    istringstream istr(buffer);

    while (istr >> number) {
        numbers.push(number);

        if (istr >> operation) {
            operations.push(operation);
        }
        else break;
    }

	operationsType(numbers, operations, operation, number);

    return 0;
}

void operationsType(stack <int> &numbers,stack <char> &operations, char operation, int number) {
    
    int sum = 0;
    while (operations.size())
    {

        int number = numbers.top();
        numbers.pop();
        char operation = operations.top();
        operations.pop();
        switch (operation) {
        case '+':sum += number; break;
        case '-':sum -= number; break;
        }

    }

    if (numbers.size())
        sum += numbers.top();
    cout << sum << endl;
}
