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

ll cnt(vector<ll> &arr){
  ll n = arr.size();
  ll res = 0;
  ll cur = 0;
  bool plus = arr[0] > 0;
  for(int i = 0;i < n;i++){
    cur += arr[i];
    if(plus && cur <= 0){
      res += 1 - cur;
      cur = 1;
    }
    else if(!plus && cur >= 0){
      res += cur + 1;
      cur = -1;
    }
    plus = !plus;
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;cin >> n;
  vector<ll> arr(n);
  for(ll i = 0;i < n;i++)cin >> arr[i];
  ll mn = INT64_MAX;
  ll tmp = arr[0];
  //start minus
  arr[0] = min(-1ll, arr[0]);
  mn = min(mn, cnt(arr) + abs(arr[0] - tmp));

  arr[0] = tmp;
  //start plus
  arr[0] = max(arr[0], 1ll);
  mn = min(mn, cnt(arr) + abs(arr[0] - tmp));
  cout << mn << endl;
}
