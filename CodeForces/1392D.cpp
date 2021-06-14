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
    int ans = 0, cnt = 0;
    while(s.size() && s[0] == s.back()){
      cnt++;
      s.pop_back();
    }
    if(s.empty()){
      if(cnt <= 2)cout << 0;
      else if(cnt == 3)cout << 1;
      else cout << (cnt + 2) / 3;
      cout << endl;
      continue;
    }
    s.push_back('$');
    for(int i = 0;i < (int)s.size() - 1;i++){
      cnt++;
      if(s[i] != s[i + 1]){
        ans += cnt / 3;
        cnt = 0;
      }
    }
    cout << ans << endl;
  }
}
