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

  string a, b;cin >> a >> b;
  int na = a.length();
  int nb = b.length();
  int one = count(b.begin(), b.end(), '1');
  vector<int> pre(na + 1);
  for(int i = 0;i < na;i++){
    if(a[i] == '1')pre[i + 1] = 1;
    pre[i + 1] += pre[i];
  }
  int ans = 0;
  for(int i = nb - 1;i < na;i++){
    int cnt = pre[i + 1] - pre[i - nb + 1];
    if(cnt % 2 == one % 2)ans++;
  }
  cout << ans << endl;
}
