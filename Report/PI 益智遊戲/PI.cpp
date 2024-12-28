#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
	int l;
	cin >> l;
	int block;
	cin >> block;
	int arr[block];
	int free = 0;
	for(int i = 0 ; i < block ; i++)
	{
		cin >> arr[i];
		free += arr[i];
	}
	free = l - free - block + 1;
	//cout << free;
	int ans[l];
	int now = 0;
	for(int i = 0 ; i < block ; i++)
	{
		for(int j = 0 ; j < arr[i] ; j++)
		{
			if(j < free)
			{
				ans[now] = 0;
			}
			else
			{
				ans[now] = 1;
			}
			now ++;
		}
		ans[now] = 0;
		now ++;
	}
	now--;
	for(int i = now ; i < l ; i++)
	{
		ans[i] = 0;
	}
	
	cout << ans[0];
	for(int i = 1 ; i < l ; i++)
	{
		cout << " " << ans[i];
	}
	cout << endl;
	return 0;
}
