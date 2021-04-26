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

vector<ll> ft(200010, 0);

void add(ll k, ll x){
  while(k < 200010){
    ft[k] += x;
    k += k & -k;
  }
}

ll sum(ll k){
  ll s = 0;
  while(k > 0){
    s += ft[k];
    k -= k & -k;
  }
  return s;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, k;cin >> n >> k;
  ll ans = 0;
  vector<ll> arr(n + 1);
  map<ll, ll> lst;
  for(ll i = 1;i <= n;i++)cin >> arr[i];
  for(ll i = 1;i <= n;i++){
    if(lst.count(arr[i])){
      add(lst[arr[i]], -1);
    }
    add(i, 1);
    lst[arr[i]] = i;
    ll l = 1, r = i;
    //find first index that val is <= k
    ll best = INT64_MAX;
    while(l <= r){
      ll mid = l + (r - l) / 2;
      if(sum(i) - sum(mid - 1) <= k){
        best = mid;
        r = mid - 1;
      } else l = mid + 1;
    }
    ans += i - best + 1;
  }
  cout << ans << endl;
}
