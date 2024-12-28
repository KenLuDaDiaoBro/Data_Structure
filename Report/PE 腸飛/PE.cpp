#include <iostream>
using namespace std;
//1A 2B 3All 4Next 5Step

long long find(int** ch , int M , int N , bool up)
{
	if(N > 0)
	{
		int l = 2 * M - 1;
		int CH[5][l];
		for(int i = 0 ; i < 5 ; i++)
		{
			for(int j = 0 ; j < l ; j++)
			{
				CH[i][j] = ch[i][j];
				//cout << CH[i][j] << " ";
			}
			//cout << endl;
		}
		int max = 0;
		int Mid = M - 1;
		int now = Mid;
		while(now >= 0)
		{
			for(int i = 0 ; i <= now ; i++)
			{
				int nowl = now - i;
				int nowr = now - nowl;
				int step;
				if(nowl > nowr)
				{
					step = nowl + nowr * 2;
				}
				else
				{
					step = nowl * 2 + nowr;
				}
				//cout << "l: " << nowl << " r: " << nowr << endl;
				if(step <= Mid)
				{
					for(int i = 0 ; i < 5 ; i++)
					{
						for(int j = 0 ; j < l ; j++)
						{
							CH[i][j] = ch[i][j];
						}
					}
					
					int All;
					int All_step = 0;
					int L = Mid - nowl;
					int R = Mid + nowr;
					for(int j = L ; j <= R ; j++)
					{
						All_step += CH[4][j];
					}
					while(All_step + step + 1 <= N)
					{
						int max_v = -1;
						int max_i;
						for(int j = L ; j <= R ; j++)
						{
							if(max_v < CH[3][j] && CH[3][j] <= CH[0][j])
							{
								max_v = CH[3][j];
								max_i = j;
							}
						}
						CH[4][max_i]++;
						CH[2][max_i] += CH[3][max_i];
						CH[3][max_i] -= CH[1][max_i];
						if(CH[3][max_i] < 0)
						{
							CH[3][max_i] = 0;
						}
						All = 0;
						All_step = 0;
						for(int j = L ; j <= R ; j++)
						{
							All += CH[2][j];
							All_step += CH[4][j];
						}
					}
					for(int i = 0 ; i < 5 ; i++)
					{
						for(int j = 0 ; j < l ; j++)
						{
							//cout << CH[i][j] << " ";
						}
						//cout << endl;
					}
					if(All > max)
					{
						max = All;
					}
				}
			}
			now--;
		}
		return max;
	}
	else
	{
		return 0;
	}
	
}

int main(int argc, char** argv) 
{
	int M;
	cin >> M;
	int N;
	cin >> N;
	int CH[5][2 * M - 1];
	for(int i = 0 ; i < 2 ; i++)
	{ 
		for(int j = M - 1 ; j < 2 * M - 1 ; j++)
		{
			cin >> CH[i][j];
		}
	}
	
	for(int i = M - 1 ; i < 2 * M - 1 ; i++)
	{
		CH[2][i] = 0; //All = 0
		CH[3][i] = CH[0][i]; // Next = A
		CH[4][i] = 0; // step = 0
	}
	
	for(int i = 0 ; i < 5 ; i++)
	{
		for(int j = 0 ; j < M - 1 ; j++)
		{
			CH[i][j] = CH[i][j + M];
		}
	}
	int* ch[5];
	for(int i = 0 ; i < 5 ; i++)
	{
		int* p = CH[i];
		ch[i] = p;
	}
	long long max = find(ch , M , N , true);
	cout << max << endl;
	
	return 0;
}
