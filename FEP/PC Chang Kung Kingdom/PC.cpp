#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
	int t;
	cin >> t;
	while(t > 0)
	{
		int destination[100];
		for(int i = 0 ; i < 3 ; i++)
		{
			cin >> destination[i];
		}
		int Long = 0;
		for(int i = 2 ; i > 0 ; i--)
		{
			for(int j = 1 ; j <= i ; j++)
			{
				if(destination[j] < destination[j - 1])
				{
					int tem = destination[j];
					destination[j] = destination[j - 1];
					destination[j - 1] = tem;
					Long++;
				}
			}
		}
		cout << Long << endl;
		t--;
	}
	return 0;
}
