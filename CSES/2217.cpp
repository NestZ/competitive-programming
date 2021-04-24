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

  int n, m;cin >> n >> m;
  vector<int> arr(n + 1);
  vector<int> p(n + 1);
  for(int i = 1;i <= n;i++){
    cin >> arr[i];
    p[arr[i]] = i;
  }
  int cur = 1;
  int lst = 0;
  for(int i = 1;i <= n;i++){
    if(p[i] < lst)cur++;
    lst = p[i];
  }
  for(int i = 0;i < m;i++){
    int a, b;cin >> a >> b;
    if(a > b)swap(a, b);
    if(a != b){
      if(arr[b] > 1 && p[arr[b]] > p[arr[b] - 1])cur++;
      if(arr[b] < n && p[arr[b]] < p[arr[b] + 1])cur++;
      if(arr[a] > 1 && p[arr[a]] > p[arr[a] - 1])cur++;
      if(arr[a] < n && p[arr[a]] < p[arr[a] + 1])cur++;
      if(arr[a] - arr[b] == 1)cur++;
      if(arr[b] - arr[a] == 1)cur--;
      swap(p[arr[b]], p[arr[a]]);
      swap(arr[a], arr[b]);
      if(arr[a] > 1 && p[arr[a]] > p[arr[a] - 1])cur--;
      if(arr[a] < n && p[arr[a]] < p[arr[a] + 1])cur--;
      if(arr[b] > 1 && p[arr[b]] > p[arr[b] - 1])cur--;
      if(arr[b] < n && p[arr[b]] < p[arr[b] + 1])cur--;
    }
    cout << cur << endl;
  }
}
