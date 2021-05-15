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
    vector<int> win(n + 1), lost(n + 1);
    int want = (n - 1) / 2;
    for(int i = 1;i < n;i++){
      for(int j = i + 1;j <= n;j++){
        if(n % 2 == 0 && i + 1 == j && i % 2 == 1)cout << 0 << ' ';
        else{
          if(win[i] < want && lost[j] < want){
            cout << 1 << ' ';
            win[i]++;
            lost[j]++;
          }
          else if(win[j] < want && lost[i] < want){
            cout << -1 << ' ';
            win[j]++;
            lost[i]++;
          }
          else assert(false);
        }
      }
    }
    cout << endl;
  }
}
