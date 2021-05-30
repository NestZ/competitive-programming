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

  int n, m;cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  vector<vector<int>> b(n, vector<int>(m));
  vector<int> row_diff(n), col_diff(m);
  for(int i = 0;i < n;i++)
    for(int j = 0;j < m;j++)
      cin >> a[i][j];
  for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
      cin >> b[i][j];
      if(b[i][j] != a[i][j]){
        row_diff[i]++;
        col_diff[j]++;
      }
    }
  }
  bool valid = true;
  for(int i = 0;i < n;i++){
    if(row_diff[i] & 1)valid = false;
  }
  for(int i = 0;i < m;i++){
    if(col_diff[i] & 1)valid = false;
  }
  if(valid)cout << "Yes";
  else cout << "No";
  cout << endl;
}
