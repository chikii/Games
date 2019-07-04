/*
inclusive x and y
i.e. from x to y how many numbers r prime n happy say..i
n is a n.th number in i.
ex = x = 20 y = 100 n = 2
i = 23 31 79 97  
so answer is 31.
if n = 1
so answer is 23.
if n is 5
then answer is No.
*/

#include<bits/stdc++.h>
using namespace std;

bool isPrime(int);
bool isHappy(int);

int main()
{
	int x,y,n;
	cin>>x>>y>>n;
	int count =0;
	for(int i =x;i<=y;i++)
	{
		if (isPrime(i) && isHappy(i))
			count++;
		if(count==n)
		{
			cout<<i;
			break;
		}
	}
	if(count!=n)
		cout<<"NO";
}
bool isPrime(int n)
{
	for(int i = 2 ; i <= sqrt(n) ; i++)
	{
		if (n%i==0)
			return false;
	}
	return true;
}
bool isHappy(int n)
{
	int sum =0 ;
	while(n>0)
	{
		sum += (n%10)*(n%10);
		n = n/10;
	}
	if (sum==1)
		return true;
	else if (sum==4)
		return false;
	isHappy(sum);
}
