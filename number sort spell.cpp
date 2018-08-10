//NUMBER SORT SPELL
// reference
// https://www.geeksforgeeks.org/program-to-convert-a-given-number-to-words-set-2/

#include "bits/stdc++.h"
using namespace std;
#define huge long
string ek[] = { "", "one ", "two ", "three ", "four ",
                 "five ", "six ", "seven ", "eight ",
                 "nine ", "ten ", "eleven ", "twelve ",
                 "thirteen ", "fourteen ", "fifteen ",
                 "sixteen ", "seventeen ", "eighteen ",
                 "nineteen "
               };
string das[] = { "", "", "twenty ", "thirty ", "forty ",
                 "fifty ", "sixty ", "seventy ", "eighty ",
                 "ninety "
               };
string itoW(int z, string previous)
{
    string line = "";
    if (z > 19)
        line += das[z / 10] + ek[z % 10];
    else
        line += ek[z];
    if (z)
        line += previous;
 
    return line;
}

string LETTER(huge flex)
{
    string screen;
    screen += itoW((flex / 10000000), "crore ");
    screen += itoW(((flex / 100000) % 100), "lakh ");
    screen += itoW(((flex / 1000) % 100), "thousand ");
    screen += itoW(((flex / 100) % 10), "hundred ");
    if (flex > 100)
    {
    	if(flex % 100)
        screen += "and ";
    }
    screen += itoW((flex % 100), ""); 
    return screen;
}

bool  btao (huge n,huge m)
{
if( n>99999 || m>99999)
return true;
 return false;
}

int main()
{
    bool boo=false;
    huge  n,m,answer;
    cin>>n>>m;
    
    if(btao(n,m))
    {
    	cout<<"Out of bounds";
	}
    
	else if(n==m)
	{
		cout<<n;
	}
	else
{
	
	
   if(n>m)
    {
    	huge temp=m;
    	m=n;
    	n=temp;
	}
	
    while(1)
    {
	
    string s1=LETTER(n) ;
	string s2= LETTER(m) ;
	if(s1<s2)
	{
		n=n+n;
		m=m+m;
			if(btao(n,m))
     		{	  
    			cout<<"Out of bounds";
    			boo=true;
    			break;
	  		}
	}
	else
	{
		answer=n+m;
		if(answer>99999)
		{
			cout<<"Out of bounds";
			boo=true;
		}
          break;		
	}
   }
   
if(boo==false)
cout<<answer;

}
    return 0;
}

