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

vector<vector<pair<ll, ll>>> g(100010);
vector<ll> dist_not_used(100010, 1e18);
vector<ll> dist_used(100010, 1e18);
priority_queue<pair<ll, ll>> q_used, q_not_used;

void process_used(ll n){
  for(auto adj : g[n]){
    ll fst = adj.first;
    ll snd = adj.second;
    if(snd + dist_used[n] < dist_used[fst]){
      dist_used[fst] = snd + dist_used[n];
      q_used.push({-dist_used[fst], fst});
    }
  }
}

void process_not_used(ll n){
  for(auto adj : g[n]){
    ll fst = adj.first;
    ll snd = adj.second;
    ll snd_half = adj.second / 2; 
    if(snd + dist_not_used[n] < dist_not_used[fst]){
      dist_not_used[fst] = snd + dist_not_used[n];
      q_not_used.push({-dist_not_used[fst], fst});
    }
    if(snd_half + dist_not_used[n] < dist_used[fst]){
      dist_used[fst] = snd_half + dist_not_used[n];
      q_used.push({-dist_used[fst], fst});
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;cin >> n >> m;
  for(ll i = 0;i < m;i++){
    ll a, b, c;cin >> a >> b >> c;
    g[a].push_back({b, c});
  }
  q_not_used.push({0, 1});
  dist_not_used[1] = 0;
  while(!q_used.empty() || !q_not_used.empty()){
    if(q_not_used.empty() ||
        (-q_not_used.top().first <= -q_used.top().first &&
        !q_used.empty())){
      auto cur = q_used.top(); q_used.pop();
      ll node = cur.second;
      ll d = -cur.first;
      if(d > dist_used[node])continue;
      process_used(node);
    }
    else if(q_used.empty() ||
        (-q_used.top().first <= -q_not_used.top().first &&
         !q_not_used.empty())){
      auto cur = q_not_used.top(); q_not_used.pop();
      ll node = cur.second;
      ll d = -cur.first;
      if(d > dist_not_used[node])continue;
      process_not_used(node);
    }
    else assert(false);
  }
  cout << dist_used[n] << endl;
}
