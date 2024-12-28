#include <iostream>
#include <list>
using namespace std;

int main(int argc, char** argv) 
{
	int t;
	cin >> t;
	int matrix [t][2];
	string alpha;
	for(int i = 0 ; i < t ; i++)
	{
		cin >> alpha;
		cin >> matrix [i][0];
		cin >> matrix [i][1];
	}
	
	cin >> t;
	while(t > 0)
	{
		cin >> alpha;
		int l = 0;
		int tem [alpha.length()][2];
		int all = 0;
		bool success = true;
		int first_row;
		int first_col;
		int second_row;
		int second_col;
		for(int i = 0; i < alpha.length() ; i ++)
		{
			switch(alpha[i])
			{
				case '(':
					break;
				case ')':
					l = l - 2;
					first_row = tem[l][0];
					first_col = tem[l][1];
					second_row = tem[l + 1][0];
					second_col = tem[l + 1][1];
					if(first_col == second_row)
					{
						tem[l][1] = second_col;
						all += first_row * second_col * first_col;
						l++;
					}
					else
					{
						success = false;
					}
					break;
				default:
					tem[l][0] = matrix [alpha[i] - 'A'][0];
					tem[l][1] = matrix [alpha[i] - 'A'][1];
					l++;
					break;	
			}
		}
		
		if(success == true)
		{
			cout << all << endl;
		}
		else
		{
			cout << "error" << endl;
		}
		t--;
	}
	return 0;
}
