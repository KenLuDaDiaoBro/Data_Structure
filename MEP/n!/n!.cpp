#include <iostream>
using namespace std;
void fs(int n , int t)
{
	if(t == 1)
	{
		cout << n << endl;
	}
	else
	{
		n *= t - 1;
		t--;
		fs(n , t);
	}
}

int main(int argc, char** argv) 
{
	int n;
	cin >> n;
	if(n == 0)
	{
		cout << 1 << endl;
	}
	else if (n > 0)
	{
		fs(n , n);
	}
	else
	{
		cout << "§A¥L¶ý" << endl; 
	}
	return 0;
}
