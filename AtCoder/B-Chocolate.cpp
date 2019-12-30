#include<bits/stdc++.h>
using namespace std;

int main(){
      int n,d,x;cin >> n >> d >> x;
      int arr[n + 5];
      int ans = 0;
      for(int i = 0;i < n;i++)cin >> arr[i];
      for(int i = 1;i <= d;i++){
            for(int j = 0;j < n;j++){
                  if((i - 1) % arr[j] == 0)ans++;
            }
      }
      cout << ans + x;
}