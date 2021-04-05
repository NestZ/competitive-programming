#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for(auto it = d.b;it != d.e;++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;cin >> n;
  vector<vector<int>> g(n + 1, vector<int>(n + 1, 0));
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= n;j++){
      char c;cin >> c;
      if(c == '1')g[i][j] = 1;
    }
  }
  int ans = -1;
  for(int i = 1;i <= n;i++){
    int mx_color = 1;
    bool valid = true;
    vector<int> color(n + 1, -1);
    queue<pair<int, int>> q;
    q.push({i, 1});
    color[i] = 1;
    while(!q.empty()){
      auto cur = q.front(); q.pop();
      for(int j = 1;j <= n;j++){
        if(cur.first != j && g[cur.first][j] && color[j] == -1){
          q.push({j, cur.second + 1});
          color[j] = cur.second + 1;
          mx_color = max(mx_color, color[j]);
        }
      }
    }
    for(int j = 1;j <= n;j++){
      for(int k = 1;k <= n;k++){
        if(j == k || g[j][k] == 0)continue;
        if(abs(color[j] - color[k]) != 1)
          valid = false;
      }
    }
    if(valid)ans = max(ans, mx_color);
  }
  cout << ans << endl;
}
