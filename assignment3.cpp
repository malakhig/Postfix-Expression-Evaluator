//Malakhi Griffin CS3350 10/15/23
#include<iostream>
#include<stack>
#include<string>

using namespace std;

//This function pushes the elements entered onto the stack
void PUSH(stack<string> &numbers) {
	cout << "Enter the postfix expression, 1 token per line. Enter '-1' to terminate." << endl;
	string num;
	while (num != "-1") {
		cin >> num;
		if (num != "-1") {
			numbers.push(num);

		}

	}
	
}
//Displays the stack in the correct order and also puts it into a string for evaluation 
void Display(stack<string>& numbers, string &equation) {
	stack<string> display;
	stack<string> save;
	
	while (!numbers.empty()) {
		display.push(numbers.top());
		numbers.pop();
	}
	while (!display.empty()) {
		cout << display.top() << " ";
		equation.append(display.top());
		save.push(display.top());
		display.pop();
	}
	while (!save.empty()) {
		numbers.push(save.top());
		save.pop();
	}
	
	cout << "=" << endl;
	
}
//Postfix Expression Evaluation of the string
void Solve(stack<string> &numbers, string &equation) {
	stack<int> integers;
	int result;
	int operand1 = 0;
	int operand2 = 0;
	int i;
	for (i = 0; i < equation.size(); ++i) {
		if (equation[i]>='0' && equation[i]<='9') {
			integers.push(equation[i] - '0');
		}
		else {
			operand2 = integers.top();
			integers.pop();
			operand1 = integers.top();
			integers.pop();
			if (equation[i] == '+') {
				result = (operand1 + operand2);
				integers.push((result));
			}
			else if (equation[i] == '-') {
				result = (operand1 - operand2);
				integers.push((result));
			}
			else if (equation[i] == '/') {
				result = (operand1 / operand2);
				if (operand2 == 0) {
					cerr << "Error: Division by zero." << endl;
					exit(1);
				}
				integers.push((result));
			}
			else if (equation[i] == '*') {
				result = (operand1 * operand2);
				integers.push((result));
			}
			
		}
	}
	 result = integers.top();
	cout  << result << endl;
	
}

int main() {
	stack<string> numbers;
	string equation;
	PUSH(numbers);
	Display(numbers, equation);	
	Solve(numbers, equation);

	return 0;
}