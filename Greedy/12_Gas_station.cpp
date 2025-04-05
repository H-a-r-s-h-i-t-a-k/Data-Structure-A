/*You are required to complete this method*/
class Solution
{
public:
    int startStation(vector<int> &gas, vector<int> &cost)
    {
        // Your
        int total_gas = 0, total_cost = 0;

        for (int i = 0; i < gas.size(); i++)
        {
            total_gas = total_gas + gas[i];
            total_cost = total_cost + cost[i];
        }
        if (total_gas < total_cost)
        {
            return -1;
        }
        int s = 0, currGass = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            currGass += (gas[i] - cost[i]);
            if (currGass < 0)
            {
                s = i + 1;
                currGass = 0;
            }
        }

        return s;
    }
};
