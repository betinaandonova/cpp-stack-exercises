#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

void addToStack(stack <int>& numbers, int arg1, int arg2);
void removeFromStack(stack <int>& numbers, int arg1);
void sumOfTheRemainingElements(stack <int>& numbers);

int main()
{
    stack <int> numbers;
    
    string buffer;
    getline(cin, buffer);

    istringstream istr(buffer);
    int number;
    while (istr >>number) 
    {
        numbers.push(number);
    }

        getline(cin, buffer);
        while (buffer != "end") {

            istringstream istr(buffer);
            string command;
            int arg1;

            istr >> command >> arg1;

            if (command == "add") {
                int arg2;
                istr >> arg2;
                addToStack(numbers, arg1, arg2);
            }
            else
                removeFromStack(numbers, arg1);
            
            getline(cin, buffer);
        }

        sumOfTheRemainingElements(numbers);
}

void addToStack(stack <int> &numbers, int arg1, int arg2){
    numbers.push(arg1);
    numbers.push(arg2);

  }

void removeFromStack(stack <int>& numbers, int arg1) {
    if (numbers.size()<arg1) {
        return;
    }
    while (arg1--)
        numbers.pop();
}

void sumOfTheRemainingElements(stack <int>& numbers) {
    int sum = 0;
    while (!numbers.empty()){
        sum += numbers.top();
        numbers.pop();
    }
    cout << sum;
}
