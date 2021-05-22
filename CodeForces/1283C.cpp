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
  vector<int> arr(n + 1), z, fr;
  set<int> have;
  for(int i = 1;i <= n;i++){
    cin >> arr[i];
    have.insert(i);
    if(arr[i] == 0)
      z.push_back(i);
  }
  for(int i = 1;i <= n;i++){
    have.erase(arr[i]);
  }
  for(int i : have)fr.push_back(i);
  assert(z.size() == fr.size());
  sort(fr.rbegin(), fr.rend());
  for(int i = 0;i < (int)z.size();i++){
    if(z[i] == fr[i]){
      if(i == 0)swap(z[i], z[i + 1]);
      else swap(z[i], z[i - 1]);
    }
  }
  for(int i = 0;i < (int)z.size();i++){
    arr[z[i]] = fr[i];
  }
  for(int i = 1;i <= n;i++)
    cout << arr[i] << ' ';
  cout << endl;
}
