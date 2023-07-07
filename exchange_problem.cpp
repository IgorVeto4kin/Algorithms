#include <bits/stdc++.h>
#define ll long long
#define INF 2147483647 //максимальное значение типа int
using namespace std;
int main(){
     int n, sum = 0;
     cin>>n;
     vector < int> a;
     for(int i = 0; i<n; i++){//we think, that all numbers are positive
          int t;
          cin>>t;
          sum+=t;
          a.push_back(t);
     }
 
     int tar;//аналог заветной N
     cin>>tar;//конец считывания
     vector <int > dp(tar+1, INF);
     dp[0] = 0;
         vector<int> answer (tar+1, 0);
     for( int i = 1; i<=tar; i++){
          dp[i] = INF;
          for (auto c :a){
               if (i-c>=0){
                    //dp[i] = min(dp[i-c]+1, dp[i]);
                    if (dp[i]> dp[i-c]+1){
                         answer[i] = c;
                         dp[i] =dp[i-c]+1;
                    }
               }
          }
     }
     cout << "Количество монет "<<dp.back()<<endl;
     for(int i = 0; i<=tar; i++){
          //cout<<dp[i]<<" ";
     }
     int iterator = tar;
     cout<< "Нужны такие монеты: ";
     while(iterator>0){
          cout<<answer[iterator]<<" ";
          iterator -= answer[iterator];
     }

     return 0;
}    
