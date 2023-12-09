#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
	int t;
	cin >> t;
	while(t > 0)
	{
		string Q;
		cin >> Q;
		int ODD = 0;
		int EVEN = 0;
		for (int i = 0;i < Q.length();i++)
		{
			if(i % 2 == 0)
			{
				ODD = ODD + Q[i] - '0' ;
			}
			else
			{
				EVEN = EVEN + Q[i] - '0';
			}
		}
		if(ODD == EVEN)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
		t -= 1;
	}
	return 0;
}
