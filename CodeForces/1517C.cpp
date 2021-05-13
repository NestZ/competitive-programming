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

int n;
bool valid(int x, int y, vector<vector<int>> &arr){
  if(x < 0 || y < 0 || x >= n || y >= n)return false;
  if(arr[x][y] != 0)return false;
  return true;
}

void ff(int x, int y, int num, int cnt, vector<vector<int>> &arr){
  if(cnt > num)return;
  arr[x][y] = num;
  if(valid(x, y - 1, arr)){
    ff(x, y - 1, num, cnt + 1, arr);
  }
  else if(valid(x + 1, y, arr)){
    ff(x + 1, y, num, cnt + 1, arr);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  vector<vector<int>> arr(n, vector<int>(n));
  for(int i = 0;i < n;i++)cin >> arr[i][i];
  for(int i = 0;i < n;i++){
    ff(i, i, arr[i][i], 1, arr);
  }
  for(int i = 0;i < n;i++){
    for(int j = 0;j <= i;j++){
      cout << arr[i][j] << ' ';
    }
    cout << endl;
  }
}
