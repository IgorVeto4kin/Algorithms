#include <bits/stdc++.h>
#define ll long long
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
     int tar;
     cin>>tar;
     vector <bool> target(tar+1, false);
     target[0] = true; 
     for (int k = 1; k <= tar; k++){//итерируемся по числу, которое хотим получить
          for (int i = sum - a[k]; i>=0; i--){
               target[i+a[k]] = target[i] | target[i+a[k]] ;
          }    
     }

     
     cout<<"Unable to reuse numbers (задача о рюкзаке) "<<target[tar]<<endl;



      for (int k = 1; k <= tar; k++){
          for (int i = 0; i<n; i++){
               if(k>=a[i]){
                    target[k] = target[k] | target[k-a[i]];
               }
          }
     }
     cout<<"Able to reuse numbers (задача о размене) "<<target[tar]<<endl;


     return 0;
}    

