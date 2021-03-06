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
    ll n, k;cin >> n >> k;
    if(n < 62 && k > (1ll << (n - 1))){
      cout << -1 << endl;
      continue;
    }
    k--;
    string s;
    for(ll i = 0;i < n;i++)
      s += '0';
    for(ll b = 0;b < min(60ll, (n - 1));b++){
      if((k >> b) & 1)
        s[n - 2 - b] = '1';
    }
    ll cnt = 1;
    ll cur = 1;
    vector<ll> ans;
    for(char i : s){
      if(i == '0'){
        for(ll j = cur + cnt - 1;j >= cur;j--)
          ans.push_back(j);
        cur += cnt;
        cnt = 1;
      }
      else cnt++;
    }
    for(ll i : ans)cout << i << ' ';
    cout << endl;
  }
}
