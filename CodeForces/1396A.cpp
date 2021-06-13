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

  ll n;cin >> n;
  vector<ll> arr(n), want(n), fst(n), snd(n - 1, 0), trd;
  ll inv = n - 1;
  for(ll i = 0;i < n;i++){
    cin >> arr[i];
    want[i] = n - arr[i] % n;
  }
  if(n == 1){
    cout << "1 1\n0\n1 1\n0\n1 1\n" << -arr[0] << endl;
    return 0;
  }
  for(ll i = 0;i < n - 1;i++){
    ll x = -arr[i] * inv % n;
    fst[i] = x * (n - 1);
    assert(fst[i] % (n - 1) == 0);
  }
  snd.push_back(-arr.back() * inv % n * (n - 1));
  for(ll i = 0;i < n;i++){
    ll cur = fst[i] + snd[i] + arr[i];
    assert(cur % n == 0);
    trd.push_back(-cur);
  }
  cout << "1 " << n - 1 << endl;
  for(ll i = 0;i < n - 1;i++)cout << fst[i] << ' ';
  cout << endl;
  cout << "2 " << n << endl;
  for(ll i = 1;i < n;i++)cout << snd[i] << ' ';
  cout << endl;
  cout << "1 " << n << endl;
  for(ll i : trd)cout << i << ' ';
  cout << endl;
}
