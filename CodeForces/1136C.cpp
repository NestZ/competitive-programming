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
  bool valid = true;
  vector<vector<int>> a(n, vector<int>(m));
  vector<vector<int>> b(n, vector<int>(m));
  for(int i = 0;i < n;i++)
    for(int j = 0;j < m;j++)
      cin >> a[i][j];
  for(int i = 0;i < n;i++)
    for(int j = 0;j < m;j++)
      cin >> b[i][j];
  for(int i = 0;i < n;i++){
    vector<int> aa, bb;
    for(int j = 0;;j++){
      int r = i - j, c = j;
      if(r < 0 || c < 0 || r >= n || c >= m)break;
      aa.push_back(a[r][c]);
      bb.push_back(b[r][c]);
    }
    sort(aa.begin(), aa.end());
    sort(bb.begin(), bb.end());
    for(int j = 0;j < (int)aa.size();j++){
      if(aa[j] != bb[j])valid = false;
    }
  }
  for(int i = 1;i < m;i++){
    vector<int> aa, bb;
    for(int j = 0;;j++){
      int r = n - 1 - j, c = i + j;
      if(r < 0 || c < 0 || r >= n || c >= m)break;
      aa.push_back(a[r][c]);
      bb.push_back(b[r][c]);
    }
    sort(aa.begin(), aa.end());
    sort(bb.begin(), bb.end());
    for(int j = 0;j < (int)aa.size();j++){
      if(aa[j] != bb[j])valid = false;
    }
  }
  if(valid)cout << "YES";
  else cout << "NO";
  cout << endl;
}
