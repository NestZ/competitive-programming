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

  ll n, d, a;cin >> n >> d >> a;
  ll ans = 0;
  vector<pair<ll, ll>> monster;
  for(ll i = 0;i < n;i++){
    ll x, h;cin >> x >> h;
    monster.push_back({x, h});
  }
  sort(monster.begin(), monster.end());
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
  ll cur = 0;
  for(ll i = 0;i < n;i++){
    ll cur_x = monster[i].first;
    ll cur_h = monster[i].second; 
    while(!q.empty() && q.top().first < cur_x){
      cur -= q.top().second;
      q.pop();
    }
    if(cur * a >= cur_h)continue;
    ll rem = cur_h - (cur * a);
    ll want = (rem + a - 1) / a;
    cur += want;
    ans += want;
    q.push({cur_x + 2 * d, want});
  }
  cout << ans << endl;
}
