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
  set<int> s;
  for(int i = 0;i <= 1000000;i++)
    s.insert(i);
  vector<int> arr(n);
  for(int i = 0;i < n;i++){
    cin >> arr[i];
    s.erase(arr[i]);
  }
  vector<int> ans;
  int lst = 1e9;
  for(int i = 0;i < n;i++){
    if(arr[i] > lst)
      s.insert(lst);
    ans.push_back(*(s.begin()));
    s.erase(s.begin());
    lst = arr[i];
  }
  for(int i : ans)cout << i << ' ';
  cout << endl;
}
