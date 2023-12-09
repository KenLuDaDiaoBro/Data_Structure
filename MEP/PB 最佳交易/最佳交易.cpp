#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char** argv) 
{
	int t ;
	cin >> t;
	while(t > 0)
	{
		int L ;
		cin >> L;
		int Q[L];
		for(int i = 0;i < L ; i++)
		{
			cin >> Q[i];
		} 
		int Ans = 0;
		for(int i = L - 1;i > 0 ; i--)
		{
			for(int j = i - 1;j >= 0; j--)
			{
				if(Q[i] - Q[j] > Ans)
				{
					Ans = Q[i] - Q[j];
				}
			}
		} 
		cout << Ans << endl;
		t -= 1;
	}
	return 0;
}
