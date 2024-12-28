#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv) 
{
	int t;
	cin >> t;
	while(t > 0)
	{
		int l;
		cin >> l;
		int arr[l];
		string brr[l];
		for(int i = 0 ; i < l ; i++)
		{
			cin >> arr[i];
			
		}
		for(int i = 0 ; i < l ; i++)
		{
			cin >> brr[i];
		}
		
		int step = 0;
		int pow = 1;
		while(pow <= l)
		{
			pow *= 2;
			step++;
		}
		
		int p = 2
		for(int i = 0 ; i < (l / p) ; i++)
		{
			for(int j = i * 2)
		}
		t--;
	}
	return 0;
}
