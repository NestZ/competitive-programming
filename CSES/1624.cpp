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

int ans = 0;
vector<vector<char>> arr(8, vector<char>(8));
vector<bool> used_col(8, false);
vector<bool> used_r_diag(16, false);
vector<bool> used_l_diag(16, false);

void fuck(int r){
  if(r == 8)ans++;
  else{
    for(int i = 0;i < 8;i++){
      if(used_col[i] || used_r_diag[r - i + 7] ||
          used_l_diag[(8 - r - 1) - i + 7] || arr[r][i] == '*')continue;
      used_col[i] = used_r_diag[r - i + 7] = used_l_diag[(8 - r - 1) - i + 7] = true;
      fuck(r + 1);
      used_col[i] = used_r_diag[r - i + 7] = used_l_diag[(8 - r - 1) - i + 7] = false;
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for(int i = 0;i < 8;i++)
    for(int j = 0;j < 8;j++)
      cin >> arr[i][j];
  fuck(0);
  cout << ans << endl;
}
