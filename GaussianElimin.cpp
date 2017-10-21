//
//  WELCOME TO MY CODE, DO NOT HACK IF YOU PLEASE :P
//
//
/*
 “The only thing that I see that is distinctly different about me is I'm not afraid to die on a treadmill. I will not be out-worked, period. You might have more talent than me, you might be smarter than me, you might be sexier than me, you might be all of those things you got it on me in nine categories. But if we get on the treadmill together, there's two things: You're getting off first, or I'm going to die. It's really that simple, right?
 You're not going to out-work me. It's such a simple, basic concept. The guy who is willing to hustle the most is going to be the guy that just gets that loose ball. The majority of people who aren't getting the places they want or aren't achieving the things that they want in this business is strictly based on hustle. It's strictly based on being out-worked; it's strictly based on missing crucial opportunities. I say all the time if you stay ready, you ain't gotta get ready.”
 
 ― Will Smith
 */
//
//  Created by Alessandro Solbiati.

//
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <bitset>
#include <queue>
using namespace std;
#define EPS 1e-9
#define INF 1e9
#define foor(n) for (int i=0;i<n;i++)
#define fooor(a,n) for (int i=a;i<n;i++)
#define per(a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define pc(x) putchar(x)
typedef vector<int> vi;
typedef vector<int,int> vii;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
namespace ib {char b[100];}
inline void pi(int x){ //fasto
    if(x==0) {pc(48); return;}
    if(x<0) {pc('-'); x=-x;}
    char *s=ib::b;
    while(x) *(++s)=x%10,x/=10;
    while(s!=ib::b) pc((*(s--))+48);
}
inline void ri(int &x){ //fasti
    x=0; static char c; bool t(0);
    while(c=getchar(),c<'0'||c>'9') if(c=='-') t=1; else t=0;
    do x=(x<<1)+(x<<3)+c-'0'; while(c=getchar(),c>='0'&&c<='9');
    if(t) x=-x;
}
//head

int gauss (vector < vector<double> > a, vector<double> & ans) {
    //return number of solution (0,1,INF)
    //ans: vector of solutions
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;
    
    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (abs (a[sel][col]) < EPS)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;
        
        for (int i=0; i<n; ++i)
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }
    
    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i=0; i<n; ++i) {
        double sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (abs (sum - a[i][m]) > EPS)
            return 0;
    }
    
    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return INF;
    return 1;
}

