#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class TrieNode{
    private:unordered_map<char,TrieNode*> children;
            bool endOfWord;
    public: TrieNode():endOfWord(false){}
    friend class Trie;
};
class Trie{
    private:TrieNode* root;
    public: Trie():root(nullptr){}
            void insert(string &s)
            {
                if(root==nullptr)
                    root=new TrieNode;
                TrieNode *p=root;
                for(int i=0;i<(int)s.length();i++)
                {
                    if(p->children.count(s[i])==0)
                    {
                        TrieNode *q= new TrieNode;
                        p->children[s[i]]=q;
                    }
                    p=p->children[s[i]];
                }
                p->endOfWord=true;
            }
            bool search(string &s)
            {
                if(root==nullptr)
                    return false;
                TrieNode *p=root;
                for(int i=0;i<(int)s.length();i++)
                {
                    if(p->children.count(s[i])==0)
                        return false;
                    p=p->children[s[i]];
                }
                return p->endOfWord;
            }
};
int main()
{
    Trie obj;
    vector<string> vec={"abcd","ghjk","klmnop","abcf"};
    for(auto &x:vec)
        obj.insert(x);
    vector<string> inp={"abvnm","abcd","klmnop","axcvbn"};
    for(auto &x:inp)
    {
        bool ans=obj.search(x);
        if(ans)
            cout<<"Found\n";
        else
            cout<<"Not Found\n";
    }
    return 0;
}