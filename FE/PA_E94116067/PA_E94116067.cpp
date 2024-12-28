#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv) 
{
	int t;
	cin >> t;
	while(t > 0)
	{
		string q;
		cin >> q;
		int len = q.size();
		int op = 1;
		int odd = 0;
		int even = 0;
		
		for(int i = 0 ; i < len ; i++)
		{
			int asc = q[i] - '0';
			if(0 <= asc && asc <= 9)
			{
				if(op == 1)
				{
					odd += asc;
				}
				else if(op == -1)
				{
					even += asc;
				}
				op *= -1;
			}
		}
		
		int ll = (odd - even) % 11;
		
		if(ll == 0)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
		t--;
	}
	return 0;
}
