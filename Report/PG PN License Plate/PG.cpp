#include <iostream>
using  namespace std;

int main(int argc, char** argv) 
{
	int l;
	cin >> l;
	int sort[140608];
	int order[l + 1][2];
	for(int i = 0 ; i <= l ; i++)
	{
		sort[i] = 0;
	}
	for(int i = 1 ; i <= l ; i++)
	{
		string plate;
		//cin >> plate;
		plate = "AAA";
		int num = 0;
		for(int j = 0 ; j < 3 ; j++) //int j = 0 ; j < 3 ; j++    int j = 2 ; j >= 0 ; j--
		{
			num *= 52;
			if(plate[j] - 'A' > 25)
			{
				num += (plate[j] - 'a') + 26;
				// + 26
				// * 2 + 1
			}
			else
			{
				num += (plate[j] - 'A');
				// * 2
			}
		}
		num = l - i;
		sort[num] = -1;
		order[i][0] = num * -1;
		order[i][1] = 0;
	}
	
	int now = 1;
	for(int i = 0 ; i < 140608 ; i++)
	{
		if(sort[i] == -1)
		{
			for(int j = 1 ; j <= l ; j++)
			{
				if(order[j][0] * -1 == i)
				{
					order[j][0] = now;
					now++;
				}
			}
		}
	}
	//for(int i = 1 ; i <= l ; i++)
	//{
	//	cout << order[i][0] << " ";
	//}
	
	int weight = 0;
	int t = 0;
	for(int i = 1 ; i <= l ; i++)
	{               //¶Ã«× 
		int add = (order[i][0] - i) + weight;
		t += add;
		order[i + add][1]--;
		weight += 1 + order[i][1];
	}
	
	cout << t << endl;
	return 0;
}
