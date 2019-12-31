#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      set<char> s;
      for(int i = 0;i < n;i++){
            char c;cin >> c;
            s.insert(c);
      }
      if(s.size() == 3)cout << "Three";
      else cout << "Four";
}