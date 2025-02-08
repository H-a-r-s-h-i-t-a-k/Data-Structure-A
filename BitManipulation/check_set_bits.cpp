class Solution
{
public:
    int isBitSet(int N)
    {
        // code here
        while (N)
        {
            if (N & 1 != 1)
            {
                return 0;
            }
            N = N >> 1;
        }

        return 1;
    }
};