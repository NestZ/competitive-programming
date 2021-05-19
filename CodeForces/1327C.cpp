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

  int n, m, k;cin >> n >> m >> k;
  vector<pair<int, int>> arr;
  vector<pair<int, int>> want;
  for(int i = 0;i < k;i++){
    int a, b;cin >> a >> b;
    arr.push_back({a, b});
  }
  for(int i = 0;i < k;i++){
    int a, b;cin >> a >> b;
    want.push_back({a, b});
  }
  vector<char> ans;
  for(int i = 0;i < m - 1;i++)
    ans.push_back('L');
  for(int i = 0;i < n - 1;i++)
    ans.push_back('D');
  for(int i = 0;i < n;i++){
    if(i > 0)ans.push_back('U');
    if(i & 1){
      for(int j = 0;j < m - 1;j++)
        ans.push_back('L');
    }
    else{
      for(int j = 0;j < m - 1;j++)
        ans.push_back('R');
    }
  }
  cout << ans.size() << endl;
  for(char c : ans)cout << c;
  cout << endl;
}
