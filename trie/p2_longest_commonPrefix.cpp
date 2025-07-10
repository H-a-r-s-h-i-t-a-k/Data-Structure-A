class TrieNode
{
public:
  char data;
  TrieNode *children[26];
  bool isTerminal;
  int cnt;
  TrieNode(char val)
  {
    data = val;
    for (int i = 0; i < 26; i++)
    {
      children[i] = NULL;
    }
    isTerminal = 0;
    cnt = 0;
  }
};

class Trie
{

public:
  TrieNode *root;
  Trie()
  {
    root = new TrieNode('\0');
  }

  void insert(string &word)
  {
    TrieNode *temp = root;
    for (auto &ch : word)
    {
      int index = ch - 'a';
      if (temp->children[index] == NULL)
      {
        TrieNode *child = new TrieNode(ch);
        temp->children[index] = child;
        temp->cnt++;
      }
      temp = temp->children[index];
    }
    temp->isTerminal = true;
  }

  string lcp(vector<string> &strs)
  {

    TrieNode *temp = root;
    string ans = "";

    for (auto &ch : strs[0])
    {
      if (temp->isTerminal)
        return ans;
      int index = ch - 'a';
      if (temp->cnt == 1)
      {
        ans.push_back(ch);
        temp = temp->children[index];
      }
      else
      {
        return ans;
      }
    }
    return ans;
  }
};

class Solution
{
public:
  string longestCommonPrefix(vector<string> &strs)
  {
    Trie *t = new Trie();

    for (auto &str : strs)
    {
      t->insert(str);
    }
    return t->lcp(strs);
  }
};
