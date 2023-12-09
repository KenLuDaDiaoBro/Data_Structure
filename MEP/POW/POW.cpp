#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
	float X;
	int Y;
	cin >> X;
	cin >> Y;
	float num = 1;
	for(int i = 0 ; i < Y ; i++)
	{
		num *= X;
	} 
	cout << num << endl;
	return 0;
}
