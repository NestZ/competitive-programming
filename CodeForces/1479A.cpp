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

int q(int x){
  cout << "? " << x << endl;
  int res;cin >> res;
  return res;
}

void ans(int x){
  cout << "! " << x << endl;
}

int main(){
  int n;cin >> n;
  if(n == 1){
    ans(1);
    return 0;
  }
  else if(n == 2){
    int a = q(1);
    int b = q(2);
    if(a < b)ans(1);
    else ans(2);
    return 0;
  }
  int l = 1, r = n, best = -1;
  while(l <= r){
    if(abs(l - r) == 0){
      ans(l);
      return 0;
    }
    else if(abs(l - r) == 1){
      int a = q(l);
      int b = q(r);
      if(a < b)ans(l);
      else ans(r);
      return 0;
    }
    int mid = l + (r - l) / 2;
    int a = q(mid - 1);
    int b = q(mid);
    int c = q(mid + 1);
    if(b < a && b < c){
      ans(mid);
      return 0;
    }
    else if(b > a){
      r = mid - 1;
      best = r;
    }
    else if(b > c){
      l = mid + 1;
      best = l;
    }
  }
  ans(best);
}
