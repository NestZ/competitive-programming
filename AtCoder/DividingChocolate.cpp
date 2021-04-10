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

  int h, w, k;cin >> h >> w >> k;
  int ans = INT_MAX;
  int mx_cut = h - 1;
  vector<vector<char>> arr(h, vector<char>(w));
  for(int i = 0;i < h;i++)
    for(int j = 0;j < w;j++)
      cin >> arr[i][j];
  for(int i = 0;i < (1 << mx_cut);i++){
    int hor_cut = __builtin_popcount(i);
    int ver_cut = 0;
    vector<int> cnt(hor_cut + 1);
    for(int l = 0;l < w;l++){
      int ptr = 0;
      bool cut = false;
      bool valid = true;
      vector<int> tmp(hor_cut + 1);
      for(int j = 0;j < h;j++){
        if(arr[j][l] == '1')tmp[ptr]++;
        if(!cut && cnt[ptr] + tmp[ptr] > k){
          ver_cut++;
          cut = true;
        }
        if((1 << j) & i)ptr++;
      }
      for(int j = 0;j < hor_cut + 1;j++){
        if(tmp[j] > k)valid = false;
        if(cut)cnt[j] = tmp[j];
        else cnt[j] += tmp[j];
      }
      if(!valid){
        ver_cut = 1e9;
        break;
      }
    }
    ans = min(ans, hor_cut + ver_cut);
  }
  cout << ans << endl;
}
