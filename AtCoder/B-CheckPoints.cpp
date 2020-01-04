#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair, tuple

int dist(pair<int, int> p1, pair<int, int> p2){
      return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main(){
      int n,m;cin >> n >> m;
      vector<pair<int, int>> vs;
      vector<pair<int, int>> vc;
      for(int i = 0;i < n;i++){
            int x,y;cin >> x >> y;
            vs.push_back(make_pair(x, y));
      }
      for(int i = 0;i < m;i++){
            int x,y;cin >> x >> y;
            vc.push_back(make_pair(x, y));
      }
      for(int i = 0;i < n;i++){
            int currMin = 0;
            for(int j = 1;j < m;j++){
                  if(dist(vs[i], vc[j]) < dist(vs[i], vc[currMin])){
                        currMin = j;
                  }
            }
            cout << currMin + 1 << "\n";
      }
}