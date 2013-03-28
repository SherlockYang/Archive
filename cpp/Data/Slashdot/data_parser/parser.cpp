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
//	freopen("..\\Slashdot\\st_data.txt","w",stdout);
	int n=0,m=0;
	vector<ipair> a;
	for (int u,v,c;scanf("%d%d%d",&u,&v,&c)!=-1;)
	{
		if (u>v) swap(u,v);
		if (u==v) continue;
		a.push_back(MP(u-1,v-1));
		if (u>n) n=u;
		if (v>n) n=v;
	}
	sort(a.begin(),a.end());
	for (int i=0;i<SIZE(a);i++) if (i==0 || a[i]!=a[i-1]) a[m++]=a[i];
	a.resize(m);
	printf("%d %d\n",n,m);
	for (int i=0;i<SIZE(a);i++) printf("%d %d\n",a[i].first,a[i].second);
	return 0;
}