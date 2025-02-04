class Solution
{
public:
    vector<int> solve(int target, vector<int> notes)
    {
        vector<int> ans;
        int n = notes.size();
        for (int i = n - 1; i >= 0; i--)
        {
            while (target >= notes[i])
            {
                target -= notes[i];
                ans.push_back(notes[i]);
            }
        }

        return ans;
    }

    vector<int> minPartition(int N)
    {
        vector<int> notes = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        int n = notes.size();
        return solve(N, notes);
        // code here
    }
};