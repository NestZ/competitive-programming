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

  int n, m;cin >> n >> m;
  int ans = 0;
  vector<pair<int, int>> con;
  vector<pair<int, int>> p;
  for(int i = 0;i < m;i++){
    int a, b;cin >> a >> b;
    con.push_back({a, b});
  }
  int k;cin >> k;
  for(int i = 0;i < k;i++){
    int c, d;cin >> c >> d;
    p.push_back({c, d});
  }
  for(int i = 0;i < (1 << k);i++){
    vector<bool> cur(n + 1, false);
    int cnt = 0;
    for(int j = 0;j < k;j++){
      if((1 << j) & i)cur[p[j].first] = true;
      else cur[p[j].second] = true;
    }
    for(auto j : con){
      if(cur[j.first] && cur[j.second])cnt++;
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;
}
