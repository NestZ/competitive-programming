#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair

int main(){
      int n,k;cin >> n >> k;
      vector<int> arr;
      int ans = 0;
      for(int i = 0;i < n;i++){
            int t;cin >> t;
            arr.push_back(t);
      }
      sort(arr.rbegin(), arr.rend());
      for(int i = 0;i < k;i++)ans += arr[i];
      cout << ans;
}