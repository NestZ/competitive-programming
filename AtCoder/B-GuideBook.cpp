#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      vector<pair<string, int>> v;
      map<pair<string, int>, int> m;
      for(int i = 0;i < n;i++){
            string s;cin >> s;
            int t;cin >> t;
            v.push_back(make_pair(s, -t));
            m[make_pair(s, -t)] = i + 1;
      }
      sort(v.begin(), v.end());
      int t = v.size();
      for(int i = 0;i < t;i++)cout << m[v[i]] << "\n";
}