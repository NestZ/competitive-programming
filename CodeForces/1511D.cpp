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

int k;
vector<int> cnt(26);
char find(char lst){
  char res = '$';
  for(int c = cnt[lst - 'a'];c < k;c++){
    if(cnt[c] == min(26, k))continue;
    return char('a' + c);
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;cin >> n >> k;
  string ans = "a";
  char lst = 'a';
  for(int i = 1;i < n;i++){
    char app = find(lst);
    if(app == '$')break;
    cnt[lst - 'a'] = int(app - 'a') + 1;
    ans += app;
    lst = app;
  }
  if((int)ans.length() < n){
    for(int i = 0;i < n / (int)ans.length();i++)
      cout << ans;
    cout << ans.substr(0, n % (int)ans.length());
  }
  else cout << ans;
  cout << endl;
}
