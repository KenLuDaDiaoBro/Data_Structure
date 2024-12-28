#include <iostream>
using namespace std;

int tri(int** arr , int row , int col , int r , int c , int l)
{
	int brr[row][col];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			brr[i][j] = arr[i][j];
		}
	}
	if(r + l == row || c + l == col)
	{
		return 0;	
	}
	else
	{
		bool suc = true;
		for(int i = 0 ; i <= l ; i++)
		{
			if(brr[r + i][c + l] != 1)
			{
				suc = false;
			}
			if(brr[r + l][c + i] != 1)
			{
				suc = false;
			}
		}
		if(suc == true)
		{
			return tri(arr , row , col , r , c , l + 1) + 1;
		}
		else
		{
			return 0;
		}
	}
}

int main(int argc, char** argv) 
{
	int row;
	int col;
	cin >> row;
	cin >> col;
	int arr [row][col];
	for(int r = 0 ; r < row ; r++)
	{
		for(int c = 0 ; c < col ; c++)
		{
			cin >> arr[r][c];
		}
	}
	
	int result = 0;
	int* p1[row];
	for (int i = 0; i < row; i++)
	{
		p1[i] = arr[i];
	}

	for(int r = 0 ; r < row ; r++)
	{
		for(int c = 0 ; c < col ; c++)
		{
			if(arr[r][c] == 1)
			{
				int tem = tri(p1 , row , col , r , c , 1) + 1;
				if(tem > result)
				{
					result = tem;
				}
			}
		}
	}
	cout << result * result << endl;
	return 0;
}

