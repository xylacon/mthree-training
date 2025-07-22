#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;

int validate(const string& str) {
	if (str.length() != 1 || !isdigit(str[0]))
		return -1;
	return stoi(str);
}

int menu() {
	int choice;
	string input;
	string title("TIC-TAC-TOE");
	string options(
		"1. Play game\n"
    	"2. Quit\n"
		"\n"
    	"Choose an option: "
	);
	string invalid("Invalid option.");

	// Game title
	cout << title << "\n\n";

	// Get user choice
	while (true) {
		cout << options;
		getline(cin, input);
		cout << endl;

		choice = validate(input);
		if (choice == 1 || choice == 2)
			break;
		cout << invalid << endl;
	}

	return choice;
}

int** newBoard(const int rows, const int cols) {
	int** board = new int*[rows];
	
	for (int i(0); i < rows; ++i) {
		board[i] = new int[cols];
		for (int j(0); j < cols; ++j)
			board[i][j] = 0;
	}

	return board;
}

bool updateBoard(int** board, const int rows, const int cols, const int player, const int row, const int col) {
	if (row > rows || col > cols)
		return false;
	
	if (board[row][col] != 0)
		return false;
	
	board[row][col] = player;
	return true;
}

void deleteBoard(int** board, const int rows) {
	for (int i(0); i < rows; ++i)
		delete[] board[i];
	delete[] board;
}

void printBoard(int** board, const int rows, const int cols) {
	cout << "  ";
	for (int i(1); i <= cols; ++i) {
		cout << " " << i << " ";
	}
	cout << "\n";

	for (int i(0); i < rows; ++i) {
		cout << (char)('A' + i) << " ";
		for (int j(0); j < cols; ++j) {
			switch (board[i][j]) {
				case 0:
					cout << "[ ]";
					break;
				case 1:
					cout << "[x]";
					break;
				case 2:
					cout << "[o]";
					break;
				default:
					cout << "[!]";
			}
		}
		cout << "\n\n";
	}
}

bool notMatch(const int curr, const int prev) {
	return (prev == 0 || curr != prev);
}

int checkBoard(int** board, const int rows, const int cols) {
	// Inefficient but easy to implement
	int prev;
	bool found;

	// Rows
	for (int i(0); i < rows; ++i) {
		prev = board[i][0];
		found = true;
		for (int j(1); j < cols; ++j)
			if (notMatch(board[i][j], prev))
				found = false;

		if (found)
			return prev;
	}

	// Columns
	for (int i(0); i < cols; ++i) {
		prev = board[0][i];
		found = true;
		for (int j(1); j < rows; ++j)
			if (notMatch(board[j][i], prev))
				found = false;

		if (found)
			return prev;
	}

	// Diagonals
	prev = board[0][0];
	found = true;
	for (int i(1), j(1); i < rows && j < cols; ++i, ++j) {
		if (notMatch(board[i][j], prev))
			found = false;
	}
	if (found)
		return prev;
	
	prev = board[rows-1][0];
	found = true;
	for (int i(rows-2), j(1); i >= 0 && j < cols; --i, ++j) {
		if (notMatch(board[i][j], prev))
			found = false;
	}
	if (found)
		return prev;
	
	// Check if full
	int countEmpty(0);
	for (int i(0); i < rows; ++i)
		for (int j(0); j < cols; ++j)
			if (board[i][j] == 0)
				++countEmpty;
	
	if (countEmpty == rows * cols)
		return 0;

	return -1;
}

int playGame(int** board, const int rows, const int cols) {
	int winner(-1);
	bool userTurn(false);
	string input;
	do {
		// User: 1
		// CPU: 2
		const int player( userTurn ? 1 : 2);
		int row(-1), col(-1);

		// CPU turn
		if (!userTurn) {
			srand(time(0));
			int row, col;
			do {
				row = rand() % 3;
				col = rand() % 3;
			} while (!updateBoard(board, rows, cols, player, row, col));

			userTurn = true;
			winner = checkBoard(board, rows, cols);
			continue;
		}

		// Player turn
		printBoard(board, rows, cols);
		while (true) {
			cout << "Enter your move: ";
			getline(cin, input);

			if (input.length() != 2) {
				cout << "Invalid move.\n\n";
				continue;
			}

			if (isalpha(input[0]) && isdigit(input[1])) {
				row = toupper(input[0]) - 'A';
				col = input[1] - '1';
			}
			else if (isdigit(input[0]) && isalpha(input[1])) {
				row = toupper(input[1]) - 'A';
				col = input[0] - '1';
			}
			else {
				cout << "Invalid move.\n\n";
				continue;
			}

			if (updateBoard(board, rows, cols, player, row, col))
				break;
			
			cout << "Invalid move.\n\n";
		}
		cout << endl;

		userTurn = false;
		winner = checkBoard(board, rows, cols);
	} while(winner == -1);

	return winner;
}

void run() {
	while (menu() == 1) {
		const int rows(3), cols(3);
		int** board = newBoard(rows, cols);
		const int winner( playGame(board, rows, cols) );

		switch (winner) {
			case 0:
				cout << "Tie";
				break;
			case 1:
				cout << "You win";
				break;
			case 2:
				cout << "CPU wins";
				break;
			default:
				cout << "ERROR";
		}
		cout << "\n\n";
		printBoard(board, rows, cols);
		cout << "\n\n";

		deleteBoard(board, rows);
	}
}

int main() {
	run();
	return 0;
}