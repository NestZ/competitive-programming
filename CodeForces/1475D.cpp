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

ll bsearch(ll want, ll cur_con,
    vector<ll> &mem, vector<ll> &con){
  //find first pos that prefix sum is greater or equal to want
  ll n = mem.size();
  ll best = LLONG_MAX;
  ll l = 0, r = n - 1;
  while(l <= r){
    ll mid = l + (r - l) / 2;
    ll sum = mem[mid];
    if(sum >= want){
      best = mid;
      r = mid - 1;
    }
    else l = mid + 1;
  }
  if(best == LLONG_MAX)return 1e18;
  else return con[best] + cur_con;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;cin >> t;
  while(t--){
    ll n, m;cin >> n >> m;
    vector<pair<ll, ll>> arr(n);
    vector<pair<ll, ll>> one, two;
    vector<ll> pre_mem, pre_con;
    for(ll i = 0;i < n;i++)cin >> arr[i].first;
    for(ll i = 0;i < n;i++)cin >> arr[i].second;
    for(ll i = 0;i < n;i++){
      if(arr[i].second == 1){
        one.push_back(arr[i]);
      }
      else two.push_back(arr[i]);
    }
    pre_mem.resize(one.size());
    pre_con.resize(one.size());
    sort(one.rbegin(), one.rend());
    sort(two.rbegin(), two.rend());
    for(ll i = 0;i < (ll)one.size();i++){
      pre_mem[i] = one[i].first;
      pre_con[i] = one[i].second;
      if(i > 0){
        pre_mem[i] += pre_mem[i - 1];
        pre_con[i] += pre_con[i - 1];
      }
    }
    ll ans = 1e18;
    ll cur_mem = 0, cur_con = 0;
    ans = min(ans, bsearch(m, cur_con, pre_mem, pre_con));
    for(ll i = 0;i < (ll)two.size();i++){
      cur_mem += two[i].first;
      cur_con += two[i].second;
      if(cur_mem >= m){
        ans = min(ans, cur_con);
        break;
      }
      ans = min(ans, bsearch(m - cur_mem, cur_con, pre_mem, pre_con));
    }
    if(ans == 1e18)ans = -1;
    cout << ans << endl;
  }
}
