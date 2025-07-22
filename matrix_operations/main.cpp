#include <iostream>
#include <vector>

using namespace std;

void print(int** mat, const int rows, const int cols) {
	if (rows < 1 || cols < 1) return;

	for (int i(0); i < rows; ++i) {
		for (int j(0); j < cols; ++j) {
			cout << mat[i][j] << " ";
		}
		cout << "\n";
	}
}

bool getValues(const char c, int** mat, const int rows, const int cols) {
	cout << "Enter the values for matrix " << c << " (" << rows << ", " << cols << "): \n";

	for (int i(0); i < rows; ++i) {
		for (int j(0); j < cols; ++j) {
			if (!(cin >> mat[i][j])) {
				cout << "ERROR: Invalid matrix input\n";
				return false; 
			}
		}
	}

	return true;
}

bool isValid(const int option, const int matA_rows, const int matA_cols, const int matB_rows, const int matB_cols) {
	if (matA_rows < 1 || matA_cols < 1 || matB_rows < 1 || matB_cols < 1) return false;

	switch (option) {
		case 1:
			// Addition
			if (matA_rows != matB_rows || matA_cols != matB_cols) {
				cout << "Error: Incompatible matrix sizes.\n";
				cout << "Matrix A size (m x n): " << matA_rows << " x " << matA_cols << "\n";
				cout << "Matrix B size (n x p): " << matB_rows << " x " << matB_cols << "\n";
				return false;
			}
			return true;
		case 2:
			// Multiplication
			if (matA_cols != matB_rows) {
				cout << "Error: Incompatible matrix sizes.\n";
				cout << "Matrix A size (m x n): " << matA_rows << " x " << matA_cols << "\n";
				cout << "Matrix B size (n x p): " << matB_rows << " x " << matB_cols << "\n";
				return false;
			}
			return true;
		default:
			cout << "Error: Invalid option\n";
	}

	return false;
}

int** newMatrix(const int rows, const int cols) {
	int** mat = new int*[rows];
	for (int i(0); i < rows; ++i) {
		mat[i] = new int[cols];
		for (int j(0); j < cols; ++j)
			mat[i][j] = 0;
	}

	return mat;
}

void deleteMatrix(int** mat, const int rows) {
	for (int i(0); i < rows; ++i)
		delete[] mat[i];
	delete[] mat;
}

int** add(int** matA, int** matB, const int rows, const int cols) {
	int** matC( newMatrix(rows, cols) );

	for (int i(0); i < rows; ++i)
		for (int j(0); j < cols; ++j)
			matC[i][j] += matA[i][j] + matB[i][j];

	return matC;
}

int** multiply(int** matA, const int matA_rows, const int matA_cols, int** matB, const int matB_rows, const int matB_cols) {
	int** matC( newMatrix(matA_rows, matB_cols) );

	for (int i(0); i < matA_rows; ++i) {
		for (int j(0); j < matB_cols; ++j) {
			for (int k(0); k < matA_cols; ++k) {
				matC[i][j] += matA[i][k] * matB[k][j];
			}
		}
	}

	return matC;
}

int validate(const string& str) {
	if (str.length() != 1 || !isdigit(str[0]))
		return -1;
	return stoi(str);
}

int getUserChoice() {
	int choice;
	string input;
	string options(
		"1. Add\n"
    	"2. Multiply\n"
		"\n"
    	"Choose an option: "
	);
	string invalid("Invalid option.");

	while (true) {
		cout << options;
		getline(cin, input);
		cout << endl;

		choice = validate(input);
		if (choice == 1 || choice == 2)
			return choice;

		cout << invalid << endl;
	}

	return -1;
}

int main() {
	const int choice( getUserChoice() );
	int matA_rows, matA_cols, matB_rows, matB_cols;
	while (true) {
		cout << "Enter the dimensions for matrix A (rows, cols): ";
		cin >> matA_rows >> matA_cols;
		cout << "Enter the dimensions for matrix B (rows, cols): ";
		cin >> matB_rows >> matB_cols;
		
		if (isValid(choice, matA_rows, matA_cols, matB_rows, matB_cols))
			break;
	}

	int** matA( newMatrix(matA_rows, matA_cols) );
	int** matB( newMatrix(matB_rows, matB_cols) );
	int** matC;

	while (!getValues('A', matA, matA_rows, matA_cols));
	while (!getValues('B', matB, matB_rows, matB_cols));

	cout << endl;

	switch (choice) {
		case 1:
			matC = add(matA, matB, matA_rows, matA_cols);
			cout << "Sum:\n";
			break;
		case 2:
			matC = multiply(matA, matA_rows, matA_cols, matB, matB_rows, matB_cols);
			cout << "Product:\n";
			break;
		default:
			cout << "ERROR: Invalid choice: " << choice << "\n";
			return 0;
	}

	print(matC, matA_rows, matB_cols);

	deleteMatrix(matA, matA_rows);
	deleteMatrix(matB, matB_rows);
	deleteMatrix(matC, matA_rows);

	return 0;
}