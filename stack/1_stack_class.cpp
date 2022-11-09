#include<bits/stdc++.h>
using namespace std;

// class Stack
// {
//     public:
//     int Top;
//     int size;
//     int *arr;

//     Stack(int size)
//     {
//         this -> size = size;
//         arr = new int[size];
//         Top = -1;
//     }
//     void push(int x)
//     {
//         if(Top>=size-1)
//         {
//             cout << "stack is overflow" <<endl;
//             return;
//         }
//         else
//         {
//             Top++;
//             arr[Top]=x;
//         }
//     }
//     void pop()
//     {
//         if(Top>0)
//         {
//             Top--;
//         }
//         else{
//             cout << "stack is empty" << endl;
//         }
//     }
//     int top()
//     {
//         if(Top>0)
//         {
//             return arr[Top];
//         }
//         cout << "stack is empty" << endl;
//         return -1;
//     }

//     bool empty()
//     {
//         if(Top==-1)
//         {
//             return 1;
//         }
//         else
//         {
//             return 0;
//         }
//     }
// };

// -------------------------------------------------------for college use------------------------------------------

#define MAX 1000
class Stack
{
    int Top;
public:
    int arr[MAX]; //Maximum size of Stack

    Stack() { Top = -1; }
    void push(int x)
    {
            arr[++Top]=x;
    }
    void pop()
    {
         if(Top>0)
             Top--;
    }
    bool empty()
    {
        if(Top==-1)
            return 1;
        else
            return 0;
    }
    int top()
    {
        if(Top>-1) 
            return arr[Top];
        return 0;
    }
};




int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);

    Stack st;

    // st.push(22);
    // st.push(43);
    // st.push(44);
    // st.push(22);
    // st.push(43);
    // st.push(44);

    // cout << st.top() << endl;
    // st.pop();

    // cout << st.top() << endl;
    // st.pop();

    // cout << st.top() << endl;
    // st.pop();

    // cout << st.top() << endl;

    if(st.empty()) {
        cout << "Stack is Empty mere dost " << endl;
    }
    else{
        cout << "Stack is not Empty mere dost " << endl;
    }
    /*
    //creation of stack
    stack<int> s;
    //push operation
    s.push(2);
    s.push(3);
    //pop
    s.pop();
    cout << "Printing top element " << s.top() << endl;
    if(s.empty())
    {
        cout << "Stack is empty " << endl;
    }
    else{
        cout << "stack is not empty " << endl;
    }
    cout << "size of stack is " << s.size() << endl;
    */
   return 0;
}