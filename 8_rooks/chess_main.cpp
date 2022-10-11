#include <iostream>
#include <conio.h>

using namespace std;

const char BLACK = 219;
const char WHITE = 32;
int board[8][8], init = 0;


void initBoard(int x,int y) {
	//initializes the board if !init
	if (!init)
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			board[i][j] = 0;
			init++;
		}
	//adds rooks(= 1) and squares under attack(= 2)
		board[x][y] = 1;
		for (int i = 0; i < 8; i++)
			if (!board[i][y])
				board[i][y] = 2;
		for (int j = 0; j < 8; j++)
			if (!board[x][j])
				board[x][j] = 2;
}

void printMatrix() {
	cout << "\n\n";
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
}

void printBoard() {
	int i, j, temp = 9;
	char ch = 97;
	for (i = 1; i <= 8; i++)
	{
		for (int m = 1; m <= 3; m++) {
			for (j = 1; j <= 8; j++) {
				if (m == 2 && (board[i-1][j-1]==1)) {
					if ((i + j) % 2 == 0)
						cout << BLACK << BLACK << "R" << BLACK << BLACK;
					else {
						cout << WHITE << WHITE << "R" << WHITE << WHITE;
					}
				}
				else {
					if ((i + j) % 2 == 0)
						cout << BLACK << BLACK << BLACK << BLACK << BLACK;
					else {
						cout << WHITE << WHITE << WHITE << WHITE << WHITE;
					}
				}

			}
			//prints number notation
			if (m == 2)
				cout << "  " << --temp;
			cout << endl;
		}
	}
	//prints letter notation
	for (i = 0; i < 8; i++)
		cout << "  " << ch++ << "  ";
	cout << "\n\n";
}

int isValid(int x,int y) {
	if (board[x][y] != 0)
		return 0;
	return 1;
}


void initMain() {
	int x, y, input = 1, opt;
	while (input) {
		printBoard();
		cout << "1. Add a new rook\n2. Exit input stage\nOption: ";
		cin >> opt;
		char position[5];
		int ok = 0;
		switch (opt) {
		case 1:
			while (!ok) {
				cout << "Choose a square using standard chess notation (ex: a3,c7 etc.): ";
				cin >> position;
				x = 8 - (int)(position[1] - 48);
				y = position[0] - 97;
				if (!(x >= 0 && x <= 7) || !(y >= 0 && y <= 7))
					cout << "Invalid notation! Try again.\n";
				else
				{
					if (isValid(x, y))
						ok = 1;
					else
						cout << "\nInvalid placement!! Two rooks are attacking each other!\n\n";
				}
			}
			initBoard(x, y);
			printMatrix();
			break;
		case 2:
			input = 0;
			break;
		default:
			cout << "Invalid choice! Try again!\n";
			break;
		}
	}
}

int main() {
	initMain();
	_getch();
	return 0;
}