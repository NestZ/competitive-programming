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
  vector<ll> arr(n + 1);
  vector<vector<ll>> dp_fst(n + 1, vector<ll>(n + 1, INT64_MIN));
  vector<vector<ll>> dp_snd(n + 1, vector<ll>(n + 1, INT64_MIN)); 
  for(ll i = 1;i <= n;i++)cin >> arr[i];
  for(ll i = 1;i <= n;i++){
    dp_fst[i][i] = arr[i];
    dp_snd[i][i] = 0;
  }
  for(ll len = 1;len <= n;len++){
    for(ll i = 1;i <= n - len + 1;i++){
      ll s = i, e = i + len - 1;
      if(s == e)continue;
      //fst turn
      dp_fst[s][e] = max(arr[s] + dp_snd[s + 1][e],
          arr[e] + dp_snd[s][e - 1]); 
      //snd turn
      dp_snd[s][e] = min(dp_fst[s + 1][e], dp_fst[s][e - 1]);
    }
  }
  cout << dp_fst[1][n] << endl;
}
