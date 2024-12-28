#include <iostream>
using namespace std;
int n , a , b;

int main(int argc, char** argv) 
{
	cin >> n >> a >> b;
	int arr[n + 1];
	for(int i = 1 ; i <= n ; i++)
	{
		arr[i] = 0;
	}
	
	int pt = 0;
	int now = a;
	int out = 0;
	while(out < n)
	{
		while(arr[now] == -1)
		{
			now++;
			if(now > n)
			{
				now = 1;
			}
		}	
		pt++;
		if(pt == b)
		{
			arr[now] = -1;
			pt = 0;
			out++;
			cout << now;
			if(out < n)
			{
				cout << " ";
			}
		}
		now++;
		if(now > n)
		{
			now = 1;
		}
	}
	cout << endl;
	return 0;
}
