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

void sw(int p1, int p2, vector<int> &pos,
    vector<pair<int, int>> &ans,
    vector<int> &arr,
    int n){
  pos[arr[p1]] = p2;
  pos[arr[p2]] = p1;
  swap(arr[p1], arr[p2]);
  ans.push_back({p1, p2});
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;cin >> n;
  vector<int> arr(n + 1), pos(n + 1);
  vector<pair<int, int>> ans;
  for(int i = 1;i <= n;i++){
    cin >> arr[i];
    pos[arr[i]] = i;
  }
  for(int i = 1;i <= n;i++){
    if(i == arr[i])continue;
    int p = pos[i];
    if(2 * abs(pos[i] - i) >= n){
      sw(p, i, pos, ans, arr, n);
    }
    else{
      if(i <= n / 2){
        if(p <= n / 2){
          sw(p, n, pos, ans, arr, n);
          sw(i, n, pos, ans, arr, n);
        }
        else{
          sw(p, 1, pos, ans, arr, n);
          sw(1, n, pos, ans, arr, n);
          sw(n, i, pos, ans, arr, n);
          sw(p, 1, pos, ans, arr, n);
        }
      }
      else{
        sw(p, 1, pos, ans, arr, n);
        sw(1, i, pos, ans, arr, n);
        sw(p, 1, pos, ans, arr, n);
      }
    }
  }
  cout << ans.size() << endl;
  for(auto p : ans)
    cout << p.first << ' ' << p.second << endl;
}
