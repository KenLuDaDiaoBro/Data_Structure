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
		char jj [len];
		int counter = 0;
		for(int i = 0 ; i < len ; i ++)
		{
			switch(s[i])
			{
				case'[':
					jj[counter] = s[i];
					counter++;
					break;
				case'(':
					jj[counter] = s[i];
					counter++;
					break;
				case']':
					if(jj[counter - 1] == '[') 
					{
						counter--;
					}
					else
					{
						jj[counter] = s[i];
						counter++;
					}
					break;
				case')':
					if(jj[counter - 1] == '(') 
					{
						counter--;
					}
					else
					{
						jj[counter] = s[i];
						counter++;
					}
					break;
			}
		}
		if(counter == 0)
		{
			cout << "VALID" << endl;
		}
		else
		{
			cout << "NOT VALID" << endl;
		}
		t--;
	}
	return 0;
}
