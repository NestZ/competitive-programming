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

vector<bool> vis(200010, false);
vector<ll> g(200010);
stack<ll> s;
vector<ll> path;
int before_c = 0;

void dfs(ll n){
  vis[n] = true;
  s.push(n);
  if(!vis[g[n]])dfs(g[n]);
  else{
    while(s.top() != g[n]){
      path.push_back(s.top());
      s.pop();
    }
    path.push_back(g[n]);
    before_c = (int)s.size() - 1;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, k;cin >> n >> k;
  for(ll i = 1;i <= n;i++)cin >> g[i];
  dfs(1);
  if(k <= before_c){
    ll cur = 1;
    for(ll i = 0;i < k;i++)cur = g[cur];
    cout << cur;
  }
  else{
    reverse(path.begin(), path.end());
    k -= before_c;
    k %= (ll)path.size();
    debug() << imie(path) imie(k) imie(before_c);
    cout << path[k];
  }
  cout << endl;
}
