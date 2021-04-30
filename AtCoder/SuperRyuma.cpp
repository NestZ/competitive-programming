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

  int sx, sy;cin >> sx >> sy;
  int ex, ey;cin >> ex >> ey;
  if(sx == ex && sy == ey)cout << 0;
  else if(abs(sx - ex) + abs(sy - ey) <= 3)cout << 1;
  else if((sx + sy) % 2 == (ex + ey) % 2){
    if(sx + sy == ex + ey || sx - sy == ex - ey)cout << 1;
    else cout << 2;
  }
  else{
    if(abs((sx - sy) - (ex - ey)) <= 3 ||
        abs((sx + sy) - (ex + ey)) <= 3 ||
        abs(sx - ex) + abs(sy - ey) <= 6)cout << 2;
    else cout << 3;
  }
  cout << endl;
}
