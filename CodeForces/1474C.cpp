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
    n = n * 2;
    vector<int> arr(n);
    for(int i = 0;i < n;i++)cin >> arr[i];
    sort(arr.begin(), arr.end());
    for(int i = 0;i < n - 1;i++){
      multiset<int> s(arr.begin(), arr.end());
      int fst = arr.back(), snd = arr[i];
      int x = fst + snd;
      bool valid = true;
      vector<pair<int, int>> ans;
      while(s.size()){
        int nfst = *(--s.end());
        s.erase(s.find(nfst));
        auto ptr = s.find(x - nfst);
        if(ptr == s.end()){
          valid = false;
          break;
        }
        int nsnd = *ptr;
        x = max(nsnd, nfst);
        ans.push_back({nfst, nsnd});
        s.erase(s.find(nsnd));
      }
      if(valid){
        cout << "YES\n";
        cout << arr.back() + arr[i] << endl;
        for(auto p : ans)
          cout << p.first << ' ' << p.second << endl;
        break;
      }
      else if(i == n - 2)cout << "NO\n";
    }
  }
}
