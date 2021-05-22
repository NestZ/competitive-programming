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

ll point(ll pt, ll pe, ll ph, ll ah, ll ae, ll a, ll b){
  ll res = pe + ph;
  pt -= a * pe;
  pt -= b * ph;
  if(pt < 0)return 0;
  ll rh = ah - ph;
  ll re = ae - pe;
  res += min(re, pt / a);
  pt -= a * min(re, pt / a);
  res += min(rh, pt / b);
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  ll q;cin >> q;
  while(q--){
    ll n, t, a, b;cin >> n >> t >> a >> b;
    ll ans = 0, e_cnt = 0, h_cnt = 0;
    ll pe = 0, ph = 0;
    vector<pair<ll, ll>> arr(n);
    for(ll i = 0;i < n;i++){
      cin >> arr[i].second;
      if(arr[i].second == 0)e_cnt++;
      else h_cnt++;
    }
    for(ll i = 0;i < n;i++){
      cin >> arr[i].first;
    }
    sort(arr.begin(), arr.end());
    ans = point(max(0ll, arr[0].first - 1), 0, 0, h_cnt, e_cnt, a, b);
    for(ll i = 0;i < n - 1;i++){
      if(arr[i].second == 0)pe++;
      else ph++;
      ll pt = max(0ll, arr[i + 1].first - 1);
      ans = max(ans, point(pt, pe, ph, h_cnt, e_cnt, a, b));
    }
    ans = max(ans, point(t, e_cnt, h_cnt, h_cnt, e_cnt, a, b));
    cout << ans << endl;
  }
}
