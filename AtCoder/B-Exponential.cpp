#include<bits/stdc++.h>
using namespace std;

int main(){
      int x;cin >> x;
      int b = 1;
      int p = 2;
      set<int> ans;
      if(x == 1 || x == 2)return cout << 1, 0;
      for(int i = b;i < x;i++){
            for(int j = p;j < x;j++){
                  if(pow(i, j) > x)break;
                  else ans.insert(pow(i, j));
            }
      }
      cout << *(--ans.end());
}