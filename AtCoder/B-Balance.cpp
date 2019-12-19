#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      int sum = 0;
      int no = 0;
      int ans = INT_MAX;
      int arr[n + 10];
      for(int i = 0;i < n;i++){
            cin >> arr[i];
            sum += arr[i];
      }
      for(int i = 0;i < n;i++){
            no += arr[i];
            sum -= arr[i];
            ans = min(ans, abs(sum - no));
      }
      cout << ans;
}