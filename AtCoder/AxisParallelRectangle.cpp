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

vector<pair<ll, ll>> point;

ll cnt(ll mx_x, ll mn_x, ll mx_y, ll mn_y){
  ll res = 0;
  ll n = point.size();
  for(ll i = 0;i < n;i++){
    ll curx = point[i].first;
    ll cury = point[i].second;
    if(curx >= mn_x && curx <= mx_x &&
        cury >= mn_y && cury <= mx_y)
      res++;
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, k;cin >> n >> k;
  ll ans = INT64_MAX;
  vector<ll> x;
  vector<ll> y;
  for(ll i = 0;i < n;i++){
    ll cx, cy;cin >> cx >> cy;
    point.push_back({cx, cy});
    x.push_back(cx);
    y.push_back(cy);
  }
  sort(x.begin(), x.end());
  for(ll i = 0;i < n - 1;i++){
    for(ll j = i + 1;j < n;j++){
      ll max_y = max(y[i], y[j]);
      ll min_y = min(y[i], y[j]);
      for(ll m = 0;m < n - 1;m++){
        ll l = m + 1;
        ll r = n;
        ll best = INT64_MAX;
        while(l <= r){
          ll mid = l + (r - l) / 2;
          if(cnt(x[mid], x[m], max_y, min_y) >= k){
            r = mid - 1;
            best = x[mid];
          }
          else l = mid + 1;
        }
        if(best != INT64_MAX){
          ans = min(ans, (max_y - min_y) * (best - x[m]));
        }
      }
    }
  }
  cout << ans << endl;
}
