#include <iostream>
using namespace std;

struct Node
{
    Node *links[28];
    bool flag = false;
    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            // moves to the reference trie
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (!node->containsKey(prefix[i]))
            {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};
int main()
{
    Trie trie;
    cout << "Inserting words: Replicater, Replicating, Replisating, Replicatike" << endl;
    trie.insert("Replicater");
    trie.insert("Replicating");
    trie.insert("Replisating");
    trie.insert("Replicate");

    cout << "Search if Replicatoring exists in trie: " << (trie.search("Replicatoring") ? "True" : "False") << endl;

    cout << "Search if Replicate exists in trie: " << (trie.search("Replicate") ? "True" : "False") << endl;

    cout << "If words is Trie start with Repli: " << (trie.startsWith("Repli") ? "True" : "False") << endl;

    return 0;
}
