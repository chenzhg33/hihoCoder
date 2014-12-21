#include <stdio.h>
#include <string>
#include <list>
#include <map>
using namespace std;

map<string, string> mp;
void search(string s1, string s2) {
	list<string> list1;
	list<string> list2;
	while (mp.find(s1) != mp.end()) {
		list1.push_back(s1);
		s1 = mp[s1];
	}
	while (mp.find(s2) != mp.end()) {
		list2.push_back(s2);
		s2 = mp[s2];
	}
	if (s1 != s2) {
		printf("%d\n", -1);
		return;
	}
	list1.push_back(s1);
	list2.push_back(s2);
	list<string>::reverse_iterator it1 = list1.rbegin();
	list<string>::reverse_iterator it2 = list2.rbegin();
	for (; it1 != list1.rend() && it2 != list2.rend() && *it1 == *it2; it1++, it2++) ;
	if (*(--it1) != *(--it2)) {
	    printf("%d\n", -1);
	    return;
	}
	printf("%s\n", it1->c_str());
}
int main() {
	int n;
	scanf("%d", &n);
	string p, s;
	char strbuf[1024];
	while (n--) {
		scanf("%s", strbuf); p = strbuf;
		scanf("%s", strbuf); s = strbuf;
		mp[s] = p;
	}
	scanf("%d", &n);
	while (n--) {
		string tmp1, tmp2;
		scanf("%s", strbuf); tmp1 = strbuf;
		scanf("%s", strbuf); tmp2 = strbuf;
		search(tmp1, tmp2);
	}
	//system("pause");
	return 0;
}
/************************************************
#include <string>
#include <vector>
#include <map>
#include <cstdio>

using namespace std;

int main()
{
	int N,M,id=0; char strbuf[1024];
	scanf("%d",&N);
	vector<string> fns,sns,names;
	map<string,int> all;
	for(int i = 0; i < N; i++) {
		string fn,sn;
		scanf("%s",strbuf);fn = strbuf;
		scanf("%s",strbuf);sn = strbuf;
		fns.push_back(fn);sns.push_back(sn);
		all[fn] = 0;all[sn] = 0;
	}
	for(map<string,int>::iterator ite = all.begin(); ite != all.end(); ite++) {
		names.push_back(ite->first); ite->second = id++;
	}
	vector<int> pid(id,-1);
	for(int i = 0; i < N; i++) pid[all[sns[i]]] = all[fns[i]];
	scanf("%d",&M);
	for(int i = 0; i < M; i++) {
		string s1,s2;
		scanf("%s",strbuf);s1 = strbuf;
		scanf("%s",strbuf);s2 = strbuf;
		
		int a=-1,b=-1;
		if(all.count(s1)) a = all[s1];
		if(all.count(s2)) b = all[s2];
		
		if(a==-1 || b==-1) {
			if(s1==s2) printf("%s\n",s1.c_str());
			else printf("-1\n");
		} else {
			vector<int> mask(id,1);
			while(a>-1) {mask[a] = 0;a = pid[a];}
			while(b>-1&&mask[b]) b = pid[b];
			if(b>-1) printf("%s\n",names[b].c_str());
			else printf("-1\n");
		}
	}
}*/

