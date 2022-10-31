#include <iostream>
using namespace std;

const string BLACK = u8"█";
const string WHITE  = " ";
const string ROOK = "R";
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
	if (x == -1 || y == -1)
		return;
	//adds rooks(= 1) and squares under attack(= 2)
		board[x][y] = 1;
		for (int i = 0; i < 8; i++)
			if (!board[i][y])
				board[i][y] = 2;
		for (int j = 0; j < 8; j++)
			if (!board[x][j])
				board[x][j] = 2;
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
						cout << BLACK << BLACK << ROOK << BLACK << BLACK;
					else {
						cout << WHITE << WHITE << ROOK << WHITE << WHITE;
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

void placeRooks(){
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (board[i][j] == 0)
				initBoard(i, j);
}

int main() {
	int x, y, opt;
	while (1) {
		printBoard();
		cout << "1. Add a new rook\n2. Automatic rook placement\n3. Restart board\n0. Exit program\nOption: ";
		cin >> opt;
		char position[5];
		int ok = 0;
		switch (opt) {
		case 1:
			while (!ok) {
				cout << "Choose a square using standard chess notation (ex: a4, f7 etc.): ";
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
			break;
		case 2:
			placeRooks();
			printBoard();
			break;
		case 3:
			init = 0;
			initBoard(-1, -1);
			break;
		case 0:
			exit(0);
			break;
		default:
			cout << "Invalid choice! Try again!\n";
			break;
		}
	}
	return 0;
}