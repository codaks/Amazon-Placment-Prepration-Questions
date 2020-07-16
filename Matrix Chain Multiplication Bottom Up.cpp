#include<bits/stdc++.h>
using namespace std;

int MCM(vector<int> p,int n){

    vector< vector<int> > dp(n, vector<int> (n,-1));

    for(int i = 0;i<n;i++){
        dp[i][i] = 0;
    }

    for(int L = 1;L<n;L++){
        for(int i = 1;i<n-L;i++){
            dp[i][i+L] = min(dp[i+1][i+L] + p[i-1]*p[i]*p[i+L],
                    dp[i][i+L-1] + p[i-1]*p[i+L-1]*p[i+L]);
        }
    }

    /*for(int i = 1;i<n;i++){
        for(int j = 1;j<n;j++){
            cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }*/
    return dp[1][n-1];

}

int main(){

    int n;
    cin>>n;
    int data;
    vector<int> vct;
    for(int i = 0;i<n;i++){
        cin>>data;
        vct.push_back(data);
    }

    cout<<MCM(vct,n);
    return 0;
}
