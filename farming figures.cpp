// FARMING FIGURES

// for polygon ,each side must be less than sum of all other sides.
// and if we check only for longest side then no need to check for all other sides

#include "bits/stdc++.h"
using namespace std;
int main()
{
	int sides;
	cin>>sides;
	int polys[sides];
	int p=0;  int add=0;   // add variable having sum of all sides
	while(p<sides)
	{
	  cin>>polys[p];		  
	  add+=polys[p];
	  p++;
	}
	sort(polys,polys+sides);      // sorting to get longest side only
//	for(p=sides-1;p>=0;p--)
//	{
//		cout<<polys[p]<<" ";
//	}
	//cout<<endl;
	for(p=sides-1;p>=2;p--)      
	{
		if(polys[p]<(add-polys[p]))     
		{
			cout<<p+1;
			return 0;
		}
		add=add-polys[p];
	}
	
	cout<<"0";
	return 0;
}
