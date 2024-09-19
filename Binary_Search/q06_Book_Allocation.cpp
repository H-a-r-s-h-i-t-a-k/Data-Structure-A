bool ispossible(int n, int arr[], int m, long long mid)
{
    int studentcount = 1;
    long long pagesum = 0;

    for (int i = 0; i < n; i++)
    {
        if (pagesum + arr[i] <= mid)
        {
            pagesum += arr[i];
        }
        else
        {
            studentcount++;
            if (studentcount > m || arr[i > mid])
                return false;

            pagesum = arr[i];
        }
        if (studentcount > m)
            return false;
    }

    return true;
}
int allocatebooks(int n, int arr[], int m)
{
    int s = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    long long e = sum, mid = s + (e - s) / 2, ans = -1;

    while (s <= e)
    {
        if (ispossible(n, arr, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;

        mid = s + (e - s) / 2;
    }
    return ans;
}