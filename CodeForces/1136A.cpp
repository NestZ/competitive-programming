#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;
      cin >> n;
      vector<pair<int,int>> v;
      for(int i = 0;i < n;i++){
            pair<int,int> temp;
            cin >> temp.first >> temp.second;
            v.push_back(temp);
      }
      int now;cin >> now;
      for(int i = 0;i < n;i++){
            if(now <= v[i].second){
                  return cout << n - i , 0;
            }
      }

      return 0;
}