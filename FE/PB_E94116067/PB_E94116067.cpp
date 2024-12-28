#include <iostream>
using namespace std;
int l , s , m;
const int INF = 0x3f3f3f3f;
int arr[200][200];

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
	int t;
	cin >> t;
	while(t > 0)
	{
		cin >> l >> s >> m;
		
		for(int i = 1 ; i <= l ; i++)
		{
			for(int j = 1 ; j <= l ; j++)
			{
				arr[i][j] = INF;
			}
		}
		
		for(int i = 0 ; i < s ; i++)
		{
			int st , en , we;
			cin >> st >> en >> we;
			arr[st][en] = arr[en][st] = we;
		}
		
		for(int i = 1 ; i <= l ; i++)
		{
			arr[i][i] = 0;
		}
		Floyd();
		while(m > 0)
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
			m--;
		}
		t--;
	}
	
	return 0;
}

