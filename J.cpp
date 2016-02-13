#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s)) //LASTBIT
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second
#define PI 2*acos(0)

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

//////////////////////
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
//////////////////////

/*
  Author: Junior Andrade
*/ 

void arquivo() {
  freopen("","r",stdin);
  freopen("","w",stdout);
}

set<int>s;
int a1[16];

int isPrime( int x ) {
  for(ll i = 2; i * i <= x; ++i) {
    if(x % i == 0) return false;
  }
  return true;
}


void back1(int pos) {
    if(pos == 16) return;
    int vl = 0;
    for(int i = 0; i < pos; ++i) {
        vl *= 2;
        vl += a1[i];
    }
    for(int i = pos - 1; i >= 0; --i) {
        vl *= 2;
        vl += a1[i];
    }

    if(a1[0] != 0 && isPrime(vl)) s.insert(vl);
    a1[pos] = 0;
    back1(pos + 1);
    a1[pos] = 1;
    back1(pos + 1);
}

void back2(int pos) {
    if(pos == 16) return;
    int vl = 0;
    for(int i = 0; i < pos; ++i) {
        vl *= 2;
        vl += a1[i];
    }
    for(int i = pos - 2; i >= 0; --i) {
        vl *= 2;
        vl += a1[i];
    }
    if(a1[0] != 0 && isPrime(vl)) s.insert(vl);
    a1[pos] = 0;
    back2(pos + 1);
    a1[pos] = 1;
    back2(pos + 1);
}

void pre(){
    back1(0);
    back2(0);
    s.insert(0);
}

void conv(int x){
  int ans[33];
  int cnt = 0;
  while(x) {
    ans[cnt++] = x%2;
    x /= 2;
  }
  for(int i = cnt - 1; i >= 0; --i) {
    printf("%d", ans[i]);
  }
  printf("\n");
}

int main() {
  pre();
  int n;
  char str[32];
  while( scanf(" %s", str) != EOF ){
    int len = strlen(str);
    n = 0;
    for(int i = 0; i < len; ++i) {
      n *= 2;
      n += (str[i]=='1');
    }
    set<int>::iterator it = s.lower_bound(n);
    conv(*it);
  }
  return 0;
}
