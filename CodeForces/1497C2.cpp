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
    int n, k;cin >> n >> k;
    vector<int> ans(k, 1);
    for(int i = 3;i < k;i++)ans[i] = 1;
    n = n - (k - 3);
    k = 3;
    if(n % 2 == 0){
      if(n % 4 == 0){
        ans[0] = n / 2;
        ans[1] = ans[2] = n / 4;
      }
      else{
        ans[0] = 2;
        ans[1] = ans[2] = (n - 2) / 2;
      }
    }
    else{
      ans[0] = ans[1] = n / 2;
      ans[2] = 1;
    }
    for(int i : ans)cout << i << ' ';
    cout << endl;
  }
}
