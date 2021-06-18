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

const ll mxN = 2e5 + 10;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;cin >> n;
  vector<ll> arr(n);
  vector<vector<ll>> cnt(mxN);
  for(ll i = 0;i < n;i++)cin >> arr[i];
  for(ll i = 0;i < n;i++){
    ll num = arr[i];
    for(ll j = 2;j * j <= num;j++){
      ll c = 0;
      while(num % j == 0){
        num /= j;
        c++;
      }
      if(c)cnt[j].push_back(c);
    }
    if(num > 1)cnt[num].push_back(1);
  }
  ll ans = 1;
  for(ll i = 0;i < mxN;i++){
    if((ll)cnt[i].size() <= n - 2)continue;
    else if((ll)cnt[i].size() == n - 1){
      sort(cnt[i].begin(), cnt[i].end());
      ans *= pow(i, cnt[i][0]);
    }
    else if((ll)cnt[i].size() == n){
      sort(cnt[i].begin(), cnt[i].end());
      ans *= pow(i, cnt[i][1]);
    }
  }
  cout << ans << endl;
}
