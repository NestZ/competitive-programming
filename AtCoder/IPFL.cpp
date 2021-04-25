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
  string s;cin >> s;
  int q;cin >> q;
  bool flip = false;
  for(int i = 0;i < q;i++){
    int t, a, b;cin >> t >> a >> b;
    if(t == 1){
      if(flip){
        if(a > n)a -= n;
        else if(a <= n)a += n;
        if(b > n)b -= n;
        else if(b <= n)b += n;
      }
      swap(s[a - 1], s[b - 1]);
    } else flip = !flip;
  }
  if(flip){
    for(int i = n;i < 2 * n;i++)cout << s[i];
    for(int i = 0;i < n;i++)cout << s[i];
  }
  else cout << s;
  cout << endl;
}
