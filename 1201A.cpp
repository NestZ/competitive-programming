#include<bits/stdc++.h>
using namespace std;

int main(){
      int s,n;
      cin >> s >> n;
      char c[s+10][n+10];
      int maxAns[5] = {0};
      int rans = 0;
      int point[n+10];
      for(int i = 0;i < s;i++){
            for(int j = 0;j < n;j++){
                  cin >> c[i][j];
            }
      }
      for(int i = 0;i < n;i++)cin >> point[i];
      for(int i = 0;i < n;i++){
            int ans[5] = {0};
            for(int j = 0;j < s;j++){
                  if(c[j][i] == 'A')ans[0]++;
                  if(c[j][i] == 'B')ans[1]++;
                  if(c[j][i] == 'C')ans[2]++;
                  if(c[j][i] == 'D')ans[3]++;
                  if(c[j][i] == 'E')ans[4]++;
            }
            maxAns[i] = *max_element(ans,ans+5);
            rans += maxAns[i]*point[i];
      }
      cout << rans;
      return 0;
}