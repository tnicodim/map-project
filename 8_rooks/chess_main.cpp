#include <iostream>
#include <conio.h>

using namespace std;

const char BLACK = 219;
const char WHITE = 32;

int main() {
	int i, j, k = 0;
	for (i = 1; i <= 8; i++)
	{
		for (j = 1; j <= 8; j++)
		{
			if (i == 2 && j == 2) {
				cout << "";
			}
			if ((i + j) % 2 == 0)
				cout << BLACK << BLACK << BLACK;
			else {
				if (k % 2 == 0) {
					cout << WHITE << WHITE << WHITE;
				}
				else {
					cout << WHITE << "R" << WHITE;
				}
				k++;
			}
		}
		printf("\n");
	}
	_getch();
	return 0;
}