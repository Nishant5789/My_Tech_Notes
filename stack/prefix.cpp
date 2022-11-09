#include<bits/stdc++.h>
using namespace std;

    // for leetcode  https://leetcode.com/problems/evaluate-reverse-polish-notation/

int main()
    {
        string token;
        // token="-+8/632";
        token="-+7*45+20";
        stack<int> st;
        for(int i=token.size()-1;i>=0; i--)
        {
            if('0'<= token[i]  && token[i] <='9')
            {
                st.push(token[i]-'0');
            }
            else
            {
                int op1=st.top();
                st.pop();
                int op2=st.top();
                st.pop();
                
                if(token[i]=='+')
                    st.push(op1+op2);
                else
                    if(token[i]=='-')
                        st.push(op1-op2);
                else
                    if(token[i]=='*')
                        st.push(op1*op2);
                else
                    if(token[i]=='/')
                        st.push(op1/op2);
                else
                    if(token[i]=='^')
                        st.push(pow(op1,op2));
            }
        }
        cout << st.top() << endl;
        return 0;
    }

