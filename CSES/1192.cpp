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

vector<vector<bool>> vis(1010, vector<bool>(1010, false));
int n, m;
//up down left right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool valid(int x, int y){
  if(x < 0 || y < 0 || x >= n || y >= m)return false;
  return true;
}

void dfs(int x, int y){
  vis[x][y] = true;
  for(int i = 0;i < 4;i++){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(!valid(nx, ny) || vis[nx][ny])continue;
    dfs(nx, ny);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  int ans = 0;
  for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
      char c;cin >> c;
      if(c == '#')vis[i][j] = true;
    }
  }
  for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
      if(vis[i][j])continue;
      ans++;
      dfs(i, j);
    }
  }
  cout << ans << endl;
}
