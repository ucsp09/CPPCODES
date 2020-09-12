#include <iostream>
#include <stack>
#include <queue>
using namespace std;
class StackQueue{
    private:queue<int> q1;
            queue<int> q2;
    public: void push(int x)
            {
                while(!empty())
                {
                    q2.push(q1.front());
                    q1.pop();
                }
                q1.push(x);
                while(!q2.empty())
                {
                    q1.push(q2.front());
                    q2.pop();
                }
            }
            void pop()
            {
                if(empty())
                    return ;
                q1.pop();
            }
            int top()
            {
                if(empty())
                    return -1;
                return q1.front();
            }
            inline bool empty()
            {
                return q1.empty();
            }
};
int main()
{
    StackQueue obj2;
    obj2.push(1);
    obj2.push(2);
    obj2.push(3);
    obj2.push(4);
    obj2.push(5);
    while(!obj2.empty())
    {
        cout<<obj2.top()<<" ";
        obj2.pop();
    }
    return 0;
}