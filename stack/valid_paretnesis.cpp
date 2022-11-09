#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

class Stack
{
    int Top;
public:
    string arr[MAX]; //Maximum size of Stack

    Stack() { Top = -1; }
    void push(string x)
    {
            arr[++Top]=x;
    }
    void pop()
    {
         if(Top>=0)
             Top--;
    }
    bool empty()
    {
        if(Top==-1)
            return 1;
        else
            return 0;
    }
    string top()
    {
        if(Top>-1) 
            return arr[Top];
        return 0;
    }
};



int main() {
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
        Stack s;
        int count1=0, flag=0, maxi=INT_MIN;
        for(int i=0; i<str.size(); i++)
        {
            if(str[i]=='<')
            {
                s.push("<");
            }
            else
                if(flag==0)
                {
                    cout << 0 << endl;
                    break;
                }
            else
            {
                if(!s.empty())
                {
                    if(s.top()=="<")
                    {
                        count1+=2;
                    }
                    s.pop();
                    maxi=max(maxi,count1);
                }
                else
                {
                    maxi=max(maxi,count1);
                    count1=0;
                }
            }
        }
        if(flag!=0)
        cout << maxi << endl;
    }
	return 0;
}
