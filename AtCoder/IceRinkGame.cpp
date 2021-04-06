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
  bool valid = true;
  vector<ll> arr(n);
  vector<ll> mn(n);
  vector<ll> mx(n);
  for(ll i = 0;i < n;i++)cin >> arr[i];
  if(arr[n - 1] != 2)valid = false;
  mn[n - 1] = 2;
  mx[n - 1] = 3;
  for(int i = n - 2;i >= 0;i--){
    mn[i] = (mn[i + 1] + arr[i] - 1) / arr[i] * arr[i];
    mx[i] = mx[i + 1] / arr[i] * arr[i] + arr[i] - 1;
    if(mn[i] > mx[i])valid = false;
  }
  if(valid)cout << mn[0] << ' ' << mx[0];
  else cout << -1;
  cout << endl;
}
