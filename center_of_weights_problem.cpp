#include <bits/stdc++.h>
#define ll long long
using namespace std;
int ro(int x1, int y1, int x2, int y2){
     int ro_x, ro_y;
     ro_x = abs(x1-x2);
     ro_y = abs(y1-y2);
     return ro_x*ro_x + ro_y*ro_y;
}
struct dot{
     int x;
     int y;
};

bool centm(int x1, int y1, int x2, int y2, int xcm, int ycm){
     return (((xcm - x1)*(x2-x1) + (ycm - y1)*(y2-y1)) > 0 and ((xcm - x2)*(x1-x2) + (ycm - y2)*(y1-y2)) > 0);
}
int main(){
     int n;
     cin>>n;
     struct dot cm;
     cin>>cm.x>>cm.y;
     vector <struct dot> pol;
     for(int i = 0; i<n; i++){
          struct dot tempor;
          cin>>tempor.x>>tempor.y;
          pol.push_back(tempor);
     }

     ll ans = 0, temp = 0;
     int flag = 0;
     for(int i = 0; i< n-1; i++){
          for(int j = i+1; j<n; j++ ){
               if(centm(pol[i].x, pol[i].y, pol[j].x, pol[j].y, cm.x, cm.y)==0){
                    continue;
               }
               int a, b, c;
               bool all_points_1_side = true;
               a = pol[j].y - pol[i].y;
               b = pol[i].x - pol[j].x;
               c = (pol[j].x * pol[i].y)  - (pol[i].x * pol[j].y);
               for(int k = 0; k < n; k++){
                    temp = a* pol[k].x + b* pol[k].y + c;
                    if(temp == 0){//значит для каких-то i и j найдена точка, которая лежит на этом отрезке
                         int dlinna = ro(pol[i].x, pol[i].y, pol[j].x, pol[j].y);
                         if ((centm(pol[i].x, pol[i].y, pol[k].x, pol[k].y, cm.x, cm.y) or centm(pol[k].x, pol[k].y, pol[j].x, pol[j].y, cm.x, cm.y))
                         and (k!=i and k != j)  
                         and (  ro(pol[k].x, pol[k].y, pol[j].x, pol[j].y) > dlinna or ro(pol[k].x, pol[k].y, pol[i].x, pol[i].y) > dlinna )   ){//и она лежит на одном из подотрезков
                              all_points_1_side = false;
                              break;
                         }
                         else{
                              continue;
                         }
                    }
                    if(flag!=0){
                         if((flag > 0)!=(temp > 0)){
                              all_points_1_side = false;
                              break;
                         }
                    }
                    else{
                         flag = temp;
                    }
               }
               if(all_points_1_side){
                    ans++;
               //cout<<i<<" "<< j<<" ||"<< pol[i].x<< " "<< pol[i].y<< " "<< pol[j].x << " " <<pol[j].y<<endl;
               }
               flag = 0;
               //cout<<ans<<endl;
          }
     }
     cout<<ans<<'\n';
     return 0;
}    
