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
  if(m == 0)cout << 1 << endl;
  else{
    int mnd = INT_MAX;
    vector<int> arr(m);
    for(int i = 0;i < m;i++)cin >> arr[i];
    sort(arr.begin(), arr.end());
    if((int)arr.back() != n)arr.push_back(n + 1);
    int lst = 0;
    for(int i = 0;i < (int)arr.size();i++){
      int diff = arr[i] - lst - 1;
      if(diff > 0)mnd = min(mnd, diff);
      lst = arr[i];
    }
    debug() << imie(mnd);
    if(mnd == 0)cout << 0;
    else{
      int ans = 0;
      lst = 0;
      for(int i = 0;i < (int)arr.size();i++){
        int diff = arr[i] - lst - 1;
        if(diff > 0){
          if(mnd == 1)ans += diff;
          else ans += (diff + mnd - 1) / mnd;
        }
        lst = arr[i];
      }
      cout << ans;
    }
    cout << endl;
  }
}
