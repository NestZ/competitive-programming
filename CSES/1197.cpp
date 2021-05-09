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

vector<vector<pair<ll, ll>>> g(3000);
vector<ll> dist(3000, 1e18);
vector<ll> p(3000, 0);

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;cin >> n >> m;
  for(ll i = 0;i < m;i++){
    ll a, b, c;cin >> a >> b >> c;
    g[a].push_back({b, c});
  }
  dist[1] = 0;
  for(ll i = 0;i < n - 1;i++){
    for(ll j = 1;j <= n;j++){
      for(auto adj : g[j]){
        if(dist[j] + adj.second < dist[adj.first]){
          p[adj.first] = j;
          dist[adj.first] = dist[j] + adj.second;
        }
      }
    }
  }
  for(ll i = 1;i <= n;i++){
    for(auto adj : g[i]){
      if(dist[i] + adj.second < dist[adj.first]){
        cout << "YES\n";
        ll cur = adj.first;
        for(ll j = 0;j < n;j++)
          cur = p[cur];
        vector<ll> ans;
        for(ll v = cur;cur != 0;v = p[v]){
          ans.push_back(v);
          if(v == cur && ans.size() > 1){
            reverse(ans.begin(), ans.end());
            for(ll j : ans)cout << j << ' ';
            cout << endl;
            return 0;
          }
        }
      }
    }
  }
  cout << "NO\n";
}
