#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
	int arr [2][2];
	for(int i = 0 ; i < 2 ; i++)
	{
		for(int j = 0 ; j < 2 ; j++)
		{
			cin >> arr[i][j];
		}
	}
	for(int i = 0 ; i < 2 ; i++) 
	{
		cout << "|" << arr[i][0] << " " << arr[i][1] << "|" << endl; 
	}
	int sum = (arr[0][0] * arr[1][1]) - (arr[1][0] * arr[0][1]);
	cout << "Sum = " << sum << endl;
	return 0;
}
