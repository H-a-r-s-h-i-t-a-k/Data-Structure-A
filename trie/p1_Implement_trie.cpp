#include<iostream>
using namespace std;



class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    int isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = 0;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie() { root = new TrieNode('\0'); }
    void insertUtilsR(TrieNode *&root, string word)
    {
        // base condition
        if (word.length() == 0)
        {
            root->isTerminal++;
            return;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertUtilsR(child, word.substr(1));
    }
    // void insertUtilsL(TrieNode *&root, string word)
    // {
    //     TrieNode *temp = root;
    //     for (auto &ch : word)
    //     {
    //         int index = ch - 'a';
    //         if (temp->children[index] == nullptr)
    //         {
    //             TrieNode *node = new TrieNode(ch);
                
    //                 temp->children[index] = node;
                

    //             }
    //             temp = temp->children[index];
    //     }
    //     temp->isTerminal++;
    // }
    void insert(string word)
    {
        insertUtilsR(root, word);
        // insertUtilsL(root, word);
    }

    int countUtils(TrieNode *&root, string word)
    {
        TrieNode *child = root;
        for (auto &ch : word)
        {
            int index = ch - 'a';
            if (child->children[index] == nullptr)
            {
                return 0;
            }
            child = child->children[index];
        }
        return child->isTerminal;
    }

    int countWordsEqualTo(string word)
    {
        return countUtils(root, word);
    }

    // int countWordsStartingWith(string word) {}

    void erase(string word) 
    {   TrieNode* temp=root;
        for(auto& ch:word){
            int index=ch-'a';
            if(temp->children[index]==nullptr){
                return;
            }
            temp=temp->children[index];
        }
        temp->isterminal=0;
    }
};



int main(){
    Trie* root=new Trie();
    root->insert("apple");
    root->insert("apple"); 
 

    root->insert("apple");
    root->insert("applee");
    root->insert("applllee");
   cout<< root->countWordsEqualTo("apple")<<endl;
   cout << root->countWordsEqualTo("applee")<<endl;
   cout << root->countWordsEqualTo("applllee");
}