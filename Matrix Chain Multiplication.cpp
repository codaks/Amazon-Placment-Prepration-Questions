#include <bits/stdc++.h>
using namespace std;

int matrixChainMultiplication(vector<long long int> vct, long long int i, long long int j)
{
    long long int min = 100000000000;
    if (i >= j)
    {
        return 0;
    }

    for (int k = i; k < j; k++)
    {
        int ans = matrixChainMultiplication(vct, i, k) + matrixChainMultiplication(vct, k + 1, j) + vct[i - 1] * vct[k] * vct[j];
        if (min > ans)
        {
            min = ans;
        }
    }
    return min;
}

int main()
{
    long long int n, data;
    cin >> n;
    vector<long long int> vct;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        vct.push_back(data);
    }

    cout << matrixChainMultiplication(vct, 1, n - 1);

    return 0;
}
