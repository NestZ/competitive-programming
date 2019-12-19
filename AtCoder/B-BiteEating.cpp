#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      int l;cin >> l;
      int arr[n + 10];
      int ans = 0;
      int minn = 1;
      for(int i = 1;i <= n;i++){
            arr[i] = l + i - 1;
            ans += arr[i];
            if(abs(arr[i]) < abs(arr[minn]))minn = i;
      }
      ans -= arr[minn];
      cout << ans;
}