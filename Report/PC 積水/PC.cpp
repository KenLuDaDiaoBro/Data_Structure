#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
	int n;
	cin >> n;
	int water[n];
	for(int i = 0 ; i < n ; i++)
	{
		cin >> water[i];
	}
	
	int apex[n];
	int s = 0;
	if(water[0] >= water[1])
	{
		apex[0] = 0;
		s++;
	}
	for(int i = 1 ; i < n - 1 ; i++)
	{
		if(water[i] >= water [i - 1] && water[i] >= water[i + 1])
		{
			apex[s] = i;
			s++;
		}
	}
	if(water[n] >= water[n - 1])
	{
		apex[s] = n - 1;
		s++;
	}
	
	int all = 0;
	for(int i = 0 ; i < s - 1 ; i++)
	{
		int p1 = apex[i];
		int p2 = apex[i + 1];
		int h = water[apex[i]];
		if(water[apex[i]] > water[apex[i + 1]])
		{
			h = water[apex[i + 1]];
		}
		for(int k = p1 ; k <= p2 ; k++)
		{
			if(h >= water[k])
			{
				all += h - water[k];
			}
		}
	}
	cout << all << endl;
	return 0;
}
