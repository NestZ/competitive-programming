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

  int n, m, q;cin >> n >> m >> q;
  vector<pair<int, int>> bag;
  vector<int> box(m);
  for(int i = 0;i < n;i++){
    int w, v;cin >> w >> v;
    bag.push_back({v, w});
  }
  for(int i = 0;i < m;i++)cin >> box[i];
  sort(bag.rbegin(), bag.rend());
  for(int i = 0;i < q;i++){
    vector<int> match(m, -1);
    int l, r;cin >> l >> r;
    l--; r--;
    for(int j = 0;j < n;j++){
      int best = -1;
      int mn = INT_MAX;
      for(int k = 0;k < m;k++){
        if(k >= l && k <= r)continue;
        if(match[k] != -1)continue;
        if(bag[j].second > box[k])continue;
        if(box[k] < mn){
          mn = box[k];
          best = k;
        }
      }
      if(best != -1)match[best] = j;
    }
    int ans = 0;
    for(int j = 0;j < m;j++){
      if(match[j] == -1)continue;
      ans += bag[match[j]].first;
    }
    cout << ans << endl;
  }
}
