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

  int d, g;cin >> d >> g;
  int ans = INT_MAX;
  vector<pair<int, int>> arr;
  for(int i = 0;i < d;i++){
    int p, c;cin >> p >> c;
    arr.push_back({p, c});
  }
  for(int i = 0;i < (1 << d);i++){
    int point = 0;
    int cnt = 0;
    vector<bool> used(d, false);
    for(int j = 0;j < d;j++){
      if((1 << j) & i){
        point += arr[j].first * 100 * (j + 1) + arr[j].second;
        cnt += arr[j].first;
        used[j] = true;
      }
    }
    if(point >= g)ans = min(ans, cnt);
    else{
      int want = g - point;
      for(int j = d - 1;j >= 0;j--){
        if(used[j])continue;
        int cur_point = 100 * (j + 1);
        int div = (want + cur_point - 1) / cur_point;
        div = min(div, arr[j].first - 1);
        want -= div * cur_point;
        cnt += div;
        if(want <= 0){
          ans = min(ans, cnt);
          break;
        }
      }
    }
  }
  cout << ans << endl;
}
