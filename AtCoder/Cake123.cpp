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

  ll x, y, z, k;cin >> x >> y >> z >> k;
  vector<ll> a(x), b(y), c(z);
  vector<ll> ab, ans;
  for(int i = 0;i < x;i++)cin >> a[i];
  for(int i = 0;i < y;i++)cin >> b[i];
  for(int i = 0;i < z;i++)cin >> c[i];
  sort(c.rbegin(), c.rend());
  for(ll i : a){
    for(ll j : b){
      ab.push_back(i + j);
    }
  }
  sort(ab.rbegin(), ab.rend());
  ll from_c = min((ll)c.size(), 3000ll);
  ll from_ab = min((ll)ab.size(), 3000ll);
  for(int i = 0;i < from_c;i++){
    for(int j = 0;j < from_ab;j++){
      ans.push_back(ab[j] + c[i]);
    }
  }
  sort(ans.rbegin(), ans.rend());
  for(int i = 0;i < k;i++){
    cout << ans[i] << endl;
  }
}
