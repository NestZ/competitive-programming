#include<bits/stdc++.h>
using namespace std;

int main(){
      int ans = INT_MIN;
      int n;cin >> n;
      int arr[n];
      for(int i = 0;i < n;i++)cin >> arr[i];
      for(int i = 0;i < n - 1;i++){
            for(int j = 1;j < n;j++){
                  ans = max(ans, abs(arr[i] - arr[j]));
            }
      }
      cout << ans;
}