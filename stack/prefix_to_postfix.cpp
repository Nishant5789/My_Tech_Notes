// CPP Program to convert prefix to postfix
#include <iostream>
#include <stack>
using namespace std;



// Pseudocode
// Function PrefixToPostfix(string prefix)
// 1. stacks
// 2. LOOP:i=prefix.length-1to0
//   2.1 IF prefix[i]is OPERAND->
//     2.1.1 s.push(prefix[i])
//   2.2 ELSE IF prefix[i]is OPERATOR->
//     2.2.1 op1=s.top()
//     2.2.2 s.pop()
//     2.2.3 op2=s.top()
//     2.2.4 s.pop()
//     2.2.5 exp=op1+op2+prefix[i]
//     2.2.6 s.push(exp)
// END LOOP
// 3. RETURN s.top

// ex- (a+(b*c))
// postfix = abc*+  prefix = +a*bc  

// to convert prefix to postfix then need two oprand and then push the oprator after the oprand

// function to check if character is operator or not
bool isOperator(char x)
{
	switch (x) {
	case '+':
	case '-':
	case '/':
	case '*':
		return true;
	}
	return false;
}

// Convert prefix to Postfix expression
string preToPost(string pre_exp)
{

	stack<string> s;
	// length of expression
	int length = pre_exp.size();

	// reading from right to left
	for (int i = length - 1; i >= 0; i--)
	{
		// check if symbol is operator
		if (isOperator(pre_exp[i]))
		{
			// pop two operands from stack
			string op1 = s.top();
			s.pop();
			string op2 = s.top();
			s.pop();

			// concat the operands and operator
			string temp = op1 + op2 + pre_exp[i];

			// Push string temp back to stack
			s.push(temp);
		}

		// if symbol is an operand
		else {

			// push the operand to the stack
			s.push(string(1, pre_exp[i]));
		}
	}

	// stack contains only the Postfix expression
	return s.top();
}
// Driver Code
int main()
{
	string pre_exp = "*-A/BC-/AKL";
	cout << "Postfix : " << preToPost(pre_exp);
	return 0;
}
// *-A/BC-/AKL