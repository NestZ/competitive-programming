#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      int arr[n + 10];
      int ans = 0;
      for(int i = 0;i < n;i++)cin >> arr[i];
      for(int i = 0;i < n;i++){
            int t;cin >> t;
            arr[i] -= t;
            if(arr[i] > 0)ans += arr[i];
      }
      cout << ans;
}