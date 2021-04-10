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
    int n, l, r, s;cin >> n >> l >> r >> s;
    vector<int> ans;
    int len = r - l + 1;
    for(int i = n;i >= 1;i--){
      if(s - i >= len * (len - 1) / 2){
        s -= i;
        len--;
        ans.push_back(i);
      }
    }
    if(r - l + 1 != (int)ans.size())cout << -1;
    else{
      set<int> se;
      for(int i : ans)se.insert(i);
      vector<int> res(n, -1);
      int ptr = 0;
      for(int i = l - 1;i < r;i++){
        res[i] = ans[ptr++];
      }
      ptr = 1;
      for(int i = 0;i < n;i++){
        while(se.count(ptr))ptr++;
        if(res[i] != -1)continue;
        res[i] = ptr++;
      }
      for(int i : res)cout << i << ' ';
    }
    cout << endl;
  }
}
