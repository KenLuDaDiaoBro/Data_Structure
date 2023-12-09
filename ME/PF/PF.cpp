#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv) 
{
	int t;
	cin >> t;
	while(t > 0)
	{
		string s;
		cin >> s;
		int len = s.length();
		int step = 1;
		int num;
		int A = 0;
		bool Pass = true;
		while(step < len && Pass == true)
		{
			num = s[A] - '0';
			s[A] = '-';
			A = (A + num) % len;
			if(s[A] != '-')
			{
				step ++;
			}
			else
			{
				Pass = false;
			}
		}
		if(Pass == true)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
		t--;
	}
	return 0;
}
