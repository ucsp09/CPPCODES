#include <iostream>
using namespace std;

class Node{
    private:Node *next;
            int x;
    friend class QueueList;
};

class Queue{
    protected:const static int MAXN=10;
    public: virtual void enqueue(int)=0;
            virtual void dequeue()=0;
            virtual int front()=0;
            virtual bool empty()=0;
};

class QueueArray:public Queue{
    private:int arr[MAXN];
            int start;
            int end;
    public: QueueArray():start(0),end(0)
            {
                for(int i=0;i<MAXN;i++)
                    arr[i]=0;
            }
            void enqueue(int x)
            {
                if(end==MAXN)
                    return ;
                arr[end++]=x;
            }
            void dequeue()
            {
                if(end==0)
                    return ;
                for(int i=0;i<end-1;i++)
                    arr[i]=arr[i+1];
                arr[end-1]=0;
                end--;
            }
            int front()
            {
                if(end==0)
                    return -1;
                return arr[start];
            }
            bool empty()
            {
                return end==0;
            }
};

class QueueList:public Queue{
    private: Node *fp;
             Node *rp;
    public:QueueList():fp(nullptr),rp(nullptr){}
            void enqueue(int x)
            {
                if(rp==nullptr)
                {
                    rp=new Node;
                    rp->x=x;
                    rp->next=nullptr;
                    fp=rp;
                }
                else
                {
                    Node *temp=new Node;
                    temp->x=x;
                    temp->next=nullptr;
                    rp->next=temp;
                    rp=temp;
                }
            }
            void dequeue()
            {
                if(rp==nullptr)
                    return ;
                if(fp==rp)
                {
                    Node *temp=fp;
                    fp=rp=nullptr;
                    delete temp;
                }
                else
                {
                    Node *temp=fp;
                    fp=fp->next;
                    delete temp;
                }
            }
            int front()
            {
                if(rp==nullptr)
                    return -1;
                return fp->x;
            }
            bool empty()
            {
                return (rp==nullptr);
            }
            
};
int main()
{
    QueueArray obj;
    obj.enqueue(1);
    obj.enqueue(2);
    obj.enqueue(3);
    obj.enqueue(4);
    obj.enqueue(5);
    while(!obj.empty())
    {
        cout<<obj.front()<<" ";
        obj.dequeue();
    }
    cout<<endl;
    QueueList obj1;
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