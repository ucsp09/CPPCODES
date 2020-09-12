#include <iostream>
#include <stack>
#include <queue>
using namespace std;
class QueueStack{
    private :   stack<int> s1;
                stack<int> s2;
    public: void enqueue(int x)
            {
                while(!empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
                s1.push(x);
                while(!s2.empty())
                {
                    s1.push(s2.top());
                    s2.pop();
                }
            }
            void dequeue()
            {
                if(empty())
                    return ;
                s1.pop();
            }
            int front()
            {
                if(empty())
                    return -1;
                return s1.top();
            }
            inline bool empty()
            {
                return s1.empty();
            }
};
int main()
{
    QueueStack obj1;
    obj1.enqueue(1);
    obj1.enqueue(2);
    obj1.enqueue(3);
    obj1.enqueue(4);
    obj1.enqueue(5);
    while(!obj1.empty())
    {
        cout<<obj1.front()<<" ";
        obj1.dequeue();
    }
    return 0;
}