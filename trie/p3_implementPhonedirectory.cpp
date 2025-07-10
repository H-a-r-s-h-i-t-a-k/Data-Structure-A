// User function Template for C++

class TrieNode
{
public:
  char data;
  TrieNode *children[26];
  bool isTerminal;

  TrieNode(char val)
  {
    data = val;
    for (int i = 0; i < 26; i++)
    {
      children[i] = NULL;
    }
    isTerminal = false;
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
        temp->children[index] = new TrieNode(ch);
      }
      temp = temp->children[index];
    }
    temp->isTerminal = true;
  }

  void suggPrefix(TrieNode *t, vector<string> &temp, string &prefix)
  {
    if (t->isTerminal)
    {
      temp.push_back(prefix);
    }

    for (int i = 0; i < 26; i++)
    {
      if (t->children[i])
      {
        prefix.push_back('a' + i);
        suggPrefix(t->children[i], temp, prefix);
        prefix.pop_back();
      }
    }
  }

  vector<vector<string>> getSuggestion(string &s)
  {
    vector<vector<string>> output;
    TrieNode *prev = root;
    string prefix = "";
    bool flag = false;

    for (auto &ch : s)
    {
      int index = ch - 'a';
      prefix.push_back(ch);
      vector<string> temp;

      if (flag || prev->children[index] == NULL)
      {
        flag = true;
        output.push_back({"0"});
        continue;
      }

      TrieNode *curr = prev->children[index];
      suggPrefix(curr, temp, prefix);
      output.push_back(temp);
      prev = curr;
    }

    return output;
  }
};

class Solution
{
public:
  vector<vector<string>> displayContacts(int n, string contact[], string s)
  {
    // Sort contacts for lexicographical order
    sort(contact, contact + n);

    // Optional: remove duplicates
    // set<string> uniqueContacts(contact, contact + n);

    Trie *t = new Trie();
    for (int i = 0; i < n; i++)
    {
      t->insert(contact[i]);
    }

    return t->getSuggestion(s);
  }
};
