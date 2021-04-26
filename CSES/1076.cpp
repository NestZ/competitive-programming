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

ll sum(int k){
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
  vector<ll> arr(n);
  map<ll, ll> ind;
  map<ll, ll> inv;
  for(ll i = 0;i < n;i++){
    cin >> arr[i];
    ind[arr[i]] = 0;
  }
  ll cnt = 1;
  for(auto &p : ind)p.second = cnt++;
  for(ll i = 0;i < n;i++){
    inv[ind[arr[i]]] = arr[i];
  }
  for(ll i = 0;i < k;i++){
    add(ind[arr[i]], 1);
  }
  for(ll i = k - 1;i < n;i++){
    ll l = 1, r = 2e5;
    ll best = INT64_MAX;
    while(l <= r){
      ll mid = l + (r - l) / 2;
      if(sum(mid) >= (k + 1) / 2){
        best = mid;
        r = mid - 1;
      } else l = mid + 1;
    }
    cout << inv[best] << ' ';
    if(i != n - 1){
      add(ind[arr[i - k + 1]], -1); add(ind[arr[i + 1]], 1);
    }
  }
  cout << endl;
}
