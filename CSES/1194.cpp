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
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
vector<vector<char>> arr(1010, vector<char>(1010));
vector<vector<char>> from(1010, vector<char>(1010));
vector<vector<pair<int, int>>> lst(1010, vector<pair<int, int>>(1010));
vector<vector<bool>> vis(1010, vector<bool>(1010));
vector<vector<int>> mon(1010, vector<int>(1010, INT_MAX));

bool valid(int x, int y){
  if(x < 0 || y < 0 || x >= n || y >= m)return false;
  if(arr[x][y] == '#')return false;
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  int sx = 0, sy = 0;
  queue<pair<pair<int, int>, int>> q;
  for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
      cin >> arr[i][j];
      if(arr[i][j] == 'A'){
        sx = i; sy = j;
      }
      if(arr[i][j] == 'M'){
        q.push({{i, j}, 0});
        vis[i][j] = true;
      }
    }
  }
  while(!q.empty()){
    auto cur = q.front().first;
    int x = cur.first;
    int y = cur.second;
    int d = q.front().second;
    q.pop();
    mon[x][y] = d;
    for(int i = 0;i < 4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(!valid(nx, ny) || vis[nx][ny])continue;
      vis[nx][ny] = true;
      q.push({{nx, ny}, d + 1});
    }
  }
  for(int i = 0;i < n;i++)
    for(int j = 0;j < m;j++)
      vis[i][j] = false;
  q.push({{sx, sy}, 0});
  vis[sx][sy] = true;
  while(!q.empty()){
    auto cur = q.front().first;
    int x = cur.first;
    int y = cur.second;
    int d = q.front().second;
    q.pop();
    if(x == 0 || x == n - 1 || y == 0 || y == m - 1){
      vector<char> path;
      cout << "YES" << endl << d << endl;
      while(x != sx || y != sy){
        path.push_back(from[x][y]);
        int nx = lst[x][y].first;
        int ny = lst[x][y].second;
        x = nx; y = ny;
      }
      reverse(path.begin(), path.end());
      for(char c : path)cout << c;
      cout << endl;
      return 0;
    }
    for(int i = 0;i < 4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(!valid(nx, ny) || vis[nx][ny])continue;
      if(d + 1 >= mon[nx][ny])continue;
      vis[nx][ny] = true;
      q.push({{nx, ny}, d + 1});
      if(i == 0)from[nx][ny] = 'U';
      else if(i == 1)from[nx][ny] = 'D';
      else if(i == 2)from[nx][ny] = 'L';
      else from[nx][ny] = 'R';
      lst[nx][ny] = cur;
    }
  }
  cout << "NO\n";
}
