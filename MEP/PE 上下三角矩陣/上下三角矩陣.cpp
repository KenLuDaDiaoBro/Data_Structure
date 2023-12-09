#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
	int t;
	cin >> t;
	while(t > 0)
	{
		int M[25];
		for(int i = 0 ; i < 25 ; i++)
		{
			cin >> M[i];
		}
		int U = M[1]  + M[2] + M[3] + M[4] + M[7] + M[8] + M[9] + M[13] + M[14] + M[19];
		int L = M[5]  + M[10] + M[11] + M[15] + M[16] + M[17] + M[20] + M[21] + M[22] + M[23];
		if(U > 0 && L == 0)
		{
			cout << 0 << endl;
		}
		else if(U == 0 && L > 0)
		{
			cout << 1 << endl;
		}
		else
		{
			cout << -1 << endl;
		}
		t -= 1;
	} 
	return 0;
}
