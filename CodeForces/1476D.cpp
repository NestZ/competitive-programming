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
  while(t--){
    int n;cin >> n;
    string s;cin >> s;
    int len = s.length();
    //0 l
    //1 r
    vector<vector<int>> l(len, vector<int>(2)), r(len, vector<int>(2));
    for(int i = 0;i < len;i++){
      if(s[i] == 'L'){
        l[i][0] = 1;
        if(i - 1 >= 0)
          l[i][0] += l[i - 1][1];
      }
      else{
        l[i][1] = 1;
        if(i - 1 >= 0)
          l[i][1] += l[i - 1][0];
      }
    }
    for(int i = len - 1;i >= 0;i--){
      if(s[i] == 'R'){
        r[i][1] = 1;
        if(i + 1 <= len - 1)
          r[i][1] += r[i + 1][0];
      }
      else{
        r[i][0] = 1;
        if(i + 1 <= len - 1)
          r[i][0] += r[i + 1][1];
      }
    }
    for(int i = 0;i < n + 1;i++){
      int ans = 1;
      if(i <= n - 1)
        ans += r[i][1];
      if(i - 1 >= 0)
        ans += l[i - 1][0];
      cout << ans << ' ';
    }
    cout << endl;
  }
}
