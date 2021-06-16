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
    string s;cin >> s;
    int n;cin >> n;
    vector<int> arr(n), ind;
    vector<char> ans(n);
    map<char, int> m;
    for(int i = 0;i < n;i++){
      cin >> arr[i];
      if(arr[i] == 0)ind.push_back(i);
    }
    for(char c : s)m[c]++;
    auto ptr = --m.end();
    while((*ptr).second < (int)ind.size())
      ptr--;
    for(int i : ind)ans[i] = (*ptr).first;
    ptr--;
    while(true){
      ind.clear();
      for(int i = 0;i < n;i++){
        if(arr[i] == 0)continue;
        int diff = 0;
        for(int j = 0;j < n;j++){
          if(arr[j] == 0)diff += abs(i - j);
        }
        if(diff == arr[i]){
          ind.push_back(i);
        }
      }
      while((*ptr).second < (int)ind.size())
        ptr--;
      for(int i : ind){
        ans[i] = (*ptr).first;
        arr[i] = 0;
      }
      if(ptr != m.begin())ptr--;
      else break;
      if(*max_element(arr.begin(), arr.end()) == 0)
        break;
    }
    for(char c : ans)cout << c;
    cout << endl;
  }
}
