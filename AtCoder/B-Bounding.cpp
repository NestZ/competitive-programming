#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      int t;cin >> t;
      int arr[n + 10];
      for(int i = 0;i < n;i++)cin >> arr[i];
      int curr = 0;
      int ans = 0;
      while(curr <= t){
            ans++;
            curr += arr[ans - 1];
      }
      cout << ans;
}