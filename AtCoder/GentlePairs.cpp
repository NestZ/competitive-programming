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
    int x, y;cin >> x >> y;
    arr.push_back({x, y});
  }
  int ans = 0;
  for(int i = 0;i < n - 1;i++){
    for(int j = i + 1;j < n;j++){
      int x1 = arr[i].first;
      int y1 = arr[i].second;
      int x2 = arr[j].first;
      int y2 = arr[j].second;
      double slope = double(y2 - y1) / double(x2 - x1);
      if(slope <= 1 && slope >= -1)ans++;
    }
  }
  cout << ans << endl;
}
