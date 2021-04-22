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

  int n;cin >> n;
  vector<int> a(n), b(n);
  vector<vector<int>> arr(n, vector<int>(n));
  for(int i = 0;i < n;i++){
    int mx = INT_MAX;
    for(int j = 0;j < n;j++){
      cin >> arr[i][j];
      mx = min(arr[i][j], mx);
    }
    a[i] = mx;
  }
  for(int i = 0;i < n;i++){
    b[i] = arr[0][i] - a[0];
  }
  bool ans = true;
  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      if(a[i] + b[j] != arr[i][j])ans = false;
    }
  }
  if(!ans)cout << "No";
  else{
    cout << "Yes\n";
    for(int i : a)cout << i << ' ';
    cout << endl;
    for(int i : b)cout << i << ' ';
  }
  cout << endl;
}
