#include<iostream>
#include <stack>
using namespace std;
class MiniMaxStack{
    protected:  stack<int> st;
                int minimax;
    public:     virtual void push(int)=0;
                virtual void pop()=0;
                virtual int top()=0;
                virtual int getMin(){};
                virtual int getMiax(){};
                inline bool isEmpty()
                {
                    return st.empty();
                }
};
class MinStack : public MiniMaxStack{
    public:     void push(int x)
                {
                    if(isEmpty())
                    {
                        st.push(x);
                        minimax=x;
                    }
                    else
                    {
                        if(x<minimax)
                        {
                            st.push(2*x-minimax);
                            minimax=x;
                        }
                        else
                            st.push(x);
                    }
                }
                void pop()
                {
                    if(isEmpty())
                        return ;
                    if(st.top()<minimax)
                        minimax=2*minimax-st.top();
                    st.pop();
                }
                int top()
                {
                    if(isEmpty())
                        return -1;
                    if(st.top()<minimax)
                        return minimax;
                    return st.top();
                }
                int getMin()
                {
                    if(isEmpty())
                        return -1;
                    return minimax;
                }
};
class MaxStack : public MiniMaxStack{
    public:     void push(int x)
                {
                    if(isEmpty())
                    {
                        st.push(x);
                        minimax=x;
                    }
                    else
                    {
                        if(x>minimax)
                        {
                            st.push(2*x-minimax);
                            minimax=x;
                        }
                        else
                            st.push(x);
                    }
                }
                void pop()
                {
                    if(isEmpty())
                        return ;
                    if(st.top()>minimax)
                        minimax=2*minimax-st.top();
                    st.pop();
                }
                int top()
                {
                    if(isEmpty())
                        return -1;
                    if(st.top()>minimax)
                        return minimax;
                    return st.top();
                }
                int getMax()
                {
                    if(isEmpty())
                        return -1;
                    return minimax;
                }
};
int main()
{
    MinStack obj;
    obj.push(2);
    obj.push(3);
    obj.push(-1);
    obj.push(-2);
    obj.push(-3);
    while(!obj.isEmpty())
    {
        cout<<obj.getMin()<<" ";
        obj.pop();
    }
    return 0;
}