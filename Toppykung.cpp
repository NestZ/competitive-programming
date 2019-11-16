#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      set<string> s;
      for(int i = 0;i < n;i++){
            string t;cin >> t;
            s.insert(t);
      }
      set<string>::iterator it;
      for(it = s.begin();it != s.end();it++)cout << *it << "\n";
      return 0;
}