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
    vector<vector<char>> arr(n, vector<char>(n));
    int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
    for(int i = 0;i < n;i++){
      for(int j = 0;j < n;j++){
        cin >> arr[i][j];
        if(arr[i][j] == '*'){
          if(x1 == -1){
            x1 = i; y1 = j;
          }
          else{
            x2 = i; y2 = j;
          }
        }
      }
    }
    if(x1 == x2){
      if(x1 > 0){
        arr[x1 - 1][y1] = arr[x2 - 1][y2] = '*';
      }
      else{
        arr[x1 + 1][y1] = arr[x2 + 1][y2] = '*';
      }
    }
    else if(y1 == y2){
      if(y1 > 0){
        arr[x1][y1 - 1] = arr[x2][y2 - 1] = '*';
      }
      else{
        arr[x1][y1 + 1] = arr[x2][y2 + 1] = '*';
      }
    }
    else{
      arr[x1][y2] = arr[x2][y1] = '*';
    }
    for(int i = 0;i < n;i++){
      for(int j = 0;j < n;j++){
        cout << arr[i][j];
      }
      cout << endl;
    }
  }
}
