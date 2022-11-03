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

int findMax(vector<set<int>> *adj) {
  int mx = 0;
  int mxi = -1;
  for (int i = 0;i < (*adj).size();i++) {
    if ((*adj)[i].size() > mx) {
      mx = (*adj)[i].size();
      mxi = i;
    }
  }
  return mxi;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;cin >> n >> m;
  vector<vector<int>> arr(n + 1, vector<int>(m + 1));
  vector<set<int>> adj(n + 1);
  for (int i = 0;i < n;i++) {
    for (int j = 0;j < m;j++) {
      cin >> arr[i][j];
    }
  }
  for (int i = 0;i < m;i++) {
    for (int j = 0;j < n - 1;j++) {
      for (int k = j + 1;k < n;k++) {
        if (arr[j][i] == -1 && arr[k][i] == 1 || arr[j][i] == 1 && arr[k][i] == -1) {
          adj[j].insert(k);
          adj[k].insert(j);
        }
      }
    }
  }

  int mxi = findMax(&adj);
  int ans = 0;
  while (mxi != -1) {
    ans++;
    for (auto e : adj[mxi]) {
      adj[e].erase(mxi);
    }
    adj[mxi] = set<int>();
    mxi = findMax(&adj);
  }
  cout << ans << endl;
}
