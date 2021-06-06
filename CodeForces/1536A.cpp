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
    vector<int> arr(n);
    set<int> s;
    for(int i = 0;i < n;i++){
      cin >> arr[i];
      s.insert(arr[i]);
    }
    bool flag = true;
    while(flag && arr.size() <= 300){
      flag = false;
      int len = arr.size();
      for(int i = 0;i < len - 1;i++){
        for(int j = i + 1;j < len;j++){
          if(!s.count(abs(arr[i] - arr[j]))){
            arr.push_back(abs(arr[i] - arr[j]));
            s.insert(abs(arr[i] - arr[j]));
            flag = true;
          }
        }
      }
    }
    if(s.size() <= 300){
      cout << "YES\n";
      cout << arr.size() << endl;
      for(int i : arr)
        cout << i << ' ';
      cout << endl;
    }
    else cout << "NO\n";
  }
}
