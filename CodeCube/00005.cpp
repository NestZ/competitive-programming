#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      vector<long long> v;
      for(int i = 0;i < n;i++){
            int t;cin >> t;
            v.push_back(t);
      }
      long long maxx = *max_element(v.begin(), v.end());
      long long m = 1;
      bool flag = false;
      int t = v.size();
      while(!flag){
            flag = true;
            for(int i = 0;i < t;i++){
                  if((maxx * m) % v[i] != 0ll){
                        m++;
                        flag = false;
                        break;
                  }
            }
      }
      cout << maxx * m;
}