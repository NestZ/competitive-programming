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

  ll n, x, pos;cin >> n >> x >> pos;
  vector<char> arr(n, 'u');
  arr[pos] = 'e';
  ll l = 0;
  ll r = n;
  while(l < r){
    ll mid = (l + r) / 2;
    if(mid <= pos){
      if(mid != pos)arr[mid] = 'l';
      l = mid + 1;
    }
    else{
      arr[mid] = 'g';
      r = mid;
    }
  }
  ll ans = 1;
  ll l_cnt = x - 1, g_cnt = n - x;
  ll le = count(arr.begin(), arr.end(), 'l');
  ll gr = count(arr.begin(), arr.end(), 'g');
  ll rem = count(arr.begin(), arr.end(), 'u');
  for(ll i = 0;i < le;i++){
    ans = ans * (l_cnt - i) % MOD;
  }
  for(ll i = 0;i < gr;i++){
    ans = ans * (g_cnt - i) % MOD;
  }
  for(ll i = rem;i >= 2;i--){
    ans = ans * i % MOD;
  }
  cout << ans << endl;
}
