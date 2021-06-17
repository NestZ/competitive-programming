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
//u d l r
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool valid(int i, int j, vector<vector<char>> &arr){
  if(i < 0 || j < 0 || i >= n || j >= m)return false;
  if(arr[i][j] != '.')return false;
  return true;
}

bool can_go(int i, int j, vector<vector<char>> &arr){
  if(i < 0 || j < 0 || i >= n || j >= m)return false;
  if(arr[i][j] == '#')return false;
  return true;
}

void block(int x, int y, vector<vector<char>> &arr){
  for(int i = 0;i < 4;i++){
    if(valid(x + dx[i], y + dy[i], arr))
      arr[x + dx[i]][y + dy[i]] = '#';
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;cin >> t;
  while(t--){
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    for(int i = 0;i < n;i++)
      for(int j = 0;j < m;j++)
        cin >> arr[i][j];
    for(int i = 0;i < n;i++){
      for(int j = 0;j < m;j++){
        if(arr[i][j] == 'B')
          block(i, j, arr);
      }
    }
    bool ans = true;
    vector<vector<bool>> vis(n, vector<bool>(m));
    for(int i = 0;i < n;i++){
      for(int j = 0;j < m;j++){
        if(arr[i][j] == 'G' || arr[i][j] == 'B'){
          if(vis[i][j])continue;
          int cnt_g = 0, cnt_b = 0;
          queue<pair<int, int>> q;
          q.push({i, j});
          vis[i][j] = true;
          bool found = false;
          while(!q.empty()){
            auto cur = q.front(); q.pop();
            int cx = cur.first;
            int cy = cur.second;
            if(arr[cx][cy] == 'G')cnt_g++;
            else if(arr[cx][cy] == 'B')cnt_b++;
            if(cx == n - 1 && cy == m - 1)
              found = true;
            for(int k = 0;k < 4;k++){
              int nx = cx + dx[k];
              int ny = cy + dy[k];
              if(can_go(nx, ny, arr) && !vis[nx][ny]){
                vis[nx][ny] = true;
                q.push({nx, ny});
              }
            }
          }
          if(!found && arr[i][j] == 'G')ans = false;
          if(found && arr[i][j] == 'B')ans = false;
          if(arr[i][j] == 'G' && cnt_b > 0)ans = false;
          if(arr[i][j] == 'B' && cnt_g > 0)ans = false;
        }
      }
    }
    if(ans)cout << "Yes";
    else cout << "No";
    cout << endl;
  }
}
