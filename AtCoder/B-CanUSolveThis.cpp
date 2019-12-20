#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      int m;cin >> m;
      int c;cin >> c;
      int arrb[m + 10];
      for(int i = 0;i < m;i++)cin >> arrb[i];
      int ans = 0;
      for(int i = 0;i < n;i++){
            int sum = 0;
            for(int j = 0;j < m;j++){
                  int t;cin >> t;
                  sum += t * arrb[j];
            }
            sum += c;
            if(sum > 0)ans++;
      }
      cout << ans;
}