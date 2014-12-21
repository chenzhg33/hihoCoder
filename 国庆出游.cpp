#include <iostream>
#include <vector>
#include <cstring>
#include <bitset>
using namespace std;
const int N = 105;
vector<int> vec[N];
int order[N];
int n, m, k;
bool finish;
int cnt;
bitset<N> bst[N];

bitset<N> dfs(int cur, int p) {
	bst[cur][cur] = 1;
	vector<int>::iterator it = vec[cur].begin();
	for (; it != vec[cur].end(); ++it) {
		if (*it != p)
			bst[cur] |= dfs(*it, cur);
	}
	return bst[cur];
}

void solve(int cur, int p) {
	//cout << cur << " YES" << endl;
	if (finish) return;
	if (order[cnt] == cur) ++cnt;
	if (vec[cur].size() == 1) return;
	vector<int>::iterator it = vec[cur].begin();
	int index = cnt;
	bool flag = false;
	while(index < k) {
		for (; it != vec[cur].end(); ++it) {
			if (bst[*it][order[index]] && *it != p) {
				flag = true;
				break;
			}
		}
		if (flag == false) {
			it = vec[cur].begin();
			++index;
		} else if (index == cnt) {
			solve(*it, cur);
			index = cnt;
			it = vec[cur].begin();
			//cout << "cur: " << cur << " Index: " << index << " order:" << order[index] << endl;
		} else if (index != cnt) {
			//cout << "finish" << endl;
			finish = true;
			return;
		}
		if (finish) return;
		flag = false;
	}
}

int main() {
	cin >> m;
	//freopen("out.txt", "w", stdout);
	while (m--) {
		cin >> n;
		int p1, p2;
		finish = false;
		cnt = 0;
		for (int i = 0; i < N; ++i) {
			vec[i].clear();
			bst[i].reset();
		}
		for (int i = 0; i < n - 1; ++i) {
			cin >> p1 >> p2;
			vec[p1].push_back(p2);
			vec[p2].push_back(p1);
		}
		cin >> k;
		for (int i = 0; i < k; ++i) {
			cin >> order[i];
		}
		dfs(1, 0);
		solve(1, 0);
		if (finish) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	//system("pause");
	return 0;
}
/*
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
#pragma comment(linker, "/STACK:102400000,102400000")
typedef long long ll;
//typedef pair<int,int> pii; 
#define INF 1e9
#define MAXN 10000
#define MAXM 100
const int maxn = 105;
const int mod = 1000003;
#define eps 1e-6
#define pi 3.1415926535897932384626433
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define scan(n) scanf("%d",&n)
#define scan2(n,m) scanf("%d%d",&n,&m)
#define scans(s) scanf("%s",s);
#define ini(a) memset(a,0,sizeof(a))
#define FILL(a,n) fill(a,a+maxn,n)
#define out(n) printf("%d\n",n)
//ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b);}
#define mk(n,m) make_pair(n,m)
using namespace std;
vector<int> G[maxn];
bitset<maxn> f[maxn]; //学会了bitset的用法，发现很好用
bool cango[maxn][maxn];
int a[maxn];
int n,m;
int now;
void dfs(int u,int fa)
{
	f[u][u] = 1;
	rep(i,(int)G[u].size())
	{
		int v = G[u][i];
		if(v == fa) continue;
		dfs(v,u);
		f[u] |= f[v];
	}
}
int c;
bool ok;
void solve(int u,int fa)
{
	if(c < m && a[c] == u ) c++;
	if(c == m) {
		ok = 1;
		return;
	}
	while(c < m){ //这个看似没用的循环很重要，充分利用了递归的性质
		int nex = a[c];
		int cur = c;
		rep(i,(int)G[u].size())
		{
			int v = G[u][i];
			if(v == fa) continue;
			if(f[v][nex] && cango[u][v])
			{
				cango[u][v] = 0;
				solve(v,u);
				break;
			}
		}
		if(c == cur) break; //表示以该节点为根的子树不存在目标点，跳出循环，（然后返回递归上一层）
	}
}
int main()
{
#ifndef ONLINE_JUDGE  
	freopen("in.txt","r",stdin);  
	//   freopen("out.txt","w",stdout);  
#endif
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		ini(cango);
		rep1(i,n)
		{
			f[i].reset();
			G[i].clear();
		}
		rep(i,n-1)
		{
			int u,v;
			scan2(u,v);
			G[u].push_back(v);
			G[v].push_back(u);
			cango[u][v] = cango[v][u] = 1;
		}
		cin>>m;
		rep(i,m) scan(a[i]);
		dfs(1,-1);
		c = 0;
		ok = 0;
		solve(1,-1);
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
} */
