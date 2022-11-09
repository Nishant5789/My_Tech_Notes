// CPP Program to convert postfix to prefix
#include <bits/stdc++.h>
using namespace std;

// Pseudocode
// Function PostfixToPrefix(string postfix)
// 1. stacks
// 2. LOOP:i=0to postfix.length
// 2.1.IF postfix[i]is OPERAND->
//    2.1.1 s.push(postfix[i])
// 2.2.ELSE IF postfix[i]is OPERATOR->
//    2.2.1 op1=s.top()
//    2.2.2 s.pop()
//    2.2.3 op2=s.top()
//    2.2.4 s.pop()
//    2.2.5 exp=postfix[i]+op2+op1
//    2.2.6 s.push(exp)
//   END LOOP
//   RETURN s.top

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

// Convert postfix to Prefix expression
string postToPre(string post_exp)
{
	stack<string> s;

	// length of expression
	int length = post_exp.size();

	// reading from right to left
	for (int i = 0; i < length; i++) {

		// check if symbol is operator
		if (isOperator(post_exp[i])) {

			// pop two operands from stack
			string op1 = s.top();
			s.pop();
			string op2 = s.top();
			s.pop();

			// concat the operands and operator
			string temp = post_exp[i] + op2 + op1;

			// Push string temp back to stack
			s.push(temp);
		}
		else {
			// push the operand to the stack
			s.push(string(1, post_exp[i]));
		}
	}
	// string ans = "";
	// while (!s.empty()) {
	// 	ans += s.top();
	// 	s.pop();
	// }
	// return ans;
    return s.top();
}

// Driver Code
int main()
{
	string post_exp = "ABC/-AK/L-*";

	// Function call
	cout << "Prefix : " << postToPre(post_exp);
	return 0;
}
