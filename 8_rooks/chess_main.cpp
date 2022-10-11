#include <iostream>
#include <conio.h>

using namespace std;

const char BLACK = 219;
const char WHITE = 32;

void printBoard() {
	int i, j, temp = 9;
	char ch = 97;
	for (i = 1; i <= 8; i++)
	{
		for (int m = 1; m <= 3; m++) {
			for (j = 1; j <= 8; j++) {
				if ((i + j) % 2 == 0)
					cout << BLACK << BLACK << BLACK << BLACK << BLACK;
				else {
					cout << WHITE << WHITE << WHITE << WHITE << WHITE;
				}
			}
			if (m == 2)
				cout << "  " << --temp;
			cout << endl;
		}
	}
	for (i = 0; i < 8; i++)
		cout << "  " << ch++ << "  ";
	cout << "\n\n";
}

int main() {
	printBoard();
	_getch();
	return 0;
}