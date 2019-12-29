#include<bits/stdc++.h>
using namespace std;

int main(){
      int minn = INT_MAX;
      int n;cin >> n;
      int x;cin >> x;
      int all = 0;
      for(int i = 0;i < n;i++){
            int t;cin >> t;
            if(t < minn)minn = t;
            all += t;
      }
      cout << (x - all) / minn + n;
}