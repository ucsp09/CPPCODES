#include <iostream>
using namespace std;


class Node{
    private:Node *next;
            int x;
    friend class StackList;
};
class Stack{
    protected:const static int MAXN=10;
    public:virtual void push(int)=0;
            virtual void pop()=0;
            virtual int top()=0;
            virtual bool empty()=0;
};

class StackArray:public Stack{
    private:int arr[MAXN];
            int length;
    public: StackArray():length(0)
            {
                for(int i=0;i<MAXN;i++)
                    arr[i]=0;
            }
            void push(int x)
            {
                if(length==MAXN)
                    return ;
                arr[length++]=x;
            }
            void pop()
            {
                if(length==0)
                    return ;
                arr[--length]=0;
            }
            int top()
            {
                if(length==0)
                    return -1;
                return arr[length-1];
            }
            bool empty()
            {
                return length==0;
            }
};

class StackList:public Stack{
    private:Node *sp;
    public: StackList():sp(nullptr){}
            void push(int x)
            {
                if(sp==nullptr)
                {
                    sp=new Node;
                    sp->x=x;
                    sp->next=nullptr;
                }
                else
                {
                    Node *temp=new Node;
                    temp->x=x;
                    temp->next=sp;
                    sp=temp;
                }
            }
            void pop()
            {
                if(sp==nullptr)
                    return ;
                Node *temp=sp;
                sp=sp->next;
                delete temp;
            }
            int top()
            {
                if(sp==nullptr)
                    return -1;
                return sp->x;
            }
            bool empty()
            {
                return (sp==nullptr);
            }
};


int main()
{
    StackArray obj;
    obj.push(1);
    obj.push(2);
    obj.push(3);
    obj.push(4);
    obj.push(5);
    while(!obj.empty())
    {
        cout<<obj.top()<<" ";
        obj.pop();
    }
    cout<<"\n";
    StackList obj1;
    obj1.push(1);
    obj1.push(2);
    obj1.push(3);
    obj1.push(4);
    obj1.push(5);
    while(!obj1.empty())
    {
        cout<<obj1.top()<<" ";
        obj1.pop();
    }
    return 0;
}