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

  ll n, k;cin >> n >> k;
  vector<ll> arr(n);
  vector<ll> sum;
  vector<ll> pre(n + 1);
  vector<ll> cnt(100);
  ll ans = 0;
  for(ll i = 0;i < n;i++){
    cin >> arr[i];
    pre[i + 1] += arr[i] + pre[i];
  }
  for(ll i = 1;i <= n;i++){
    for(ll j = i;j <= n;j++){
      sum.push_back(pre[j] - pre[i - 1]);
    }
  }
  ll len = sum.size();
  for(auto i : sum){
    for(ll j = 0;j <= 55;j++){
      if(i & (1ll << j))cnt[j]++;
    }
  }
  vector<bool> valid(len, true);
  for(ll i = 55;i >= 0;i--){
    if(cnt[i] < k)continue;
    ll rem = 0;
    for(ll j = 0;j < len;j++){
      if(!valid[j])continue;
      if((1ll << i) & sum[j])
        rem++;
    }
    if(rem >= k){
      ans += (1ll << i);
      for(ll j = 0;j < len;j++){
        if((1ll << i) & sum[j]){}
        else valid[j] = false;
      }
    }
  }
  cout << ans << endl;
}
