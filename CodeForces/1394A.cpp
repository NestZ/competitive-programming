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

const ll mxN = 1e5;

void build(vector<ll> &arr, ll n){
  sort(arr.begin() + 1, arr.begin() + n + 1);
  reverse(arr.begin() + 1, arr.begin() + n + 1);
  for(ll i = 1;i <= n;i++)
    arr[i] += arr[i - 1];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, d, m;cin >> n >> d >> m;
  ll l = 0, g = 0;
  vector<ll> lt(mxN + 5), gt(mxN + 5);
  for(ll i = 0;i < n;i++){
    ll t;cin >> t;
    if(t > m)gt[++g] = t;
    else lt[++l] = t;
  }
  if(g == 0){
    ll res = 0;
    for(ll i = 1;i <= n;i++)res += lt[i];
    cout << res << endl;
    return 0;
  }
  build(lt, l);
  build(gt, g);
  fill(lt.begin() + l + 1, lt.begin() + n + 1, lt[l]);
  ll ans = 0;
  for(ll i = (g + d) / (1 + d);i <= (ll)gt.size();i++){
    if((i - 1) * (d + 1) + 1 <= n){
      ans = max(ans, gt[i] + lt[n - (i - 1) * (d + 1) - 1]);
    }
  }
  cout << ans << endl;
}
