#include <iostream>
using namespace std;

unsigned long long F(unsigned long long n)
{
	if(n >= 19)
	{
		return 0;
	}
	else if(n == 1 || n == 0)
	{
		return 1;
	}
	else
	{
		return n * F(n - 1);
	}
}

unsigned long long G(unsigned long long n)
{
	if(n == 1 || n == 2)
	{
		return 1;
	}
	else if(n == 0)
	{
		return 0;
	}
	else
	{
		return G(n - 1) + G(n - 2);
	}
}

int main(int argc, char** argv) 
{
	int t;
	cin >> t;
	while(t > 0)
	{
		unsigned long long s;
		cin >> s;
		unsigned long long f = F(s);
		unsigned long long k = f % 19;
		cout << G(k) << endl;
		t--;
	}
	return 0;
}
