#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      vector<int> v;
      for(int i = 0;i < n;i++){
            int ans = 0;
            int t;cin >> t;
            if(t & 1)return cout << 0, 0;
            while(!(t & 1)){
                  ans++;
                  t = t >> 1;
            }
            v.push_back(ans);
      }
      cout << *min_element(v.begin(), v.end());
}