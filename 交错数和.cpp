#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
//#pragma comment(linker, "/STACK:102400000,102400000")
typedef long long ll;
#define INF 1e9
#define MAXN 21
#define maxn 360
#define mod 1000000007
#define eps 1e-7
#define pi 3.1415926535897932384626433
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define scan(n) scanf("%d",&n)
#define scanll(n) scanf("%I64d",&n)
#define scan2(n,m) scanf("%d%d",&n,&m)
#define scans(s) scanf("%s",s);
#define ini(a) memset(a,0,sizeof(a))
#define out(n) printf("%d\n",n)
ll gcd(ll a,ll b) {return b==0?a:gcd(b,a%b);}
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
struct node
{
	ll cnt,sum; //分别表示该状态的出现的次数，以及数字和
	node(ll _cnt,ll _sum):cnt(_cnt),sum(_sum){}
	node(){}
}dp[20][20][300]; //dp[i][j][k],表示当前在的i位，第一位有效位为j，交错和为k-100的状态
ll num[20];
ll ten[20];
ll l,r;
int k;
node dfs(int cur,int first,int sum,bool limit)
{
	if(cur <= 0)
		return node(sum==k,0);
	if(!limit && dp[cur][first][sum+100].cnt != -1) return dp[cur][first][sum+100];
	int up = limit ? num[cur] : 9;
	node ret(0,0),tv;
	rep(i,up+1)
	{
    if(!first){
			if (i == 0)
				tv = dfs(cur-1,0,0,limit && i==up);
			else
				tv = dfs(cur-1,cur,sum+i,limit && i == up);
		} else
			tv = dfs(cur-1,first,sum+((first-cur)%2==0?1:-1)*i,limit && i == up);
			
		ll t = i*ten[cur-1]%mod;
		ret.cnt = (ret.cnt + tv.cnt) % mod; //次数相加
		ret.sum = (ret.sum + tv.sum + t*tv.cnt)%mod; //和相加
	}
	if(!limit) dp[cur][first][sum+100] = ret;
	return ret;
}
ll solve(ll n)
{
	if(n <= 0) return 0;
	int len = 0;
	while(n){
		num[++len] = n % 10;
		n /= 10;
	}
	return dfs(len,0,0,1).sum;
}
void init()
{
	memset(dp,-1,sizeof(dp));
	ten[0] = 1;
	for(int i=1;i<20;i++) ten[i] = (ten[i-1] * 10) % mod;
}
int main()
{
	init();
	while(~scanf("%lld%lld%d",&l,&r,&k))
	{
		cout<<(solve(r)-solve(l-1)+mod)%mod<<'\n';
	}
    return 0;
}
