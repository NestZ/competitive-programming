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

  string s;cin >> s;
  int n = s.length();
  vector<vector<int>> cnt(26);
  for(int i = 0;i < n;i++){
    int cur = s[i] - 'a';
    cnt[cur].push_back(i);
  }
  for(int i = 0;i < 26;i++){
    int sz = cnt[i].size();
    for(int j = 0;j < sz - 1;j++){
      for(int k = j + 1;k < sz;k++){
        int len = cnt[i][k] - cnt[i][j] + 1;
        int num = k - j + 1;
        if(num > len / 2){
          cout << cnt[i][j] + 1 << ' ' << cnt[i][k] + 1 << endl;
          return 0;
        }
      }
    }
  }
  cout << "-1 -1\n";
}
