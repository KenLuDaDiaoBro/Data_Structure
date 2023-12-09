#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
	int row , colomn;
	scanf("%d %d" , &row , &colomn);
	int M1[colomn][row];
	string M;
	string tem;
	for(int i = 0 ; i < row; i++)
	{
		for(int j = 0 ; j < colomn; j++)
		{
			cin >> M1[j][i];
		}
	}
	for (int i = 0 ; i < colomn ; i++)
	{
		printf("%d" , M1[i][0]);
		for(int j = 1 ; j < row ; j++)
		{
			printf(" %d" , M1[i][j]);
		}
		printf("\n");
	}
	return 0;
}
