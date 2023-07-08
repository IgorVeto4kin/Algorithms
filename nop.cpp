#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n, m;
    vector <int> pos_n, pos_m;
    cin>>n;
    for(int i = 0; i<n; i++){
        int t;
        cin>>t;
        pos_n.push_back(t);
    }
    cin>>m;
    for(int i = 0; i<m; i++){
        int t;
        cin>>t;
        pos_m.push_back(t);
    }
    int dp[n+1][m+1];
    for(int i = 0; i<=n; i++){
        dp[i][0] = 0;
    }
    for(int i = 0; i<=m; i++){//fin init
        dp[0][i] = 0;
    }
    int atkuda[n+1][m+1]; // 1 - vert, 2 - gorizont, 0 -diag


    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(pos_n[i-1]==pos_m[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
                atkuda[i][j] = 0;
            }
            else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                if(dp[i][j-1] > dp[i-1][j]){
                    dp[i][j] = dp[i][j-1];
                    atkuda[i][j] = 2;
                }
                else{
                    dp[i][j] = dp[i-1][j];
                    atkuda[i][j] = 1;
                }
            }
            //cout<<pos_n[i-1]<<" "<<pos_m[j-1]<<" "<<dp[i][j]<<endl;
        }
    }
    vector <int> ans;
    int c_n = n, c_m = m;
    while (c_n!=0 && c_m!=0){
        if(atkuda[c_n][c_m] == 0){
            ans.push_back(pos_n[c_n-1]);
            c_n--;
            c_m--;
        }
        if(atkuda[c_n][c_m] == 1){
            c_n--;
        }
        if(atkuda[c_n][c_m] == 2){
            c_m--;
        }
    }
    //cout<<dp[n][m]<<endl;   
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=m; j++){
            //cout<<dp[i][j]<<" ";
        }
        //cout<<endl;
    }
    for(int i = ans.size()-1; i>=0; i--){
        cout<<ans[i]<<" ";
    }
    cout<< endl;
    return 0;
}         
