#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      int k;cin >> k;
      vector<int> v;
      for(int i = 0;i < n;i++){
            int t;cin >> t;
            v.push_back(t);
      }
      bool flag = false;
      while(!flag){
            flag = true;
            for(int i = 0;i < n && k > 0;i++){
                  if(v[i] > v[i + 1] && k > 0){
                        v.erase(v.begin() + i);
                        k--;
                        n--;
                        flag = false;
                        break;
                  }
            }
      }
      while(k--)v.erase(v.end() - 1);
      for(int i : v)cout << i << " ";
}