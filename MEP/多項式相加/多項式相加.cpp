#include <iostream>
using namespace std;

int *SoRt(int Arr[] , int num)
{
	num = num / 2;
	for(int i = 1 ; i < num ; i++)
	{
		if(Arr[2 * i + 1] > Arr[2 * (i - 1) + 1])
		{
			int temp = Arr[2 * (i - 1) + 1];
			Arr[2 * (i - 1) + 1] = Arr[2 * i + 1];
			Arr[2 * i + 1] = temp;
			
			temp = Arr[2 * (i - 1)];
			Arr[2 * (i - 1)] = Arr[2 * i];
			Arr[2 * i] = temp;
		}
	}
	return Arr;
}
int main(int argc, char** argv) 
{
	int Max_Size = 0;
	int num_A , num_B;
	cin >> num_A;
	int Arr[2 * num_A];
	for(int i = 0 ; i < 2 * num_A ; i++)
	{
		cin >> Arr[i];
		if(i % 2 == 1 && Arr[i] > Max_Size)
		{
			Max_Size = Arr[i];
		}
	}
	int *temp_A = SoRt(Arr , 2 * num_A);
	
	cin >> num_B;
	int Brr[2 * num_B];
	for(int i = 0 ; i < 2 * num_B ; i++)
	{
		cin >> Brr[i];
		if(i % 2 == 1 && Brr[i] > Max_Size)
		{
			Max_Size = Brr[i];
		}
	}
	int *temp_B = SoRt(Brr , 2 * num_B);
	
	Max_Size ++;
	int Ans [Max_Size];
	for(int i = 0 ; i < Max_Size ; i++)
	{
		Ans[i] = 0;
		for(int j = 1 ; j < num_A  * 2; j += 2)
		{
			if(temp_A[j] == i)
			{
				Ans[i] += temp_A[j - 1];
			}
		}
		for(int j = 1 ; j < num_B  * 2; j += 2)
		{
			if(temp_B[j] == i)
			{
				Ans[i] += temp_B[j - 1];
			}
		}
	}  
	
	int Max = Max_Size - 1;
	while(Ans[Max] == 0)
	{
		Max--;
	}
	cout << Ans[Max] << "x^" << Max;
	for(int i = Max - 1; i >= 0 ; i--)
	{
		if(Ans[i] != 0)
		{
			cout << "+" << Ans[i];
			if(i != 0)
			{
				cout << "x^" << i;
			}
		} 
	}
	cout << endl;
	return 0;
}
