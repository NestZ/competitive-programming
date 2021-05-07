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

ll dp[2][20][11][2] = {};

ll fuckUp(bool mx, string num, ll idx, ll lst, bool one){
  ll s1 = (mx ? 1 : 0), s2 = idx, s3 = lst, s4 = (one ? 1 : 0);
  if(dp[s1][s2][s3][s4] != -1)
    return dp[s1][s2][s3][s4];
  if(idx >= (ll)num.length()){
    return dp[s1][s2][s3][s4] = 1;
  }
  ll res = 0;
  ll k = 9;
  if(mx)k = num[idx] - '0';
  for(ll i = 0;i <= k;i++){
    if(i == lst){
      if(one)continue;
      else if(i != 0)continue;
    }
    bool nw = mx && (i == num[idx] - '0');
    res += fuckUp(nw, num, idx + 1, i, (i > 0) || one);
  }
  return dp[s1][s2][s3][s4] = res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll a, b;cin >> a >> b;
  for(ll i = 0;i < 2;i++)
    for(ll j = 0;j < 20;j++)
      for(ll k = 0;k < 11;k++)
        for(ll l = 0;l < 2;l++)
          dp[i][j][k][l] = -1;
  ll fb = fuckUp(true, to_string(b), 0, 10, false);
  for(ll i = 0;i < 2;i++)
    for(ll j = 0;j < 20;j++)
      for(ll k = 0;k < 11;k++)
        for(ll l = 0;l < 2;l++)
          dp[i][j][k][l] = -1;
  ll fa = 0;
  if(a > 0)
    fa = fuckUp(true, to_string(a - 1), 0, 10, false);
  cout << fb - fa << endl;
}
