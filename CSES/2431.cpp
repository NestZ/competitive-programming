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
vector<ll> cnt(20, 0);

ll fuck(ll n){
  string s = to_string(n);
  ll len = s.length();
  ll flr = pow(10ll, len - 1);
  ll res = cnt[len - 1];
  res += (n - flr + 1) * len;
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll q;cin >> q;
  for(ll i = 1;i <= 18;i++){
    cnt[i] = 9 * pow(10ll, i - 1) * i;
    cnt[i] += cnt[i - 1];
  }
  while(q--){
    ll k;cin >> k;
    ll l = 1, r = 1e18;
    ll best = INT64_MAX;
    while(l <= r){
      ll mid = l + (r - l) / 2;
      if(fuck(mid) >= k){
        best = mid;
        r = mid - 1;
      }
      else l = mid + 1;
    }
    k -= fuck(best - 1);
    string num = to_string(best);
    cout << num[k - 1] << endl;
  }
}
