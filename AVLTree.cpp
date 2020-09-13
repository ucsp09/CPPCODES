#include <iostream>
using namespace std;


class Node{
    private:
            int x;
            Node* left;
            Node* right;
            int height;
    public: Node(int val):x(val),left(nullptr),right(nullptr){}
    friend class AVLTree;
};

class AVLTree{
    private:Node* root;
            Node* insert(Node* root,int val)
            {
                if(root==nullptr)
                    root=new Node(val);
                else if(root->x>val)
                    root->left=insert(root->left,val);
                else if(root->x<val)
                    root->right=insert(root->right,val);
                else
                    return root;
                int diff=height(root->left)-height(root->right);
                if(diff>1)
                {
                    if(height(root->left->left)>=height(root->left->right))
                        root=rotateRight(root);
                    else
                    {
                        root->left=rotateLeft(root->left);
                        root=rotateRight(root);
                    }
                }
                else if(diff<-1)
                {
                    if(height(root->right->right)>=height(root->right->left))
                        root=rotateLeft(root);
                    else
                    {
                        root->right=rotateRight(root->right);
                        root=rotateLeft(root);
                    }
                }
                else
                    root->height=setHeight(root);
                return root;
            }
            Node* rotateRight(Node* root)
            {
                Node* newRoot=root->left;
                root->left=newRoot->right;
                newRoot->right=root;
                root->height=setHeight(root);
                newRoot->height=setHeight(newRoot);
                return newRoot;
            }
            Node* rotateLeft(Node* root)
            {
                Node* newRoot=root->right;
                root->right=newRoot->left;
                newRoot->left=root;
                root->height=setHeight(root);
                newRoot->height=setHeight(newRoot);
                return newRoot;
            }
            int height(Node* root)
            {
                if(root==nullptr)
                    return 0;
                return root->height;
            }
            int setHeight(Node* root)
            {
                if(root==nullptr)
                    return 0;
                return 1+max(height(root->left),height(root->right));
            }
            void preorder(Node* root)
            {
                if(root==nullptr)
                    return ;
                cout<<root->x<<" ";
                preorder(root->left);
                preorder(root->right);
            }
            Node* search(Node* root,int val)
            {
                if(root==nullptr||root->x==val)
                    return root;
                if(val<root->x)
                    return search(root->left,val);
                return search(root->right,val);
            }
            Node* erase(Node* root,int val)
            {
                if(root==nullptr)
                    return root;
                if(val<root->x)
                    root->left=erase(root->left,val);
                else if(val>root->x)
                    root->right=erase(root->right,val);
                else
                {
                    if(root->left==nullptr && root->right==nullptr)
                    {
                        delete root;
                        return nullptr;
                    }
                    else if(root->left==nullptr)
                    {
                        Node* temp=root->right;
                        delete root;
                        return temp;
                    }
                    else if(root->right==nullptr)
                    {
                        Node* temp=root->left;
                        delete root;
                        return temp;
                    }
                    else
                    {
                        Node* temp=root->right;
                        while(temp->left!=nullptr)
                            temp=temp->left;
                        root->x=temp->x;
                        root->right=erase(root->right,temp->x);
                    }
                }
                int diff=height(root->left)-height(root->right);
                if(diff>1)
                {
                    if(height(root->left->left)>=height(root->left->right))
                        root=rotateRight(root);
                    else
                    {
                        root->left=rotateLeft(root->left);
                        root=rotateRight(root);
                    }
                }
                else if(diff<-1)
                {
                    if(height(root->right->right)>=height(root->right->left))
                        root=rotateLeft(root);
                    else
                    {
                        root->right=rotateRight(root->right);
                        root=rotateLeft(root);
                    }
                }
                else
                    root->height=setHeight(root);
                return root;
            }
    public: AVLTree():root(nullptr){}
            void insert(int val)
            {
                root=insert(root,val);
            }
            void preorder()
            {
                preorder(root);
            }
            bool search(int val)
            {
                Node* temp=search(root,val);
                return temp!=nullptr;
            }
            void erase(int val)
            {
                root=erase(root,val);
            }
};


int main()
{
    AVLTree obj;
    obj.insert(10);
    obj.insert(20);
    obj.insert(30);
    obj.insert(40);
    obj.insert(50);
    obj.preorder();
    obj.erase(50);cout<<"\n";
    obj.preorder();
    obj.erase(20);cout<<"\n";
    obj.preorder();
    return 0;
}