#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > dp (100, vector<int> (100,-1));


int mcmMeoized(vector<int> vct,int i, int j){

    if(i>=j){
        dp[i][j] = 0;
        return dp[i][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int min = INT_MAX;
    for(int k = i;k<j;k++){
        int ans = mcmMeoized(vct,i,k)+mcmMeoized(vct,k+1,j) + vct[i-1]*vct[k]*vct[j];
        if(min>ans){
            min  = ans;
        }
    }
    return dp[i][j] = min;

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

    cout<<mcmMeoized(vct,1,n-1);

    return 0;
}
