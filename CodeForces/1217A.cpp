#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      for(int i = 0;i < n;i++){
            int s,in,e;cin >> s >> in >> e;
            if(s + e <= in)cout << 0;
            else if(e == 0)cout << 1;
            else if(in + e < s)cout << e + 1;
            else cout << (s + e + 1 - in) / 2;
            cout << "\n";
      }
      return 0;
}