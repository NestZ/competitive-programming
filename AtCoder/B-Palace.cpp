#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      int t, a;cin >> t >> a;
      int curr = 0;
      int minn = INT_MAX;
      for(int i = 0;i < n;i++){
            int k;cin >> k;
            if(abs((t * 1000 - k * 6) - a * 1000) < abs(minn - a)){
                  curr = i + 1;
                  minn = abs((t*1000 - k * 6) - a * 1000);
            }
      }
      cout << curr;
}