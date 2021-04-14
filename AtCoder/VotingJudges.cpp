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

  ll n, m, v, p;cin >> n >> m >> v >> p;
  set<ll> ans;
  vector<pair<ll, ll>> arr;
  for(ll i = 0;i < n;i++){
    ll a;cin >> a;
    arr.push_back({a, i});
  }
  sort(arr.rbegin(), arr.rend());
  vector<ll> pre(n + 1);
  for(ll i = 0;i < n;i++){
    pre[i + 1] = arr[i].first + pre[i] + m;
  }
  for(ll i = 0;i < n;i++){
    ll offset = m;
    ll back = n - i;
    ll front = max(0ll, v - back);
    ll ncur = arr[i].first + offset;
    if(ncur < arr[p - 1].first)continue;
    if(p - 1 >= i || (ncur >= arr[p - 1].first && front < p))
      ans.insert(arr[i].second);
    else{
      ll have = back * m + (p - 1) * m;
      ll rem = v * m - have;
      ll segment_sum = pre[i] - pre[p - 1];
      ll segment_mx = ncur * (i - p + 1);
      ll can = m * (i - p + 1) - (segment_sum - segment_mx);
      if(can >= rem)ans.insert(arr[i].second);
    }
  }
  cout << ans.size() << endl;
}
