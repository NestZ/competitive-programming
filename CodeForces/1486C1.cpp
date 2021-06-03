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

int q(int l, int r){
  cout << "? " << l << ' ' << r << endl;
  int ind;cin >> ind;
  return ind;
}

void ans(int p){
  cout << "! " << p << endl;
}

int main(){
  int n;cin >> n;
  int l = 1, r = n;
  int ind = -1;
  int pos = -1;
  while(l <= r){
    if(l == r){
      pos = l;
      break;
    }
    if(ind == -1 || r - l == 1){
      ind = q(l, r);
      if(r - l == 1){
        if(ind == l)pos = r;
        else pos = l;
        break;
      }
    }
    int mid = l + (r - l) / 2;
    int ql = l, qr = r;
    bool cl = true;
    if(ind >= mid){
      ql = mid;
      qr = r;
      cl = false;
    }
    else{
      ql = l;
      qr = mid;
    }
    int cq = q(ql, qr);
    if(ind == cq){
      if(cl)r = mid;
      else l = mid;
    }
    else{
      if(cl)l = mid + 1;
      else r = mid - 1;
      ind = -1;
    }
  }
  ans(pos);
}
