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

const ll MOD = 1e9 + 7;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;cin >> n;
  ll ans = 1;
  bool valid = true;
  vector<ll> a(n), b(n), mxa(n), mxb(n), mna(n), mnb(n);
  for(int i = 0;i < n;i++)cin >> a[i];
  for(int i = 0;i < n;i++)cin >> b[i];
  mxa[0] = mna[0] = a[0];
  mxb[n - 1] = mnb[n - 1] = b[n - 1];
  for(int i = 1;i < n;i++){
    if(a[i] > a[i - 1]){
      mxa[i] = mna[i] = a[i];
    }
    else if(a[i] == a[i - 1]){
      mxa[i] = mxa[i - 1];
      mna[i] = 1;
    }
    else valid = false;
  }
  for(int i = n - 2;i >= 0;i--){
    if(b[i] > b[i + 1]){
      mxb[i] = mnb[i] = b[i];
    }
    else if(b[i] == b[i + 1]){
      mxb[i] = mxb[i + 1];
      mnb[i] = 1;
    }
    else valid = false;
  }
  for(int i = 0;i < n;i++){
    ll mn = max(mna[i], mnb[i]);
    ll mx = min(mxa[i], mxb[i]);
    ans = ans * max(0ll, mx - mn + 1) % MOD;
  }
  if(valid)cout << ans;
  else cout << 0;
  cout << endl;
}
