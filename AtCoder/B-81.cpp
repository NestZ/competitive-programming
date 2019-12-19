#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      set<int> s;
      for(int i = 1;i <= 9;i++){
            for(int j = 1;j <= 9;j++){
                  s.insert(i * j);
            }
      }
      if(s.count(n) != 0)cout << "Yes";
      else cout << "No";
}