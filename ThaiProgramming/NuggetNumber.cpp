#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      bool flag = false;
      set<int> s;
      for(int l = 6;l <= n;l++){
            for(int i = 0;i <= l / 6;i++){
                  for(int j = 0;j <= l / 9;j++){
                        for(int k = 0;k <= l / 20;k++){
                              if(i * 6 + j * 9 + k * 20 == l){
                                    if(s.count(l) == 0)cout << l << "\n";
                                    s.insert(l);
                                    flag = true;
                              }
                        }
                  }
            }
      }
      if(!flag)cout << "no";
}