#include <iostream>
using namespace std;
class Node{
  private:Node *next;
            int x;
  friend class CircularLinkedList;
};

class CircularLinkedList{
    private:Node *head;
            Node *tail;
            int length;
    public: CircularLinkedList():head(nullptr),tail(nullptr),length(0){}
            void add(int x)
            {
                if(!head)
                {
                    head=new Node;
                    head->x=x;
                    head->next=nullptr;
                    tail=head;
                    tail->next=head;
                }
                else
                {
                    Node *temp=new Node;
                    temp->x=x;
                    if(head==tail)
                        head->next=temp;
                    temp->next=head;
                    tail->next=temp;
                    tail=temp;
                }
                ++length;
            }
            void pop(int pos)
            {
                if(pos<0||pos>=length)
                    return ;
                if(!pos)
                {
                    Node *temp=head;
                    if(head==tail)
                        head=tail=nullptr;
                    else
                    {
                        head=head->next;
                        tail->next=head;
                    }
                    delete temp;        
                }
                else
                {
                    int cur_pos=1;
                    Node *p=head;
                    while(p!=tail && ++cur_pos!=pos)
                        p=p->next;
                    Node *temp=p->next;
                    p->next=temp->next;
                    delete temp;
                }
                --length;
            }
            bool has_cycle()
            {
                Node *slow=head;
                Node *fast=head;
                while(slow!=nullptr && fast!=nullptr &&fast->next!=nullptr)
                {
                    slow=slow->next;
                    fast=fast->next->next;
                    if(slow==fast)
                        return true;
                }
                return false;
            }
            bool empty()
            {
                return (length==0);
            }
};

int main()
{
    CircularLinkedList obj;
    obj.add(1);
    obj.add(2);
    obj.add(3);
    obj.add(4);
    obj.add(5);
    while(!obj.empty())
    {
    if(obj.has_cycle())
        cout<<"Yes\n";
    else
        cout<<"No\n";
    obj.pop(0);
    }
    return 0;
}