#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
	int score[5];
	int ToTle = 0;
	for(int i = 0 ; i < 5 ; i++)
	{
		cin >> score[i];
		cout << "��" << i + 1 << "��ǥͪ����ƬO" << score[i] << endl;
		ToTle += score[i]; 
	} 
	cout << "5��ǥͪ��`���O" << ToTle << "��" << endl;
	system("pause"); 
	return 0;
}
