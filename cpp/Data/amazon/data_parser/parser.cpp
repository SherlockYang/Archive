#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>

using namespace std;

#define SIZE(A) ((int)A.size())
typedef pair<int,int> ipair;
#define MP(A,B) make_pair(A,B)

int get_id(map<int,int> &M, int key)
{
	if (M.find(key)!=M.end()) return M[key];
	int size=SIZE(M);
	return M[key]=size;
}

int main()
{
	freopen("..\\amazon\\Amazon0302.txt","r",stdin);
	freopen("..\\amazon\\ama_data.txt","w",stdout);
	vector<ipair> a;
	int u,v;
	while (scanf("%d%d",&u,&v)!=-1)
	{
		if (u>v) swap(u,v);
		a.push_back(MP(u,v));
	}
	int n=0,m=0;
	for (int i=0;i<SIZE(a);i++)
	{
		if (a[i].first+1>n) n=a[i].first+1;
		if (a[i].second+1>n) n=a[i].second+1;
	}
	sort(a.begin(),a.end());
	for (int i=0;i<SIZE(a);i++) if (i==0 || a[i]!=a[i-1]) a[m++]=a[i];
	a.resize(m);
	printf("%d %d\n",n,m);
	for (int i=0;i<SIZE(a);i++) printf("%d %d\n",a[i].first,a[i].second);
	return 0;
}