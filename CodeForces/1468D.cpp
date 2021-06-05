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
    int n, m, a, b;cin >> n >> m >> a >> b;
    vector<int> bomb(m);
    for(int i = 0;i < m;i++)cin >> bomb[i];
    sort(bomb.rbegin(), bomb.rend());
    int time1 = abs(a - b) - 1;
    int time2 = 0;
    if(b > a)time2 = a - 1;
    else time2 = n - a;
    int mx_time = time1 + time2;
    int ans = 0;
    for(int i = 0;i < m;i++){
      if(bomb[i] > mx_time)continue;
      mx_time--;
      ans++;
    }
    cout << min(time1, ans) << endl;
  }
}
