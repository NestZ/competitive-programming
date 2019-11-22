#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      long long int arr[n+5][2+5];
      long long int ans = __INTMAX_MAX__;
      for(int i = 0;i < n;i++)cin >> arr[i][0] >> arr[i][1];
      for(int i = 1;i < (1 << n);i++){
            long long int currS = 1;
            long long int currB = 0;
            for(int j = 0;j < n;j++){
                  if((i & (1 << j)) != 0){
                        currS *= arr[j][0];
                        currB += arr[j][1];
                  }
            }
            ans = min(ans, abs(currS - currB));
      }
      cout << ans;
      return 0;
}