#include <iostream>
using namespace std;
void hanoi(char A , char B , char C , int n)
{
	if(n == 1)
	{
		cout << A << " -> " << C << endl;
	}
	else
	{
		hanoi(A , C , B , n - 1);
		cout << A << " -> " << C << endl;
		hanoi(B , A , C , n - 1);
	}
}
int main(int argc, char** argv) 
{
	char A = 'A';
	char B = 'B';
	char C = 'C';
	int n;
	cin >> n ;
	hanoi(A , B , C , n);
	return 0;
}
