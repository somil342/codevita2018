// OBSTACLE GAME

#include "bits/stdc++.h"
using namespace std;
char arr[21][21];                  // storing given matrix
int twod[21][21]={0};             // to make sure every "R" is not traversed twice.
bool surround(int n,int i,int j)     
{
	bool boo=false;
	int limit=n-1;
	char s[8]; int p=0;
	if(j-1>=0)  // left 
	{s[p]=arr[i][j-1];p++;}
	if(i+1<=limit)       // down
	{s[p]=arr[i+1][j]; p++;}
	if(i+1<=limit && j-1>=0)   // bottom-left
	{s[p]=arr[i+1][j-1]; p++;}
	if(j+1<=limit)  //right
	{s[p]=arr[i][j+1]; p++;}
	if(i+1<=limit && j+1<=limit)  // bottom -right
	{s[p]=arr[i+1][j+1]; p++;}
	if(i-1>=0 && j+1<=limit)   // top-right
	{s[p]=arr[i-1][j+1]; p++;}
	if(i-1>=0)    // top
	{s[p]=arr[i-1][j]; p++;}
	if(i-1>=0 && j-1>=0)   //top -left
	{s[p]=arr[i-1][j-1]; p++;}
	int index=p;
	int ans[4]={0};  
	
	for(p=0;p<index;p++)
	{
		if(s[p]=='L')ans[0]++;
		if(s[p]=='S')ans[1]++;
		if(s[p]=='T')ans[2]++;
		if(s[p]=='W')ans[3]++;
	}
		
		while(ans[0]--){ cout<<"L ";boo=true;}
		while(ans[1]--){ cout<<"S ";boo=true;}
		while(ans[2]--){ cout<<"T ";boo=true;}
		while(ans[3]--){ cout<<"W ";boo=true;}
twod[i][j]=1;
return boo;	
}
void fun(int n,int i,int j)
{
	if(j-1>=0 && arr[i][j-1]=='R' && twod[i][j-1]==0)  // left 
	{
		if( surround(n,i,j-1) ) cout<<endl;
		else cout<<"NO HURDLES"<<endl;
		fun(n,i,j-1);
	}
	if(i+1<=n-1 && j-1>=0  && arr[i+1][j-1]=='R' && twod[i+1][j-1]==0)   // bottom-left
	{
	    if( surround(n,i+1,j-1) ) cout<<endl;
		else cout<<"NO HURDLES"<<endl;
        fun(n,i+1,j-1);
	}	
	if(i+1<=n-1  && arr[i+1][j]=='R'  && twod[i+1][j]==0)       // down
	{
		if( surround(n,i+1,j) ) cout<<endl;
		else cout<<"NO HURDLES"<<endl;
	fun(n,i+1,j);
	}
	if(i+1<=n-1 && j+1<=n-1  && arr[i+1][j+1]=='R'  && twod[i+1][j+1]==0)  // bottom -right
	{
		if( surround(n,i+1,j+1) ) cout<<endl;
		else cout<<"NO HURDLES"<<endl;
	fun(n,i+1,j+1);
	}
	if(j+1<=n-1  && arr[i][j+1]=='R'  && twod[i][j+1]==0)  //right
	{
		if( surround(n,i,j+1) ) cout<<endl;
		else cout<<"NO HURDLES"<<endl;
	fun(n,i,j+1);
    }
	if(i-1>=0 && j+1<=n-1  && arr[i-1][j+1]=='R'  && twod[i-1][j+1]==0)   // top-right
	{
		if( surround(n,i-1,j+1) ) cout<<endl;
		else cout<<"NO HURDLES"<<endl;
	fun(n,i-1,j+1);
    }
	if(i-1>=0  && arr[i-1][j]=='R'  && twod[i-1][j]==0)    // top
	{
		if( surround(n,i-1,j) ) cout<<endl;
		else cout<<"NO HURDLES"<<endl;
	    fun(n,i-1,j);
	}
	if(i-1>=0 && j-1>=0  && arr[i-1][j-1]=='R'  && twod[i-1][j-1]==0)   //top -left
	{
	   if( surround(n,i-1,j-1) ) cout<<endl;
		else cout<<"NO HURDLES"<<endl;
	   fun(n,i-1,j-1);
	}
}
int main()
{
	int n;
	cin>>n;
	int i=0; int j=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}
fun(n,0,0);
	cout<<"DESTINATION";
	return 0;
}
