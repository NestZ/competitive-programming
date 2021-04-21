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

  int n;cin >> n;
  int ans = 0;
  string s;cin >> s;
  vector<vector<int>> cnt(n + 1, vector<int>(4));
  map<char, int> m;
  m['A'] = 0; m['T'] = 1; m['G'] = 2; m['C'] = 3;
  //ATGC
  for(int i = 0;i < n;i++){
    cnt[i + 1][m[s[i]]]++;
    for(int j = 0;j < 4;j++){
      cnt[i + 1][j] += cnt[i][j];
    }
  }
  for(int i = 1;i <= n;i++){
    for(int j = i;j <= n;j++){
      int a = cnt[j][0] - cnt[i - 1][0];
      int t = cnt[j][1] - cnt[i - 1][1];
      int g = cnt[j][2] - cnt[i - 1][2];
      int c = cnt[j][3] - cnt[i - 1][3];
      bool valid = true;
      if(a > 0 || t > 0){
        if(a != t)valid = false;
      }
      if(g > 0 || c > 0){
        if(g != c)valid = false;
      }
      if(valid)ans++;
    }
  }
  cout << ans << endl;
}
