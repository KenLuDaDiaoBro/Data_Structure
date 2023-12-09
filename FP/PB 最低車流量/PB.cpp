#include <iostream>
using namespace std;
const int INF = 0x3f3f3f3f;
int arr[200][200];
int l = 7;

void Floyd()
{
	for(int now = 1 ; now <= l ; now++)
	{
		for(int i = 1 ; i <= l ; i++)
		{
			for(int j = 1 ; j <= l ; j++)
			{
				int max = arr[i][now];
				if(arr[i][now] < arr[now][j])
				{
					max = arr[now][j];
				}
				if(max < arr[i][j])
				{
					arr[i][j] = max;
				}
			} 
		}
	}
}

int main(int argc, char** argv) 
{
	for(int i = 1 ; i <= l ; i++)
	{
		for(int j = 1 ; j <= l ; j++)
		{
			arr[i][j] = INF;
		}
	}
	arr[1][2] = arr[2][1] = 50;
	arr[1][3] = arr[3][1] = 60;
	arr[2][4] = arr[4][2] = 120;
	arr[2][5] = arr[5][2] = 90;
	arr[3][6] = arr[6][3] = 50;
	arr[4][6] = arr[6][4] = 80;
	arr[4][7] = arr[7][4] = 70;
	arr[5][7] = arr[7][5] = 40;
	arr[6][7] = arr[7][6] = 140;
	for(int i = 1 ; i <= 7 ; i++)
	{
		arr[i][i] = 0;
	}
	Floyd();
	
	int t;
	cin >> t;
	while(t > 0)
	{
		int start , end;
		cin >> start >> end;
		int result = arr[start][end];
		if(result == INF)
		{
			cout << "no path" << endl;
		}
		else
		{
			cout << result << endl;
		}
		t--;
	}
	return 0;
}
