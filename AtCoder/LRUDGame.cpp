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

  int h, w, n;cin >> h >> w >> n;
  int sr, sc;cin >> sr >> sc;
  string s, t;cin >> s >> t;
  int tu = 0, td = 0, tr = 0, tl = 0;
  bool ans = true;
  for(int i = 0;i < n;i++){
    if(s[i] == 'L')tl++;
    else if(s[i] == 'R')tr++;
    else if(s[i] == 'U')tu++;
    else td++;
    //try to move to rlud
    if(sc + tr > w)ans = false;
    if(sc - tl < 1)ans = false;
    if(sr - tu < 1)ans = false;
    if(sr + td > h)ans = false;
    if(t[i] == 'L')tr = max(tr - 1, -(sc - 1));
    else if(t[i] == 'R')tl = max(tl - 1, -(w - sc));
    else if(t[i] == 'U')td = max(td - 1, -(sr - 1));
    else tu = max(tu - 1, -(h - sr));
  }
  if(ans)cout << "YES";
  else cout << "NO";
  cout << endl;
}
