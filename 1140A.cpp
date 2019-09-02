#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      int arr[n];
      for(int i = 0;i < n;i++)cin >> arr[i];
      int ans = 0;
      int maxx = 1;
      for(int i = 0;i < n;i++){
            maxx = max(arr[i],maxx);
            if(i + 1 == maxx)ans++;
      }
      cout << ans;
      return 0;
}