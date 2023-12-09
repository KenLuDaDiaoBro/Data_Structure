#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv) 
{
	int t ;
	cin >> t;
	while(t > 0)
	{
		string s;
		cin >> s;
		int len = s.length();
		int Odd = 0;
		int Even = 0;
		bool f = false;
		for(int i = 0 ; i < len ; i++)
		{
			if(s[i] != '.')
			{
				if(f == false)
				{
					if(i % 2 == 0)
					{
						Odd += s[i] - '0';
					}
					else
					{
						Even += s[i] - '0';
					}
				}
				else
				{
					if(i % 2 == 0)
					{
						Even += s[i] - '0';
					}
					else
					{
						Odd += s[i] - '0';
					}
				}
			}
			else
			{
				f = true;
			}
		}
		int Sub = Odd - Even;
		if(Sub % 11 == 0)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
		t--	;
	} 
	return 0;
}
