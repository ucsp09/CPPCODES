#include <iostream>
using namespace std;
const int MAXN=5;

class CircularQueue{
    private:int arr[MAXN];
            int start=0;
            int end=0;
            int length;
    public: CircularQueue():length(0)
            {
                for(int i=0;i<MAXN;i++)
                    arr[i]=0;            
            }
            void enqueue(int x)
            {
                if(length==MAXN)
                {
                    cout<<"Queue is Full\n";
                    return ;
                }
                arr[end++]=x;
                if(end==MAXN)
                    end=0;
                ++length;
            }
            void dequeue()
            {
                if(length==0)
                {
                    cout<<"Queue is empty\n";
                    return ;
                }
                arr[start++]=0;
                if(start==MAXN)
                    start=0;
                --length;
            }
            int front()
            {
                if(length==0)
                    return -1;
                return arr[start];
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
    CircularQueue obj;
    obj.enqueue(1);
    obj.enqueue(2);
    obj.enqueue(3);
    obj.enqueue(4);
    obj.enqueue(5);
    obj.enqueue(6);
    obj.println();
    obj.dequeue();
    obj.dequeue();
    obj.println();
    obj.enqueue(6);
    obj.enqueue(7);
    obj.enqueue(8);
    obj.println();
    return 0;
}