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

char s1[10], s2[10];
int l1, l2;
char s[20];
set<string>mys;
int qtd;

void back(int a, int b) {
  if(a + b == l1 + l2) {
    mys.insert((string)s);
    qtd++;
    return;
  }
  if(a < l1) {
    s[a + b] = s1[a];
    back(a + 1, b);
  }
  if(b < l2) {
    s[a + b] = s2[b];
    back(a, b +1);
  }
}

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    scanf(" %s %s", s1, s2);
    l1 = strlen(s1);
    l2 = strlen(s2);
    mys.clear();
    memset(s, 0, sizeof s);
    qtd = 0;
    back(0, 0);
    for(set<string>::iterator it = mys.begin(); it != mys.end(); it++){
      printf("%s\n", (*it).c_str());
    }
    printf("\n");

    debug("%d\n", qtd);
  }

  return 0;
}
