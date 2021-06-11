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

bool dfs(pair<int, int> cur, pair<int, int> lst, map<pair<int, int>, bool> &vis, vector<int> &own_r, vector<int> &own_c,
    vector<pair<int, int>> &arr){
  vis[cur] = true;
  int cx = cur.first;
  int cy = cur.second;
  auto d1 = make_pair(cx, cx);
  auto d2 = make_pair(cy, cy);
  auto a1 = arr[own_r[cy]];
  auto a2 = arr[own_c[cx]];
  bool ncycle = true;
  if(cx != cy){
    if(d2 != lst){
      if(!vis[d2])
        ncycle &= dfs(d2, cur, vis, own_r, own_c, arr);
      else ncycle = false;
    }
    if(d1 != lst){
      if(!vis[d1])
        ncycle &= dfs(d1, cur, vis, own_r, own_c, arr);
      else ncycle = false;
    }
  }
  else{
    if(own_c[cx] && a2 != lst && a2 != cur){
      if(!vis[a2])
        ncycle &= dfs(a2, cur, vis, own_r, own_c, arr);
      else ncycle = false;
    }
    if(own_r[cy] && a1 != lst && a1 != cur){
      if(!vis[a1])
        ncycle &= dfs(a1, cur, vis, own_r, own_c, arr);
      else ncycle = false;
    }
  }
  return ncycle;
}
 
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  int t;cin >> t;
  while(t--){
    int n, m;cin >> n >> m;
    vector<int> own_r(n + 1), own_c(n + 1);
    vector<pair<int, int>> arr(m + 1);
    map<pair<int, int>, bool> vis;
    int ans = 0;
    for(int i = 1;i <= n;i++){
      vis[{i, i}] = false;
    }
    for(int i = 1;i <= m;i++){
      int r, c;cin >> r >> c;
      arr[i].first = r;
      arr[i].second = c;
      own_r[r] = own_c[c] = i;
      if(r != c)ans++;
      vis[{r, c}] = false;
    }
    for(auto p : vis){
      if(p.second)continue;
      if(!dfs(p.first, {-1, -1}, vis, own_r, own_c, arr))
        ans++;
    }
    cout << ans << endl;
  }
}
