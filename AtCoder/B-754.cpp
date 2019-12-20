#include<bits/stdc++.h>
using namespace std;

int main(){
      string s;cin >> s;
      int n = s.length();
      int ans = INT_MAX;
      for(int i = 0;i < n - 2;i++){
            int t = stoi(s.substr(i, 3));
            if(abs(t - 753) < abs(ans - 753))ans = t;
      }
      cout << abs(ans - 753);
}