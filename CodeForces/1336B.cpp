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
 
ll diff(ll r, ll g, ll b){
  ll fst = abs(r - g);
  ll snd = abs(r - b);
  ll trd = abs(g - b);
  return fst * fst + snd * snd + trd * trd;
}
 
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;cin >> t;
  while(t--){
    ll nr, ng, nb;cin >> nr >> ng >> nb;
    vector<ll> r(nr), g(ng), b(nb);
    for(ll i = 0;i < nr;i++)cin >> r[i];
    for(ll i = 0;i < ng;i++)cin >> g[i];
    for(ll i = 0;i < nb;i++)cin >> b[i];
    vector<pair<ll, ll>> arr;
    for(ll i = 0;i < nr;i++){
      arr.push_back({r[i], 0});
    }
    for(ll i = 0;i < ng;i++){
      arr.push_back({g[i], 1});
    }
    for(ll i = 0;i < nb;i++){
      arr.push_back({b[i], 2});
    }
    sort(arr.begin(), arr.end());
    ll len = arr.size(), ans = LLONG_MAX;
    vector<ll> pre0(len, -1), pre1(len, -1), pre2(len, -1);
    vector<ll> suf0(len, -1), suf1(len, -1), suf2(len, -1);
    for(ll i = 0;i < len;i++){
      if(arr[i].second == 0){
        pre0[i] = i;
        if(i > 0){
          pre1[i] = pre1[i - 1];
          pre2[i] = pre2[i - 1];
        }
      }
      else if(arr[i].second == 1){
        pre1[i] = i;
        if(i > 0){
          pre0[i] = pre0[i - 1];
          pre2[i] = pre2[i - 1];
        }
      }
      else if(arr[i].second == 2){
        pre2[i] = i;
        if(i > 0){
          pre0[i] = pre0[i - 1];
          pre1[i] = pre1[i - 1];
        }
      }
    }
    for(ll i = len - 1;i >= 0;i--){
      if(arr[i].second == 0){
        suf0[i] = i;
        if(i < len - 1){
          suf1[i] = suf1[i + 1];
          suf2[i] = suf2[i + 1];
        }
      }
      else if(arr[i].second == 1){
        suf1[i] = i;
        if(i < len - 1){
          suf0[i] = suf0[i + 1];
          suf2[i] = suf2[i + 1];
        }
      }
      else if(arr[i].second == 2){
        suf2[i] = i;
        if(i < len - 1){
          suf0[i] = suf0[i + 1];
          suf1[i] = suf1[i + 1];
        }
      }
    }
    for(ll i = 1;i < len - 1;i++){
      ll fst = -1, snd = arr[i].first, trd = -1;
      if(arr[i].second == 0){
        //12
        if(pre1[i - 1] != -1 && suf2[i + 1] != -1){
          fst = arr[pre1[i - 1]].first;
          trd = arr[suf2[i + 1]].first;
          ans = min(ans, diff(fst, snd, trd));
        }
        //21
        if(pre2[i - 1] != -1 && suf1[i + 1] != -1){
          fst = arr[pre2[i - 1]].first;
          trd = arr[suf1[i + 1]].first;
          ans = min(ans, diff(fst, snd, trd));
        }
      }
      else if(arr[i].second == 1){
        //02
        if(pre0[i - 1] != -1 && suf2[i + 1] != -1){
          fst = arr[pre0[i - 1]].first;
          trd = arr[suf2[i + 1]].first;
          ans = min(ans, diff(fst, snd, trd));
        }
        //20
        if(pre2[i - 1] != -1 && suf0[i + 1] != -1){
          fst = arr[pre2[i - 1]].first;
          trd = arr[suf0[i + 1]].first;
          ans = min(ans, diff(fst, snd, trd));
        }
      }
      else if(arr[i].second == 2){
        //01
        if(pre0[i - 1] != -1 && suf1[i + 1] != -1){
          fst = arr[pre0[i - 1]].first;
          trd = arr[suf1[i + 1]].first;
          ans = min(ans, diff(fst, snd, trd));
        }
        //10
        if(pre1[i - 1] != -1 && suf0[i + 1] != -1){
          fst = arr[pre1[i - 1]].first;
          trd = arr[suf0[i + 1]].first;
          ans = min(ans, diff(fst, snd, trd));
        }
      }
      else assert(false);
    }
    cout << ans << endl;
  }
}
