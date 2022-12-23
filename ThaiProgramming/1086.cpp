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

  int n, k, a;cin >> n >> k >> a;
  vector<int> tmp;
  for (int i = 0;i < n;i++) {
    int cnt;cin >> cnt;
    for (int j = 0;j < cnt;j++) {
      tmp.push_back(i);
    }
  }
  vector<int> cnt(tmp.size());
  vector<set<int>> ans(a);
  int real_ans = 0;
  for (int i = 0;i < tmp.size();i++) {
    ans[i % a].insert(tmp[i]);
    cnt[i] = ans[i % a].size();
  }
  int mx = 0;
  for (int i = 0;i < tmp.size();i++) {
    if (i + (k - 1) * a >= tmp.size()) {
      break;
    }
    int cur = cnt[i + (k - 1) * a] - cnt[i] + 1;
    if (cur > mx) {
      mx = cur;
      real_ans = i;
    }
  }
  cout << real_ans + 1 << ' ' << mx << endl;
}
