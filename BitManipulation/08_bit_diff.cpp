/*
10100
11001
01101=xor
00001
--------
0

*/
class Solution
{
public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b)
    {

        int c = 0;
        int xr = a ^ b;
        while (xr)
        {
            if (xr & 1 == 1)
            {
                c++;
            }
            xr = xr >> 1;
        }
        return c;
    }
};