#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

map<int,int> M;
char s[1000000];
set<pair<int,int> > S;

int get_id(int s)
{
	if (M.find(s)!=M.end()) return M[s];
	int size=M.size();
	M[s]=size;
	return size;
}
int main()
{
	freopen("..\\GCRBC.txt","r",stdin);
	freopen("..\\gc_data.txt","w",stdout);
	while (1)
	{
		gets(s);
		string str=s;
		str=str.substr(0,15);
		if (str=="## Coauthor Map") break;
	}
	while (1)
	{
		s[0]=0;
		gets(s);
		if (s[0]==0) break;
		for (int i=0;s[i];i++) if (s[i]==',') s[i]=' ';
		istringstream sin(s);
		int a,b;
		sin>>a>>b;
		a=get_id(a);
		b=get_id(b);
		if (a>b) swap(a,b);
		if (a==b) continue;
		S.insert(make_pair(a,b));
	}
	printf("%d %d\n",(int)M.size(),(int)S.size());
	for (set<pair<int,int> >::iterator it=S.begin();it!=S.end();++it)
		printf("%d %d\n",it->first,it->second);
	return 0;
}