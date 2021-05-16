#include<bits/stdc++.h>
using namespace std;
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

int q(int x, int y){
  cout << "? " << x << ' ' << y << endl;
  int p;cin >> p;
  return p;
}

int main(){
  int n;cin >> n;
  if(n == 1){
    cout << "! 1" << endl;
    return 0;
  }
  vector<int> ans(n + 1, -1);
  int cnt = 0;
  int fst = 1;
  int snd = 2;
  while(cnt != n){
    int go = q(fst, snd);
    int back = q(snd, fst);
    int mx = max(go, back);
    if(go == mx){
      ans[fst] = mx;
      while(fst < n && ans[fst] != -1)fst++;
      snd = fst + 1;
      while(snd < n && ans[snd] != -1)snd++;
    }
    else{
      ans[snd] = mx;
      while(snd < n && ans[snd] != -1)snd++;
    }
    if(fst > n || snd > n)break;
    cnt++;
  }
  cout << "! ";
  for(int i = 1;i <= n;i++){
    if(ans[i] == -1)ans[i] = n;
    cout << ans[i] << ' ';
  }
  cout << endl;
}
