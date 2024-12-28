#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv) 
{
	int t;
	cin >> t;
	for(int i = 1 ; i <= t ; i++)
	{
		string a;
		cin >> a;
		int len = a.size();
		int arr[10 + 26 + 26];
		for(int j = 0 ; j < 62 ; j++)
		{
			arr[j] = 0;
		}
		
		for(int j = 0 ; j < len ; j++)
		{
			if(0 <= a[j] - '0' && a[j] - '0' <= 9)
			{
				arr[a[j] - '0']++;
				cout <<"00";
			}
			else if(0 <= a[j] - 'A' && a[j] - 'A' <= 25)
			{
				arr[a[j] - '0' + 10]++;
				cout <<"01";
			}
			else if(0 <= a[j] - 'a' && a[j] - 'a' <= 25)
			{
				arr[a[j] - '0' + 62]++;
				cout <<"02";
			}
		}
		cout << "Case " << i << ": "; 
		for(int j = 0 ; j < 62 ; j++)
		{
			char ch;
			if((arr[j] == 2) || (arr[j] == 3) || (arr[j] == 5) || (arr[j] == 7))
			{
				if(j <= 9)
				{
					ch = '0' + j;
					cout << ch;
				}
				else if(j <= 35)
				{
					ch = 'A' + j - 27;
					cout << ch;
				}
				else if(j <= 61)
				{
					ch = 'a' + j;
					cout << ch;
				}
			}
		}
		cout << endl;
	}
	return 0;
}
