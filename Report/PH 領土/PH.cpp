#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
	int row , col;
	cin >> row >> col; 
	int arr[row][col];
	for(int i = 0 ; i < row ; i++)
	{
		for(int j = 0 ; j < col ; j++)
		{
			cin >> arr[i][j];
		}
	}
	
	string re[row][col];
	for(int i = 0 ; i < row ; i++)
	{
		for(int j = 0 ; j < col ; j++)
		{
			bool edge = false;
			if(arr[i][j] == 1)
			{
				if(j != 0 && arr[i][j - 1] == 0)
				{
					edge = true;
				}
				if((j + 1) != col && arr[i][j + 1] == 0)
				{
					edge = true;
				}
				if(i != 0 && arr[i - 1][j] == 0)
				{
					edge = true;
				}
				if((i + 1) != row && arr[i + 1][j] == 0)
				{
					edge = true;
				}
			}
			if(edge == true)
			{
				re[i][j] = "0";
			}
			else
			{
				re[i][j] = "_";
			}
		}
	}
	
	for(int i = 0 ; i < row ; i++)
	{
		cout << re[i][0];
		for(int j = 1 ; j < col ; j++)
		{
			cout << " " << re[i][j];
		}
		cout << endl;
	}
	return 0;
}
