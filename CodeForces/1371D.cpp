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
    vector<vector<int>> arr(n, vector<int>(n));
    vector<int> op(n);
    for(int i = 0;i < n;i++)op[i] = i;
    for(int i = 0;i < k;i++){
      int col = i % n;
      arr[op[col]][col] = 1;
      op[col] = (op[col] + 1) % n;
    }
    int mxr = 0, mnr = n, mxc = 0, mnc = n;
    for(int i = 0;i < n;i++){
      int cntr = 0, cntc = 0;
      for(int j = 0;j < n;j++){
        if(arr[i][j])cntr++;
        if(arr[j][i])cntc++;
      }
      mxr = max(mxr, cntr);
      mnr = min(mnr, cntr);
      mxc = max(mxc, cntc);
      mnc = min(mnc, cntc);
    }
    int dr = mxr - mnr;
    int dc = mxc - mnc;
    cout << dr * dr + dc * dc << endl;
    for(int i = 0;i < n;i++){
      for(int j = 0;j < n;j++){
        cout << arr[i][j];
      }
      cout << endl;
    }
  }
}
