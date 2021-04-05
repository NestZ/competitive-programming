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

  int n;cin >> n;
  vector<pair<int, int>> arr;
  for(int i = 0;i < n;i++){
    int d;cin >> d;
    int mx = max(d, 24 - d);
    int mn = min(d, 24 - d);
    arr.push_back({mn, mx});
  }
  sort(arr.begin(), arr.end());
  int ans = INT_MAX;
  bool low = true;
  vector<int> tmp;
  tmp.push_back(0);
  for(int i = 0;i < n;i++){
    if(low)tmp.push_back(arr[i].first);
    else tmp.push_back(arr[i].second);
    low = !low;
  }
  for(int i = 0;i < n;i++){
    for(int j = i + 1;j <= n;j++){
      ans = min(ans, abs(tmp[i] - tmp[j]));
    }
  }
  cout << ans << endl;
}
