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

  int n, k;cin >> n >> k;
  priority_queue<int> q;
  vector<vector<int>> cell_cost(n, vector<int>(n, 0));
  vector<vector<int>> cost(2 * n + 2, vector<int>(n + 1, 0));
  for(int i = 0;i < n * 2 + 1;i++){
    if(i & 1){
      //up down border
      for(int j = 0;j < n + 1;j++){
        cin >> cost[i][j];
      }
    } else {
      for(int j = 0;j < n;j++){
        cin >> cost[i][j];
      }
    }
  }
  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      //up cost[i * 2][j]
      //down cost[(i + 1) * 2][j]
      //right cost[i * 2 + 1][j + 1]
      //left cost[i * 2 + 1][j]
      cell_cost[i][j] = 3 * cost[i * 2][j] - 3 * cost[(i + 1) * 2][j] -
        5 * cost[i * 2 + 1][j + 1] + 5 * cost[i * 2 + 1][j];
      q.push(-cell_cost[i][j]);
    }
  }
  int ans = 0;
  for(int i = 0;i < k;i++){
    int cur_cost = -q.top();
    q.pop();
    ans += cur_cost;
  }
  cout << ans << endl;
}
