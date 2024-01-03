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

vector<pair<int, int>> arr(300010);
string s;
int ans = INT_MAX;

void dfs(int cur, int cost) {
  if (arr[cur].first == 0 && arr[cur].second == 0) {
    ans = min(ans, cost);
  } else {
    char dir = s[cur - 1];
    if (arr[cur].first != 0) {
      int cur_cost = cost;
      if (dir != 'L') cur_cost++;
      dfs(arr[cur].first, cur_cost);
    }
    if (arr[cur].second != 0) {
      int cur_cost = cost;
      if (dir != 'R') cur_cost++;
      dfs(arr[cur].second, cur_cost);
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;cin >> t;
  while(t--) {
    ans = INT_MAX;
    int n;cin >> n;
    cin >> s;
    for (int i = 1;i <= n;i++) {
      int l, r;cin >> l >> r;
      arr[i] = {l, r};
    }
    dfs(1, 0);
    cout << ans << endl;
  }
}
