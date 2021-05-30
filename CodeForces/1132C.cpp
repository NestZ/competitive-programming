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

  int n, q;cin >> n >> q;
  vector<pair<int, int>> arr;
  vector<int> f(n + 2), pre1(n + 1), pre2(n + 1);
  for(int i = 0;i < q;i++){
    int l, r;cin >> l >> r;
    arr.push_back({l, r});
    f[l]++;
    f[r + 1]--;
  }
  int ans = 0;
  for(int i = 1;i <= n;i++){
    f[i] += f[i - 1];
    if(f[i])ans++;
    if(f[i] == 2)pre2[i]++;
    if(f[i] == 1)pre1[i]++;
    pre1[i] += pre1[i - 1];
    pre2[i] += pre2[i - 1];
  }
  int mn_l = INT_MAX;
  for(int i = 0;i < q - 1;i++){
    for(int j = i + 1;j < q;j++){
      int cur_l = 0;
      auto p1 = arr[i];
      auto p2 = arr[j];
      if(p2.first < p1.first)swap(p1, p2);
      int l1 = p1.first, r1 = p1.second;
      int l2 = p2.first, r2 = p2.second;
      int inter_l = max(l1, l2);
      int inter_r = min(r1, r2);
      if(inter_r >= inter_l)
        cur_l += pre2[inter_r] - pre2[inter_l - 1];
      int l = l1, r = min(r1, l2 - 1);
      if(r >= l)cur_l += pre1[r] - pre1[l - 1];
      l = 0, r = max(r1, r2);
      if(r1 >= r2)l = r2 + 1;
      else l = max(l2, r1 + 1);
      if(r >= l)cur_l += pre1[r] - pre1[l - 1];
      mn_l = min(mn_l, cur_l);
    }
  }
  cout << ans - mn_l << endl;
}
