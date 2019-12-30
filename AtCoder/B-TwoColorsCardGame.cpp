#include<bits/stdc++.h>
using namespace std;

int main(){
      map<string, int> m;
      int n;cin >> n;
      int ans = INT_MIN;
      for(int i = 0;i < n;i++){
            string s;cin >> s;
            m[s]++;
      }
      int t;cin >> t;
      for(int i = 0;i < t;i++){
            string s;cin >> s;
            m[s]--;
      }
      for(auto i : m){
            if(i.second > ans)ans = i.second;
      }
      cout << max(0, ans);
}