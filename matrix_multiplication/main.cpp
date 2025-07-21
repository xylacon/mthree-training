#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void print(const vector<vector<int>>& mat) {
	if (mat.size() == 0) return;

	const int M(mat.size());
	const int N(mat[0].size());

	for (const vector<int>& row : mat) {
		for (const int& value : row) {
			cout << value << " ";
		}
		cout << "\n";
	}
}

void getValues(vector<vector<int>>& mat) {
	for (vector<int>& row : mat) {
		for (int& value : row) {
			cin >> value;
		}
	}
}

vector<vector<int>> multiply(vector<vector<int>>& matA, vector<vector<int>>& matB) {
	const int M(matA.size());
	const int N(matB.size());
	const int P(matB[0].size());

	if (M == 0 || N == 0) return {{}};

	vector<vector<int>> matC(M, vector<int>(P, 0));

	for (size_t i(0); i < M; ++i) {
		for (size_t j(0); j < P; ++j) {
			for (size_t k(0); k < N; ++k) {
				matC[i][j] = matA[i][k] * matB[k][j];
			}
		}
	}

	return matC;
}

int main() {
	int M, N, P;

	cout << "Enter the dimensions for matrix A (m x n): ";
	cin >> M >> N;

	cout << "Enter the second dimension (p) for matrix B (" << N << " x p): ";
	cin >> P;

	vector<vector<int>> matA(M, vector<int>(N, 0));
	vector<vector<int>> matB(N, vector<int>(P, 0));

	cout << "Enter the values (integer) for matrix A (" << M << " x " << N << "):\n";
	getValues(matA);

	cout << "Enter the values (integer) for matrix B (" << N << " x " << P << "):\n";
	getValues(matB);

	cout << endl;

	vector<vector<int>> matC( multiply(matA, matB) );
	cout << "Result matrix:\n";
	print(matC);
}