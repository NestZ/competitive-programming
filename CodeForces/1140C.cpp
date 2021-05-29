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
  vector<pair<ll, ll>> arr(n);
  vector<ll> mx_sum(n + 1);
  for(ll i = 0;i < n;i++){
    cin >> arr[i].second >> arr[i].first;
  }
  sort(arr.begin(), arr.end());
  priority_queue<ll> q;
  ll csum = 0;
  for(ll i = n - 1;i >= 1;i--){
    csum += arr[i].second;
    q.push(-arr[i].second);
    if((ll)q.size() == k){
      csum += q.top(); q.pop();
    }
    mx_sum[i] = csum;
  }
  ll ans = 0;
  for(ll i = 0;i < n;i++){
    ans = max(ans, (mx_sum[i + 1] + arr[i].second) * arr[i].first);
  }
  cout << ans << endl;
}
