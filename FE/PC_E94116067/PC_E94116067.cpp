#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
	int t;
	cin >> t;
	while(t > 0)
	{
		int n;
		cin >> n;
		int arr[n];
		for(int i = 0 ; i < n ; i++)
		{
			cin >> arr[i];
		}
		int step = 0;
		for(int i = n - 1 ; i > 0 ; i--)
		{
			for(int j = 1 ; j <= i ; j++)
			{
				if(arr[j] < arr[j - 1])
				{
					int tem = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = tem;
					step++;
				}
			}
		}
		cout << step << endl;
		t--;
	}
	return 0;
}
