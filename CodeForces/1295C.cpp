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

  int q;cin >> q;
  while(q--){
    string s, t;cin >> s >> t;
    int ns = s.length();
    int nt = t.length();
    vector<vector<int>> pos(ns, vector<int>(26, -1));
    for(int i = ns - 1;i >= 0;i--){
      int c = s[i] - 'a';
      pos[i][c] = i;
      if(i < ns - 1){
        for(int j = 0;j < 26;j++){
          if(j == c)continue;
          pos[i][j] = pos[i + 1][j];
        }
      }
    }
    int ans = 1, ptr = 0;
    bool valid = true;
    for(int i = 0;i < nt;i++){
      if(ptr == ns){
        ans++;
        ptr = 0;
      }
      int c = t[i] - 'a';
      ptr = pos[ptr][c];
      if(ptr == -1){
        ptr = pos[0][c]; 
        ans++;
        if(ptr == -1){
          valid = false;
          break;
        }
      }
      ptr++;
    }
    if(valid)cout << ans;
    else cout << -1;
    cout << endl;
  }
}
