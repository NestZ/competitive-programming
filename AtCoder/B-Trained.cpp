#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair, tuple

int main(){
      set<int> press;
      int n;cin >> n;
      int arr[n + 5];
      int curr = 1;
      int ans = 0;
      for(int i = 0;i < n;i++)cin >> arr[i];
      for(int i = 0;i < n;i++){
            press.insert(curr);
            curr = arr[curr - 1];
            if(press.count(curr) != 0)return cout << -1, 0;
            ans++;
            if(curr == 2)break;
      }
      cout << ans;
}