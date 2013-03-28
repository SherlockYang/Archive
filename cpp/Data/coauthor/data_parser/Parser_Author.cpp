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
	while (1)
	{
		gets(s);
		string str=s;
		str=str.substr(0,15);
		if (str=="## Author Map #") break;
	}
	map<int,string> M2;
	while (1)
	{
		s[0]=0;
		gets(s);
		if (s[0]==0) break;
		string str=s;
		str=str.substr(0,15);
		if (str=="## Coauthor Map") break;
		int p1=0,p2=0;
		for (;s[p1]!='\t';p1++);
		for (p2=p1+1;s[p2]!='\t' && s[p2]!=0;p2++);
		str=s;
		M2[atoi(str.substr(0,p1).c_str())]=str.substr(p1+1,p2-p1-1);
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
	}
	map<int,string> M3;
	for (map<int,string>::iterator it=M2.begin();it!=M2.end();++it)
		if (M.find(it->first)!=M.end())
			M3[M[it->first]]=it->second;
	freopen("..\\gc_authors.txt","w",stdout);
	for (map<int,string>::iterator it=M3.begin();it!=M3.end();++it)
		printf("%d %s\n",it->first,it->second.c_str());
	return 0;
}