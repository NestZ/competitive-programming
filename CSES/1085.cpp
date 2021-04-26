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
  for(ll i = 0;i < n;i++)cin >> arr[i];
  ll l = *max_element(arr.begin(), arr.end());
  ll r = 1e18;
  ll best = INT64_MAX;
  while(l <= r){
    ll mid = l + (r - l) / 2;
    ll use = 1;
    ll sum = 0;
    for(ll i = 0;i < n;i++){
      if(sum + arr[i] > mid){
        sum = arr[i];
        use++;
      }
      else sum += arr[i];
    }
    if(use > k)l = mid + 1;
    else{
      best = mid;
      r = mid - 1;
    }
  }
  cout << best << endl;
}
