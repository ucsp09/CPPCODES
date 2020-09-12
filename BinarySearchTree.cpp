#include <iostream>
using namespace std;

class Node{
    private:Node *left;
            Node *right;
            int x;
    public: Node(int val):left(nullptr),right(nullptr),x(val){}
    friend class BinarySearchTree;
};

class BinarySearchTree{
    private:Node *root;
            Node* insert(Node *node,int val)
            {
                if(node==nullptr)
                    return new Node(val);
                if(val>node->x)
                    node->right=insert(node->right,val);
                else
                    node->left=insert(node->left,val);
                return node;
            }
            Node* search(Node *node,int val)
            {
                if(node==nullptr||node->x==val)
                    return node;
                if(val>node->x)
                    return search(node->right,val);
                else
                    return search(node->left,val);
            }
            Node* erase(Node *node,int val)
            {
                if(node==nullptr)
                    return node;
                if(node->x>val)
                    node->left=erase(node->left,val);
                else if(node->x<val)
                    node->right=erase(node->right,val);
                else
                {
                    if(node->left==nullptr && node->right==nullptr)
                    {
                        delete node;
                        return nullptr;
                    }
                    else if(node->left==nullptr)
                    {
                        Node *temp=node->right;
                        delete node;
                        return temp;
                    }
                    else if(node->right==nullptr)
                    {
                        Node *temp=node->left;
                        delete node;
                        return temp;
                    }
                    else
                    {
                        Node *temp=nullptr;
                        successor(node,temp,val);
                        node->x=temp->x;
                        node->right=erase(node->right,temp->x);
                    }
                }
            }
            void predecessor(Node *node,Node *&pre,int val)
            {
                if(node==nullptr)
                    return ;
                if(node->x==val)
                {
                    if(node->left!=nullptr)
                    {
                        Node *t2=node->left;
                        while(t2->right!=nullptr)
                            t2=t2->right;
                        pre=t2;
                    }
                }
                else if(node->x>val)
                {
                    predecessor(node->left,pre,val);
                }
                else
                {
                    pre=node;
                    predecessor(node->right,pre,val);
                }
            }
            void successor(Node *node,Node *&suc,int val)
            {
                if(node==nullptr)
                    return ;
                if(node->x==val)
                {
                    if(node->right!=nullptr)
                    {
                        Node *t1=node->right;
                        while(t1->left!=nullptr)
                            t1=t1->left;
                        suc=t1;
                    }
                }
                else if(node->x>val)
                {
                    suc=node;
                    successor(node->left,suc,val);
                }
                else
                {
                    successor(node->right,suc,val);
                }
            }
            void inorder(Node *node)
            {
                if(node==nullptr)
                    return ;
                inorder(node->left);
                cout<<node->x<<" ";
                inorder(node->right);
            }
            void preorder(Node *node)
            {
                if(node==nullptr)
                    return ;
                cout<<node->x<<" ";
                preorder(node->left);
                preorder(node->right);
            }
            void postorder(Node *node)
            {
                if(node==nullptr)
                    return ;
                postorder(node->left);
                postorder(node->right);
                cout<<node->x<<" ";
            }
    public: BinarySearchTree():root(nullptr){}
            void insert(int x)
            {
                if(root==nullptr)
                    root=insert(root,x);
                else
                    insert(root,x);
            }
            bool search(int x)
            {
                Node *temp=search(root,x);
                return temp!=nullptr;
            }
            void erase(int x)
            {
                root=erase(root,x);
            }
            void preorder()
            {
                preorder(root);
            }
            void inorder()
            {
                inorder(root);
            }
            void postorder()
            {
                postorder(root);
            }
            int predecessor(int val)
            {
                Node *pre=nullptr;
                predecessor(root,pre,val);
                if(pre!=nullptr)
                    return pre->x;
                return -1;
            }
            int successor(int val)
            {
                Node *suc=nullptr;
                successor(root,suc,val);
                if(suc!=nullptr)
                    return suc->x;
                return -1;
            }
};

int main()
{
    BinarySearchTree obj;
    obj.insert(50);
    obj.insert(30);
    obj.insert(20);
    obj.insert(40);
    obj.insert(70);
    obj.insert(60);
    obj.insert(80);
    obj.erase(50);
    obj.erase(70);
    obj.preorder();
    return 0;
}