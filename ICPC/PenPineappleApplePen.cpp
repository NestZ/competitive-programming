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
    int n, k;cin >> n >> k;
    string s;cin >> s;
    vector<int> have(1 << 20);
    for(int i = 1;i <= k;i++){
      string cur;cin >> cur;
      int cur_mask = 0;
      int len = cur.length();
      for(int j = 0;j < len;j++){
        cur_mask |= (1 << (cur[j] - 'a'));
      }
      have[cur_mask] = i;
    }
    for(int i = (1 << 20) - 1;i >= 1;i--){
      if(have[i]){
        for(int j = 0;j < 20;j++){
          if((1 << j) & i){
            have[i ^ (1 << j)] = have[i];
          }
        }
      }
    }
    int cur_mask = 0;
    int cur_len = 0;
    for(int i = 0;i < n;i++){
      int mask = (1 << (s[i] - 'a'));
      if(!have[cur_mask | mask]){
        for(int j = 0;j < cur_len;j++){
          cout << have[cur_mask] << ' ';
        }
        cur_mask = mask;
        cur_len = 1;
      }
      else{
        cur_mask |= mask;
        cur_len++;
      }
    }
    if(cur_len > 0){
      for(int i = 0;i < cur_len;i++)
        cout << have[cur_mask] << ' ';
    }
    cout << endl;
  }
}
