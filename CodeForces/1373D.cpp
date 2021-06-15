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

  ll t;cin >> t;
  while(t--){
    ll n;cin >> n;
    vector<ll> arr(n), pre_e(n), pre_o(n);
    vector<ll> get_e, get_o;
    for(ll i = 0;i < n;i++){
      cin >> arr[i];
      pre_e[i] = (i > 0 ? pre_e[i - 1] : 0);
      pre_o[i] = (i > 0 ? pre_o[i - 1] : 0);
      if(i & 1)pre_o[i] += arr[i];
      else pre_e[i] += arr[i];
    }
    for(ll i = 1;i < n;i++){
      ll cur_get = ((i & 1) ? pre_o[i] - pre_e[i] : pre_o[i] - pre_e[i] + pre_e.front());
      if(i & 1)get_o.push_back(cur_get);
      else get_e.push_back(cur_get);
    }
    ll cur_e = 0, cur_o = 0, mx_e = 0, mx_o = 0;
    ll ans = pre_e.back();
    for(ll i = 0;i < (ll)get_e.size();i++){
      ll lst = (i > 0 ? get_e[i - 1] : 0);
      cur_e = max(0ll, cur_e + get_e[i] - lst);
      mx_e = max(mx_e, cur_e);
    }
    for(ll i = 0;i < (ll)get_o.size();i++){
      ll lst = (i > 0 ? get_o[i - 1] : 0);
      cur_o = max(0ll, cur_o + get_o[i] - lst);
      mx_o = max(mx_o, cur_o);
    }
    cout << ans + max(mx_e, mx_o) << endl;
  }
}
