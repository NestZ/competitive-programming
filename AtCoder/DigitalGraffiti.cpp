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

  int h, w;cin >> h >> w;
  vector<vector<char>> arr(h, vector<char>(w));
  vector<vector<bool>> is_u(h, vector<bool>(w, false));
  vector<vector<bool>> is_d(h, vector<bool>(w, false));
  vector<vector<bool>> is_l(h, vector<bool>(w, false));
  vector<vector<bool>> is_r(h, vector<bool>(w, false));
  for(int i = 0;i < h;i++)
    for(int j = 0;j < w;j++)
      cin >> arr[i][j];
  int hor = 0, ver = 0;
  for(int i = 0;i < h;i++){
    for(int j = 0;j < w;j++){
      if(arr[i][j] == '#'){
        if(arr[i - 1][j] == '.'){
          is_u[i][j] = true;
          if(!is_u[i][j - 1])hor++;
        }
        if(arr[i + 1][j] == '.'){
          is_d[i][j] = true;
          if(!is_d[i][j - 1])hor++;
        }
      }
    }
  }
  for(int i = 0;i < w;i++){
    for(int j = 0;j < h;j++){
      if(arr[j][i] == '#'){
        if(arr[j][i - 1] == '.'){
          is_l[j][i] = true;
          if(!is_l[j - 1][i])ver++;
        }
        if(arr[j][i + 1] == '.'){
          is_r[j][i] = true;
          if(!is_r[j - 1][i])ver++;
        }
      }
    }
  }
  debug() << imie(hor) imie(ver);
  cout << hor + ver << endl;
}
