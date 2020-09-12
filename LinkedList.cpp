#include <iostream>

class Node{
    private:Node *next;
            int x;
    friend class LinkedList;
};
class LinkedList{
    private:Node *head;
            int length;
            Node* clone(Node *head)
            {
                if(head==nullptr)
                    return head;
                Node *newHead=new Node;
                newHead->x=head->x;
                newHead->next=nullptr;
                Node *p=head->next;
                Node *q=newHead;
                while(p!=nullptr)
                {
                    Node *temp=new Node;
                    temp->x=p->x;
                    temp->next=nullptr;
                    q->next=temp;
                    p=p->next;
                    q=q->next;
                }
                return newHead;
            }
            Node** getNode()
            {
                return &head;
            }
    public: LinkedList():head(nullptr),length(0){}
            void add(int x)
            {
                if(head==nullptr)
                {
                    head=new Node;
                    head->x=x;
                    head->next=nullptr;
                }
                else
                {
                    Node *p=head;
                    while(p->next!=nullptr)
                        p=p->next;
                    Node *temp=new Node;
                    temp->x=x;
                    temp->next=nullptr;
                    p->next=temp;
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
                    head=head->next;
                    delete temp;
                }
                else
                {
                    Node *p=head;
                    int cur_pos=0;
                    while(p!=nullptr && ++cur_pos != pos)
                        p=p->next;
                    Node *temp=p->next;
                    p->next=temp->next;
                    delete temp;
                }
                --length;
            }
            void reverse()
            {
                if(head==nullptr|| head->next==nullptr)
                    return ;
                Node *cur=head;
                Node *prev=nullptr;
                Node *next=nullptr;
                while(cur!=nullptr)
                {
                    next=cur->next;
                    cur->next=prev;
                    prev=cur;
                    cur=next;
                }
                head=prev;
            }
            void println()
            {
                Node *p=head;
                while(p!=nullptr)
                {
                    std::cout<<(p->x)<<" ";
                    p=p->next;
                }
                std::cout<<"\n";
            }
            void clone(LinkedList &obj)
            {
                Node **temp=obj.getNode();
                *temp=clone(head);
            }
            bool has_cycle()
            {
                Node *slow=head;
                Node *fast=head;
                while(!slow && !fast &&!fast->next)
                {
                    slow=slow->next;
                    fast=fast->next;
                    if(slow==fast)
                        return true;
                }
                return false;
            }
            inline int size()
            {
                return length;
            }
            inline bool empty()
            {
                return (length==0);
            }
};

int main()
{
    LinkedList obj;
    obj.add(1);
    obj.add(2);
    obj.add(3);
    obj.add(4);
    obj.add(5);
    LinkedList obj1;
    obj.clone(obj1);
    obj1.println();
    return 0;
}