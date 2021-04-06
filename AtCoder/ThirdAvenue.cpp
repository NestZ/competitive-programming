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

//up down left right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int h, w;

bool valid(int x, int y){
  if(x < 0 || y < 0 || x >= h || y >= w)return false;
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> h >> w;
  int ans = INT_MAX;
  vector<vector<pair<int, int>>> portal(26);
  vector<vector<char>> arr(h, vector<char>(w));
  vector<vector<bool>> vis(h, vector<bool>(w, false));
  queue<tuple<int, int, int>> q;
  for(int i = 0;i < h;i++){
    for(int j = 0;j < w;j++){
      cin >> arr[i][j];
      if(arr[i][j] == 'S'){
        q.push({i, j, 0});
        vis[i][j] = true;
      }
      if(arr[i][j] >= 'a' && arr[i][j] <= 'z'){
        portal[arr[i][j] - 'a'].push_back({i, j});
      }
    }
  }
  while(!q.empty()){
    auto cur = q.front(); q.pop();
    int cx = get<0>(cur);
    int cy = get<1>(cur);
    int cd = get<2>(cur);
    if(arr[cx][cy] == 'G'){
      ans = cd;
      break;
    }
    if(arr[cx][cy] >= 'a' && arr[cx][cy] <= 'z'){
      for(auto warp : portal[arr[cx][cy] - 'a']){
        int fst = warp.first;
        int snd = warp.second;
        if(vis[fst][snd])continue;
        q.push({fst, snd, cd + 1});
        vis[fst][snd] = true;
      }
    }
    for(int i = 0;i < 4;i++){
      int nx = cx + dx[i];
      int ny = cy + dy[i];
      if(valid(nx, ny) && arr[nx][ny] != '#' && !vis[nx][ny]){
        vis[nx][ny] = true;
        q.push({nx, ny, cd + 1});
      }
    }
  }
  if(ans == INT_MAX)cout << -1;
  else cout << ans;
  cout << endl;
}
