#include <stdio.h>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
struct disjointSet;
struct element;
struct element {
  disjointSet* disjointSet_;
  string value_;
  element* next_;
  element() : next_(NULL), disjointSet_(NULL) {}
  element(string value) : next_(NULL), disjointSet_(NULL), value_(value) {}
};
struct disjointSet {
  element* head_;
  element* tail_;
  disjointSet() : head_(NULL), tail_(NULL) {}
};
disjointSet* makeSet(element* e) {
  disjointSet* temp = new disjointSet();
  temp->head_ = e;
  temp->tail_ = e;
  e->disjointSet_ = temp;
  return temp;
}
element* findSet(element* element_) {
	if (element_->disjointSet_ == NULL)
		return NULL;
  return element_->disjointSet_->head_;
}
void Union(element* a, element* b) {
  disjointSet* a_disjointSet = findSet(a)->disjointSet_;
  disjointSet* b_disjointSet = findSet(b)->disjointSet_;
  if (a_disjointSet != b_disjointSet) {
    a_disjointSet->tail_->next_ = b_disjointSet->head_;
    element* temp= b_disjointSet->head_;
    while (temp) {
      temp->disjointSet_ = a_disjointSet;
      temp = temp->next_;
    }
    a_disjointSet->tail_ = b_disjointSet->tail_;
  }
}
int main() {
	int n, q;
	scanf("%d", &n);
	map<string, element*> mp;
	char buf[1024];
	while (n--) {
		scanf("%d", &q);
		string name1, name2;
		scanf("%s", buf); name1 = buf;
		scanf("%s", buf); name2 = buf;
		if (q == 0) {
			if (mp.find(name1) == mp.end()) {
				mp[name1] = new element(name1);
				makeSet(mp[name1]);
			}
			if (mp.find(name2) == mp.end()) {
				mp[name2] = new element(name2);
				makeSet(mp[name2]);
			}
			Union(mp[name1], mp[name2]);
		} else if (q == 1) {
			if (mp.find(name1) != mp.end() && mp.find(name2) != mp.end() && findSet(mp[name1]) == findSet(mp[name2]))
				printf("yes\n");
			else
				printf("no\n");
		}
	}
	return 0;
}
// 最快代码  
#include <iostream>
#include <cstdio>
#include <cstring>
const int N=100010;
#define C(c) c>'Z'?c-'a'+26:c-'A'
int e[N],x[N][26*2],c=0,d=0;
int add(){
    ++c;
    e[c]=0;
    memset(x[c],0,sizeof(x[c]));
    return c;
}
int find(char*s){
    int p=0,t;
    while(*s){
        t=C(*s);
        if(!x[p][t])x[p][t]=add();
        p=x[p][t];
        ++s;
    }
    return e[p]?e[p]:e[p]=++d;
}
char a[100],b[100];
int r[N],n,o,A,B;
int find(int i){return i==r[i]?i:r[i]=find(r[i]);}
int main(){
    for(scanf("%d",&n);n--;){
        scanf("%d%s%s",&o,a,b);
        A=find(a);B=find(b);
        //std::cout << A << ' ' << B << std::endl;
        if(!r[A])r[A]=A;
        if(!r[B])r[B]=B;
        A=find(A);B=find(B);
        if(o)puts(A==B?"yes":"no");
        else r[A]=B;
    }
    return 0;
}
//第二快代码 
#include <stdio.h>

#define N 100003
#define L 101

int ufset[N + 2], num_child[N];

int findset(int k)
{
    if(ufset[k] != k)
        return ufset[k] = findset(ufset[k]);
    return k;
}

void unionset(int x, int y)
{
    x = findset(x);
    y = findset(y);
    if(x != y) {
        if(num_child[x] <= num_child[y]) {
            ufset[x] = y;
            num_child[y] += num_child[x] + 1;
        } else {
            ufset[y] = x;
            num_child[x] += num_child[y] + 1;
        }
    }
}

struct hashnode {
    char str[L];
    struct hashnode *next;
} nodes[N << 1], *hashtable[N];

int id;

int hashfind(int hashkey, char *s)
{
    struct hashnode *node;
    for(node = hashtable[hashkey]; node && strcmp(node->str, s); node = node->next)
        ;
    return node == NULL ? -1 : (node - nodes);
}

int hashinsert(int hashkey, char *s)
{
    strcpy(&nodes[id].str, s);
    nodes[id].next = hashtable[hashkey];
    hashtable[hashkey] = &nodes[id];
    return id++;
}

int hashcode(char *str)
{
    unsigned int seed = 13131; // 31 131 1313 13131 131313 ..
    unsigned int hash = 0;
    while (*str)
        hash = hash * seed + (*str++);
    return (hash & 0x7FFFFFFF);
}

int main()
{
    int n, i, ha, hb, fa, fb;
    char na[L], nb[L], *pa, *pb;
    for(i = 0; i < N + 2; i++)
        ufset[i] = i;
    scanf("%d", &n);
    while(n-- > 0) {
        scanf("%d%s%s", &i, na, nb);
        ha = hashcode(na) % N;
        hb = hashcode(nb) % N;
        fa = hashfind(ha, na);
        fb = hashfind(hb, nb);
        if(i) {
            if(fa == -1 || fb == -1 || findset(fa) != findset(fb))
                printf("no\n");
            else
                printf("yes\n");
        } else {
            if(fa == -1)
                fa = hashinsert(ha, na);
            if(fb == -1)
                fb = hashinsert(hb, nb);
            unionset(fa, fb);
        }
    }
    return 0;
}
//code Length 最短代码 
#include <bits/stdc++.h>
using namespace std;
map<string,int> H;
int r[100010],o,n,c=0,A,B;
int f(int i){return r[i]==i?i:r[i]=f(r[i]);}
string a,b;
int main(){
    for(cin>>n;n--;){
        cin>>o>>a>>b;
        if(!(A=H[a]))A=H[a]=++c,r[c]=c;
        if(!(B=H[b]))B=H[b]=++c,r[c]=c;
        if(o)puts(f(A)==f(B)?"yes":"no");
        else r[f(A)]=f(B);
    }
}
