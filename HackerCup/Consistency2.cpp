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

  int t;cin >> t;
  for(int q = 0;q < t;q++){
    string s;cin >> s;
    int e;cin >> e;
    int n = s.length();
    int ans = 1e9;
    vector<vector<int>> dist(30, vector<int>(30, 1e9));
    for(int i = 0;i < 30;i++)
      dist[i][i] = 0;
    for(int i = 0;i < e;i++){
      string r;cin >> r;
      assert(r.length() == 2);
      int fst = r[0] - 'A';
      int snd = r[1] - 'A';
      dist[fst][snd] = 1;
    }
    for(int k = 0;k < 30;k++){
      for(int i = 0;i < 30;i++){
        for(int j = 0;j < 30;j++){
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
    for(char c = 'A';c <= 'Z';c++){
      int cnt = 0;
      for(int i = 0;i < n;i++){
        int fst = s[i] - 'A';
        int snd = c - 'A';
        if(dist[fst][snd] == 1e9){
          cnt = 1e9;
          break;
        }
        cnt += dist[fst][snd];
      }
      ans = min(ans, cnt);
    }
    if(ans == 1e9)ans = -1;
    cout << "Case #" << q + 1 << ": " << ans << endl;
  }
}
