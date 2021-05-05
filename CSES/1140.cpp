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

  ll n;cin >> n;
  vector<pair<pair<ll, ll>, ll>> arr;
  vector<ll> dp(200010), lst(200010);
  for(ll i = 0;i < n;i++){
    ll a, b, p;cin >> a >> b >> p;
    arr.push_back({{b, a}, p});
  }
  sort(arr.begin(), arr.end());
  lst[0] = -1;
  for(ll i = 1;i < n;i++){
    pair<pair<ll, ll>, ll> want = {{arr[i].first.second, INT64_MIN}, INT64_MIN};
    auto ptr = upper_bound(arr.begin(), arr.end(), want);
    if(ptr == arr.begin())lst[i] = -1;
    else{
      ptr--;
      lst[i] = ptr - arr.begin();
    }
  }
  for(ll i = 0;i < n;i++){
    ll choose = arr[i].second + (lst[i] == -1 ? 0 : dp[lst[i]]);
    ll not_choose = (i > 0 ? dp[i - 1] : 0);
    dp[i] = max(choose, not_choose);
  }
  cout << dp[n - 1] << endl;
}
