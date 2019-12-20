#include<bits/stdc++.h>
using namespace std;

int main(){
      int n,m;cin >> n >> m;
      map<int, int> mm;
      int ans = 0;
      for(int i = 0;i < n;i++){
            set<int> no;
            int k;cin >> k;
            for(int j = 0;j < k;j++){
                  int t;cin >> t;
                  if(no.count(t) == 0){
                        mm[t]++;
                        no.insert(t);
                        if(mm[t] == n)ans++;
                  }
            }
      }
      cout << ans;
}