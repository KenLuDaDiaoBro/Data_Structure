#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv) 
{
	int m , n;
	cin >> m;
	cin >> n;
	int A [m][n] ;
	for(int i = 0 ; i < m ; i++)
	{
		for(int j = 0 ; j < n ; j++)
		{
			cin >> A[i][j];
		}
	}
	
	int p , q;
	cin >> p;
	cin >> q;
	int B [p][q];
	for(int i = 0 ; i < p ; i++)
	{
		for(int j = 0 ; j < q ; j++)
		{
			cin >> B[i][j];
		}
	}
	
	int Ans[m][q];
	for(int i = 0 ; i < m ; i++)
	{
		for(int j = 0 ; j < q ; j++)
		{
			int C = 0;
			for(int k = 0 ; k < n ; k++)
			{
				C += A[i][k] * B[k][j];
			}
			Ans[i][j] = C;
		}
	}
	
	for(int i = 0 ; i < m ; i++)
	{
		cout << Ans[i][0];
		for(int j = 1 ; j < q ; j++)
		{
			cout << " " << Ans[i][j];
		}
		cout << endl;
	}
	return 0;
}
