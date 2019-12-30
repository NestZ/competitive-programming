#include<bits/stdc++.h>
using namespace std;

int main(){
      int n,m,x;cin >> n >> m >> x;
      int l = 0;
      int r = 0;
      for(int i = 0;i < m;i++){
            int t;cin >> t;
            if(t < x)l++;
            else r++;
      }
      cout << min(l, r);
}