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

  ll t;cin >> t;
  while(t--){
    ll n;cin >> n;
    bool valid = true;
    vector<ll> arr(2 * n);
    vector<ll> b(n), d(n);
    for(ll i = 0;i < 2 * n;i++)cin >> arr[i];
    sort(arr.rbegin(), arr.rend());
    for(ll i = 0;i < n;i++){
      if(arr[i * 2] != arr[i * 2 + 1])valid = false;
      b[i] = arr[i * 2];
    }
    for(ll i = 1;i < n;i++){
      if(b[i - 1] == b[i] || (b[i - 1] - b[i]) % (2 * (n - i)))
        valid = false;
      d[i] = (b[i - 1] - b[i]) / 2 / (n - i);
    }
    for(ll i = 1;i < n;i++){
      b[n - 1] -= 2 * i * d[i];
    }
    if(b[n - 1] <= 0 || b[n - 1] % (2 * n))valid = false;
    if(valid)cout << "YES";
    else cout << "NO";
    cout << endl;
  }
}
