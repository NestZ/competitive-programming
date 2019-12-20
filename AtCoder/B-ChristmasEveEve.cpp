#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      int sum = 0;
      int maxx = 0;
      for(int i = 0;i < n;i++){
            int t;cin >> t;
            if(t > maxx)maxx = t;
            sum += t;
      }
      cout << sum - (maxx / 2);
}