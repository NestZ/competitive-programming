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

  ll q;cin >> q;
  while(q--){
    ll n, m;cin >> n >> m;
    vector<pair<ll, pair<ll, ll>>> arr(n + 2);
    for(ll i = 1;i <= n;i++){
      cin >> arr[i].first >> arr[i].second.first >> arr[i].second.second;
    }
    bool ans = true;
    ll time = 0;
    ll mn = m, mx = m;
    for(ll i = 1;i <= n;i++){
      ll t = arr[i].first;
      ll s = arr[i].second.first;
      ll e = arr[i].second.second;
      mx += t - time;
      mn -= t - time;
      if(mx < s || mn > e){
        ans = false;
        break;
      }
      mx = min(mx, e);
      mn = max(mn, s);
      time = t;
    }
    if(ans)cout << "YES";
    else cout << "NO";
    cout << endl;
  }
}
