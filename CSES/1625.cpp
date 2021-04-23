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

vector<char> cur(50, '$');
vector<vector<bool>> vis(10, vector<bool>(10, false));
string p;
int ans = 0;
int cnt = 0;
int way = 0;
int call = 0;
//up down left right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void fuck(int r, int c){
  //++call;
  ++cnt;
  vis[r][c] = true;
  //too far to reach end point
  int rem = 49 - cnt;
  int diff = 6 - r + c;
  if(diff <= rem){
    if(cnt == 49){
      if(r == 7 && c == 1){
        //way++;
        bool same = true;
        for(int i = 0;i < 48;++i){
          if(p[i] == '?')continue;
          if(p[i] != cur[i])
            same = false;
        }
        if(same)++ans;
      }
    }
    else{
      for(int i = 0;i < 4;++i){
        int nx = r + dx[i];
        int ny = c + dy[i];
        if(nx < 1 || ny < 1 || nx > 7 || ny > 7)continue;
        if(vis[nx][ny])continue;
        //purne lr
        if(ny > 1 && ny < 7 && (nx == 1 || nx == 7) &&
            (!vis[nx][ny - 1] && !vis[nx][ny + 1])){
          continue;
        }
        //purne ud
        if(nx > 1 && nx < 7 && (ny == 1 || ny == 7) &&
            (!vis[nx + 1][ny] && !vis[nx - 1][ny])){
          continue;
        }
        //purne tail
        if(nx > 1 && nx < 7 && ny > 1 && ny < 7){
          //lr
          if(vis[nx + 1][ny] && vis[nx - 1][ny] &&
              !vis[nx][ny - 1] && !vis[nx][ny + 1])
            continue;
          //ud
          if(vis[nx][ny + 1] && vis[nx][ny - 1] &&
            !vis[nx - 1][ny] && !vis[nx + 1][ny])
            continue;
        }
        //reach before end
        if(nx == 7 && ny == 1){
          if(cnt + 1 != 49)continue;
        }
        if(i == 0)cur[cnt - 1] = 'U';
        else if(i == 1)cur[cnt - 1] = 'D';
        else if(i == 2)cur[cnt - 1] = 'L';
        else cur[cnt - 1] = 'R';
        fuck(nx, ny);
      }
    }
  }
  --cnt;
  vis[r][c] = false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> p;
  fuck(1, 1);
  cout << ans << endl;
}
