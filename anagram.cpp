#include<bits/stdc++.h>
using namespace std;

string checkAnagram(string& a, string& b);
int token(string&);
void stringConvert(string& a , string& b);
int main()
{
	string a,b;
	getline(cin,a);
	getline(cin,b);	

	cout<<checkAnagram(a,b);
	cout<<endl;
	cout<<token(a);
}
int token(string& a)
{
	map<char,bool> LetterLength;
	int count=0;
	for(int i =0 ;i<a.length();i++)
	{
		if(!LetterLength[a[i]])
		{
			LetterLength[a[i]]=true;
			count++;
		}
	}
	return count;
}
string checkAnagram(string& a,string& b)
{
	stringConvert(a,b);
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int count1=0,count2=0;
	for(int i=0,j=0;  ; i++,j++)
	{
		while(a[i]==32)
		{
			count1++;
			i++;
		}
		while(b[j]==32)
		{
			count2++;
			j++;
		}
		if((a[i]!=32)&&(b[j]!=32))
		 break;
	}
	int B = count1-count2;
	if(B<0)
		B = -B;

	if(a.length() != b.length()-B)
		return "Not an anagram.";
		
	for(int i =0, j=0 ; a[i]!='\0' ; i++,j++)
	{
		while(a[i]==32 )
			i++;
		while(b[j]==32)
			j++;
		if(a[i]-b[j] != 0)
		{
			return "Not an anagram.";
		}	
	}
	return "Anagram.";
}
void stringConvert(string& a , string& b)
{
	for (int i =0 ; i<a.length();i++)
		a[i]=tolower(a[i]);
	for(int j=0 ; j<b.length();j++)
		b[j]=tolower(b[j]);
}
