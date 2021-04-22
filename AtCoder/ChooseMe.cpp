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

bool comp(pair<ll, ll> &a, pair<ll, ll> &b){
  ll sa = 2 * a.first + a.second;
  ll sb = 2 * b.first + b.second;
  return sa < sb;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;cin >> n;
  ll tak = 0, aoki = 0, ans = 0;
  vector<pair<ll, ll>> arr;
  for(ll i = 0;i < n;i++){
    ll a, b;cin >> a >> b;
    arr.push_back({a, b});
    aoki += a;
  }
  sort(arr.rbegin(), arr.rend(), comp);
  for(ll i = 0;i < n && tak <= aoki;i++){
    tak += arr[i].first + arr[i].second;
    aoki -= arr[i].first;
    ans++;
  }
  cout << ans << endl;
}
