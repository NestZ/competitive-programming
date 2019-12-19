#include<bits/stdc++.h>
using namespace std;

int main(){
      int a;cin >> a;
      int b;cin >> b;
      int ans = 0;
      int curr = 1;
      while(curr < b){
            curr--;
            curr += a;
            ans++;
      }
      cout << ans;
}