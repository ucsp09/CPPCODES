#include <iostream>
using namespace std;

class Node{
    private:Node *next;
            Node *prev;
            int x;
    friend class DequeList;
};

class Deque{
    protected: const static int MAXN=5;
    public: virtual void push_back(int)=0;
            virtual void push_front(int)=0;
            virtual void pop_back()=0;
            virtual void pop_front()=0;
            virtual int front()=0;
            virtual int back()=0;
            virtual bool empty()=0;
};  

class DequeList:public Deque{
    private:Node *head;
            Node *tail;
            Node* newNode(int x)
            {
                Node *temp=new Node;
                temp->x=x;
                temp->next=temp->prev=nullptr;
                return temp;
            }
    public: DequeList():head(nullptr),tail(nullptr){}
            void push_back(int x)
            {
                if(head==nullptr)
                {
                    head=newNode(x);
                    tail=head;
                }
                else
                {
                    Node *temp=newNode(x);
                    tail->next=temp;
                    temp->prev=tail;
                    tail=temp;
                }
            }
            void push_front(int x)
            {
                if(head==nullptr)
                {
                    head=newNode(x);
                    tail=head;
                }
                else
                {
                    Node *temp=newNode(x);
                    temp->next=head;
                    head->prev=temp;
                    head=temp;
                }
            }
            void pop_back()
            {
                if(head==nullptr)
                    return ;
                if(head==tail)
                {
                    Node *temp=head;
                    head=tail=nullptr;
                    delete temp;
                }
                else
                {
                    Node *temp=tail;
                    tail=tail->prev;
                    tail->next=nullptr;
                    delete temp;
                }
            }
            void pop_front()
            {
                if(head==nullptr)
                    return ;
                if(head==tail)
                {
                    Node *temp=head;
                    head=tail=nullptr;
                    delete temp;
                }
                else
                {
                    Node *temp=head;
                    head=head->next;
                    head->prev=nullptr;
                    delete temp;
                }
            }
            int front()
            {
                if(head==nullptr)
                    return -1;
                return head->x;
            }
            int back()
            {
                if(head==nullptr)
                    return -1;
                return tail->x;
            }
            bool empty()
            {
                return head==nullptr;       
            }
};

class DequeArray:public Deque{
    private: int arr[MAXN];
                int start,end;
              int length;
    public: DequeArray():length(0),start(0),end(0)
            {
                for(int i=0;i<MAXN;i++)
                    arr[i]=0;
            }
            void push_back(int x)
            {
                if(length==MAXN)
                    return ;
                if(start==0 && end==0)
                    start=MAXN-1;
                arr[end++]=x;
                if(end==MAXN)
                    end=0;
                ++length;
            }
            void push_front(int x)
            {
                if(length==MAXN)
                    return ;
                if(start==0 && end==0)
                {
                    arr[start]=x;
                    start=MAXN-1;
                    end=1;
                }
                else
                {
                    arr[start--]=x;
                    if(start==-1)
                        start=MAXN-1;
                }
                ++length;
            }
            void pop_back()
            {
                if(length==0)
                    return ;
                if(end==0)
                {
                    arr[MAXN-1]=0;
                    end=MAXN-1;
                }
                else
                    arr[--end]=0;
                --length;
            }
            void pop_front()
            {
                if(length==0)
                    return ;
                if(start==MAXN-1)
                {
                    arr[0]=0;
                    start=0;
                }
                else
                    arr[++start]=0;
                --length;
                
            }
            int front()
            {
                if(length==0)
                    return -1;
                if(start==MAXN-1)
                    return arr[0];
                return arr[start+1];
            }
            int back()
            {
                if(length==0)
                    return -1;
                if(end==0)
                    return arr[MAXN-1];
                return arr[end-1];
            }
            bool empty()
            {
                return length==0;
            }
            void println()
            {
                for(int i=0;i<MAXN;i++)
                    cout<<arr[i]<<" ";
                cout<<"\n";
            }
};

int main()
{
   DequeArray obj;
   obj.push_back(1);
   obj.push_back(2);
   obj.push_back(3);
   obj.push_back(4);
   obj.push_back(5);
   while(!obj.empty())
    {
        cout<<obj.back()<<" ";
        obj.pop_back();
    }
    cout<<"\n";
    obj.push_front(1);
    obj.push_front(2);
    obj.push_front(3);
    obj.push_front(4);
    obj.push_front(5);
    while(!obj.empty())
    {
        cout<<obj.front()<<" ";
        obj.pop_front();
    }
    cout<<"\n";
    DequeList obj1;
    obj1.push_back(1);
    obj1.push_back(2);
    obj1.push_back(3);
    obj1.push_back(4);
    obj1.push_back(5);
    while(!obj1.empty())
    {
        cout<<obj1.back()<<" ";
        obj1.pop_back();
    }
    cout<<"\n";
    obj1.push_front(1);
    obj1.push_front(2);
    obj1.push_front(3);
    obj1.push_front(4);
    obj1.push_front(5);
    while(!obj1.empty())
    {
        cout<<obj1.front()<<" ";
        obj1.pop_front();
    }
    return 0;
}