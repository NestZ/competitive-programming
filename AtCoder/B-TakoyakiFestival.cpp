#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      int arr[n + 10];
      int ans = 0;
      for(int i = 0;i < n;i++)cin >> arr[i];
      for(int i = 0;i < n - 1;i++){
            for(int j = i + 1;j < n;j++){
                  ans += arr[i] * arr[j];
            }
      }
      cout << ans;
}