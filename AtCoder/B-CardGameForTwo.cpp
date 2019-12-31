#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      vector<int> arr;
      for(int i = 0;i < n;i++){
            int t;cin >> t;
            arr.push_back(t);
      }
      sort(arr.rbegin(), arr.rend());
      int a = 0;
      int b = 0;
      for(int i = 0;i < n;i++){
            if(!(i & 1))a += arr[i];
            else b += arr[i];
      }
      cout << max(a, b) - min(a, b);
}