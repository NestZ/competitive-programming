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

  int a, b; cin >> a >> b;
  int n = 100;
  int cmx = 1, cmn = 1;
  char mn = '#', mx = '.';
  if(a < b)swap(mn, mx);
  vector<vector<char>> arr(n, vector<char>(n, mx));
  for(int i = 0;i < n;i++)arr[0][i] = mn;
  for(int i = 0;i < n - 1;i++){
    for(int j = 1;j < n;j += 2){
      arr[i][j] = mn;
    }
  }
  for(int i = 0;i < n;i += 2){
    for(int j = 2;j < n && cmx < max(a, b);j += 2){
      arr[j][i] = mn;
      cmx++;
    }
  }
  for(int i = n - 1;i >= 0;i -= 2){
    for(int j = n - 3;j >= 0 && cmn < min(a, b);j -= 2){
      arr[j][i] = mx;
      cmn++;
    }
  }
  cout << n << ' ' << n << endl;
  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      cout << arr[i][j];
    }
    cout << endl;
  }
}
