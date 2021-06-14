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
    int n;cin >> n;
    string a, b;cin >> a >> b;
    vector<vector<int>> arr(30, vector<int>(30));
    for(int i = 0;i < n;i++){
      int fst = a[i] - 'a';
      int snd = b[i] - 'a';
      if(fst != snd)arr[fst][snd]++;
    }
    int ans = 0;
    for(int i = 0;i < 20;i++){
      int fst = INT_MAX;
      for(int j = i + 1;j < 20;j++){
        if(arr[i][j] > 0){
          fst = min(fst, j);
        }
      }
      if(fst == INT_MAX)continue;
      arr[i][fst] = 0;
      for(int j = fst + 1;j < 20;j++){
        arr[fst][j] += arr[i][j];
        arr[i][j] = 0;
      }
      ans++;
    }
    for(int i = 0;i < 20;i++){
      for(int j = 0;j < 20;j++){
        if(arr[i][j] > 0)ans = -1;
      }
    }
    cout << ans << endl;
  }
}
