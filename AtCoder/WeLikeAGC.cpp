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

  ll n;cin >> n;
  ll dp[n + 1][4][4][4] = {};
  dp[0][0][0][0] = 1;
  //T = 0, A = 1, G = 2, C = 3
  for(int i = 1;i <= n;i++){
    for(int b = 0;b < 4;b++){
      for(int j = 0;j < 4;j++){
        for(int k = 0;k < 4;k++){
          for(int l = 0;l < 4;l++){
            // (j, k, l, b)
            if(k == 2 && l == 1 && b == 3) continue; // GAC
            if(k == 1 && l == 3 && b == 2) continue; // ACG
            if(j == 1 && l == 2 && b == 3) continue; // A*GC
            if(j == 1 && k == 2 && b == 3) continue; // AG*C
            if(k == 1 && l == 2 && b == 3) continue; // AGC
            dp[i][k][l][b] += dp[i - 1][j][k][l];
            dp[i][k][l][b] %= MOD;
          }
        }
      }
    }
  }
  ll ans = 0;
  for(int i = 0;i < 4;i++){
    for(int j = 0;j < 4;j++){
      for(int k = 0;k < 4;k++){
        ans += dp[n][i][j][k];
        ans %= MOD;
      }
    }
  }
  cout << ans << endl;
}
