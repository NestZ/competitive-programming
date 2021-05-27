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
  vector<char> ans;
  vector<int> arr(n);
  for(int i = 0;i < n;i++)cin >> arr[i];
  int l = 0, r = n - 1;
  int cur = 0;
  while(l <= r){
    if(arr[l] > cur && arr[r] > cur){
      if(arr[l] < arr[r]){
        ans.push_back('L');
        cur = arr[l];
        l++;
      }
      else if(arr[r] < arr[l]){
        ans.push_back('R');
        cur = arr[r];
        r--;
      }
      else{
        int lc = 0, rc = 0;
        int lst = cur;
        for(int i = l;i < r;i++){
          if(arr[i] > lst){
            lst = arr[i];
            lc++;
          }
          else break;
        }
        lst = cur;
        for(int i = r;i > l;i--){
          if(arr[i] > lst){
            lst = arr[i];
            rc++;
          }
          else break;
        }
        if(lc > rc){
          ans.push_back('L');
          cur = arr[l];
          l++;
        }
        else{
          ans.push_back('R');
          cur = arr[r];
          r--;
        }
      }
    }
    else if(arr[r] > cur){
      ans.push_back('R');
      cur = arr[r];
      r--;
    }
    else if(arr[l] > cur){
      ans.push_back('L');
      cur = arr[l];
      l++;
    }
    else break;
  }
  cout << ans.size() << endl;
  for(char c : ans)cout << c;
  cout << endl;
}
