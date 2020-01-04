#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair, tuple

int main(){
      string s;cin >> s;
      int n = s.length();
      set<char> sc;
      for(int i = 0;i < n;i++)sc.insert(s[i]);
      if(sc.size() == n)cout << "yes";
      else cout << "no";
}