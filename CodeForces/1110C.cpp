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
    int tmp = n;
    bool valid = false;
    while(tmp > 0){
      if(!(tmp & 1))valid = true;
      tmp >>= 1;
    }
    if(!valid){
      int ans = 0;
      for(int i = 1;i * i <= n;i++){
        if(n % i == 0){
          int fst = i;
          int snd = n / i;
          if(fst < n)ans = max(ans, fst);
          if(snd < n)ans = max(ans, snd);
        }
      }
      cout << ans;
    }
    else{
      int cur = 1;
      while(cur <= n)cur <<= 1;
      cout << cur - 1;
    }
    cout << endl;
  }
}
