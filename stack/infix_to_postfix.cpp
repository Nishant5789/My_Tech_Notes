
#include<bits/stdc++.h>
using namespace std;

// •If operand
//     print
// •If'('
//    push to stack
// •If')'
//    pop from stack and print until("is found
// •If operator
//    pop from stack and print until an
//    operator with less precedence is found

// ex----      (a-b/c) * (a/k-l)

// abc/-ak/l-*

// one this that remaiber that here we use stack of char because we add the char one by
//one no need to add bracket so we don't need it


int prec(char c)
{
    if(c=='^')
        return 3;
    else
        if(c=='/'||c=='*')
            return 2;
    else
        if(c=='+'||c=='-')
            return 1;
    else
        return -1;
}

string infixpostfix(string& s)
{
    stack<char> st;
    string res;
    
    for(int i=0; i<s.size(); i++)
    {
        // check the oprand is character or not
        // then it push into res
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
        {
            res+=s[i];
        }
        else
        // if sring occurs the '(' then simply push it
            if(s[i]=='(')
            {
                st.push(s[i]);
            }
        else
        // if string occurs the ')'
        // so we add the top element of stack until the '(' is apper
            if(s[i]==')')
            {
                while(st.size()!=0 && st.top()!='(')
                {
                    res+=st.top();
                    st.pop();
                }
                // after then we pop the '(' bracket
                if(st.size()!=0)
                {
                    st.pop();
                }
            }
        else
            {
            //most crucial part of the program 
            // first we check the precedence of oprator 
            // we add the oprator until
            // current oprator pre small than top oprator in stack
   
            //why????????

            //ex - (a-b/c)  postfix ans is  abc-/
            // here compare abc/- to  subprefix op1 op2   where op1= - and op2= /
            // so always op1<<=op2<<=op3.... so the expressionis right 
            // if op(top)<<op(curr) then we used to pop op1 from the stack
            //so if any low precedence op is acurr in string than we need another subprefix so we break while loop

            // i hope you got it!!!!!!
            
                while(st.size()!=0 && prec(st.top())>prec(s[i]))
                {
                    res+=st.top();
                    st.pop();
                }
                // after that we push the curr oprator
                st.push(s[i]);
            }
    }// after we check that that stack sempty or not
    // if it not then we add char to res;
      while(st.size()!=0)
        {
            res+=st.top();
            st.pop();
        }
    return res;
}
int main()
{
    string str="(a-b/c)*(a/k-l)";
    cout << infixpostfix(str) << endl;
// abc/-ak/l-*
    return 0;
}
