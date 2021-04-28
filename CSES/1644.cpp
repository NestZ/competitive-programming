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

const ll mxN = 200010;
vector<ll> st(4 * mxN, 0);

ll mx(ll a, ll b){
  a += mxN; b += mxN;
  ll res = INT64_MIN;
  while(a <= b){
    if(a % 2 == 1)res = max(res, st[a++]);
    if(b % 2 == 0)res = max(res, st[b--]);
    a /= 2; b /= 2;
  }
  return res;
}

void update(ll k, ll x){
  k += mxN;
  st[k] = x;
  for(k /= 2;k >= 1;k /= 2){
    st[k] = max(st[2 * k], st[2 * k + 1]);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, a, b;cin >> n >> a >> b;
  vector<ll> arr(n + 1);
  vector<ll> pre(n + 1);
  for(ll i = 1;i <= n;i++){
    cin >> arr[i];
    pre[i] = pre[i - 1] + arr[i];
  }
  for(ll i = 1;i <= n;i++){
    update(i, pre[i]);
  }
  ll ans = INT64_MIN;
  for(ll i = 1;i <= n - a + 1;i++){
    ll q = mx(i + a - 1, min(n, i + b - 1));
    ll offset = pre[i - 1];
    ans = max(ans, q - offset);
  }
  cout << ans << endl;
}
