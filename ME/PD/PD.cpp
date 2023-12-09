#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
	int t;
	cin >> t;
	while(t > 0)
	{
		int num;
		cin >> num;
		int all [num];
		for(int i = 0 ; i < num ; i++)
		{
			cin >> all[i];
		}
		int fir;
		int end;
		int len;
		int high;
		int range;
		int max = 0;
		for(int i = 0 ; i < num - 1 ; i++)
		{
			fir = all[i];
			for(int j = i + 1 ; j < num ; j++)
			{
				end = all[j];
				len = j - i;
				if(all[i] >= all[j])
				{
					high = all[j];
				}
				else
				{
					high = all[i];
				}
				range = len * high;
				if(range >= max)
				{
					max = range;
				}
			}
		}
		cout << max << endl;
		t--;
	} 
	return 0;
}
