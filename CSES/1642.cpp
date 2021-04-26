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

  ll n, x;cin >> n >> x;
  vector<pair<ll, pair<ll, ll>>> com;
  vector<ll> arr(n);
  for(int i = 0;i < n;i++)cin >> arr[i];
  for(int i = 0;i < n - 1;i++){
    for(int j = i + 1;j < n;j++){
      auto p = make_pair(arr[i] + arr[j], make_pair(i, j));
      com.push_back(p);
    }
  }
  sort(com.begin(), com.end());
  for(int i = 0;i < n - 1;i++){
    for(int j = i + 1;j < n;j++){
      ll want = x - (arr[i] + arr[j]);
      if(want <= 0)continue;
      ll l = 0, r = com.size() - 1;
      ll best = INT64_MAX;
      while(l <= r){
        ll mid = l + (r - l) / 2;
        if(com[mid].first >= want){
          r = mid - 1;
          best = mid;
        }
        else l = mid + 1;
      }
      if(best == INT64_MAX)continue;
      for(int k = best;k < (int)com.size() && com[k].first == want;k++){
        ll fst = com[k].second.first;
        ll snd = com[k].second.second;
        if(fst != i && snd != j && fst != j && snd != i){
          cout << fst + 1 << ' ' << snd + 1 << ' ' << i + 1 << ' ' << j + 1 << endl;
          return 0;
        }
      }
    }
  }
  cout << "IMPOSSIBLE\n";
}
