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
    vector<ll> at(n + 1);
    vector<ll> s(n + 1);
    vector<vector<ll>> u(n + 1);
    vector<ll> ans(n + 1);
    vector<bool> have(n + 1, false);
    ll sum_u = 0;
    for(ll i = 1;i <= n;i++)cin >> at[i];
    for(ll i = 1;i <= n;i++)cin >> s[i];
    for(ll i = 1;i <= n;i++){
      u[at[i]].push_back(s[i]);
      sum_u += s[i];
    }
    for(ll i = 1;i <= n;i++){
      ll uz = u[i].size();
      if(uz){
        sort(u[i].begin(), u[i].end());
        vector<ll> pre(uz + 1);
        for(ll j = 0;j < uz;j++){
          pre[j + 1] += u[i][j] + pre[j];
        }
        for(ll j = 1;j <= n;j++){
          if(j > uz)break;
          ll out = uz % j;
          have[j] = true;
          ans[j] += pre[uz] - pre[out];
        }
      }
    }
    for(ll i = 1;i <= n;i++){
      cout << ans[i] << ' ';
    }
    cout << endl;
  }
}
