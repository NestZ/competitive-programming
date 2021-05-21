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
    map<pair<int, int>, int> lst;
    int x = 0, y = 0;
    int b = -1, e = -1;
    int mn_d = 1e9;
    lst[make_pair(0, 0)] = 0;
    for(int i = 0;i < n;i++){
      if(s[i] == 'L')y--;
      else if(s[i] == 'R')y++;
      else if(s[i] == 'U')x--;
      else x++;
      auto p = make_pair(x, y);
      if(!lst.count(p))lst[p] = i + 1;
      else{
        if(i - lst[p] + 1 < mn_d){
          mn_d = i - lst[p] + 1;
          b = lst[p] + 1;
          e = i + 1;
        }
        lst[p] = i + 1;
      }
    }
    if(b == -1)cout << -1;
    else cout << b << ' ' << e;
    cout << endl;
  }
}
