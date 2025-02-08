class Solution
{
public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n)
    {
        int ans = 0;
        while (n != 0)
        {
            ans = ans ^ n;
            n = n >> 1;
        }
        // Your code here
        return ans;
    }
};