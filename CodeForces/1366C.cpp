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

int n, m;

bool valid(int x, int y){
  if(x <= 0 || y <= 0 || x > n || y > m)return false;
  return true;
}

void bfs(vector<vector<int>> &arr, vector<int> &cnt0,
    vector<int> &cnt1, int sx, int sy, bool flip){
  vector<vector<bool>> vis(40, vector<bool>(40, false));
  queue<pair<pair<int, int>, int>> q;
  vis[sx][sy] = true;
  q.push({{sx, sy}, 1});
  while(!q.empty()){
    auto cur = q.front(); q.pop();
    int cx = cur.first.first;
    int cy = cur.first.second;
    int d = cur.second;
    if(arr[cx][cy] == 1)cnt1[d]++;
    else cnt0[d]++;
    int nx = cx;
    int ny = cy + (flip ? -1 : 1);
    if(valid(nx, ny) && !vis[nx][ny]){
      q.push({{nx, ny}, d + 1});
      vis[nx][ny] = true;
    }
    nx = cx + (flip ? -1 : 1);
    ny = cy;
    if(valid(nx, ny) && !vis[nx][ny]){
      q.push({{nx, ny}, d + 1});
      vis[nx][ny] = true;
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;cin >> t;
  while(t--){
    cin >> n >> m;
    vector<vector<int>> arr(n + 1, vector<int>(m + 1));
    vector<int> cnt0(n + m), cnt1(n + m);
    for(int i = 1;i <= n;i++)
      for(int j = 1;j <= m;j++)
        cin >> arr[i][j];
    bfs(arr, cnt0, cnt1, 1, 1, false);
    bfs(arr, cnt0, cnt1, n, m, true);
    int ans = 0;
    int c = (n + m - 1) / 2;
    for(int i = 1;i <= c;i++){
      ans += min(cnt0[i], cnt1[i]);
    }
    cout << ans << endl;
  }
}
