
#include<bits/stdc++.h>
using namespace std;


// first we reverse the string and then chage the '(' to ')' and ')' to '('
// after then we apply the infix to postfix . at the last we again reverse the string
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
    
    reverse(s.begin(),s.end());
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='(')
            s[i]=')';
        else
            if(s[i]==')')
            s[i]='(';
    }
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
          reverse(res.begin(),res.end());
    return res;
}
int main()
{
    string str=" (A - B/C) * (A/K-L)";
    cout << infixpostfix(str) << endl;
//  *-A/BC-/AKL
    return 0;
}
