#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void print(const vector<vector<int>>& mat) {
	if (mat.empty()) return;

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
	if (mat.empty()) return;

	for (vector<int>& row : mat) {
		for (int& value : row) {
			cin >> value;
		}
	}
}

vector<vector<int>> multiply(vector<vector<int>>& matA, vector<vector<int>>& matB) {
	if (matA.empty() || matB.empty()) return {{}};

	const int M(matA.size());
	const int N(matA[0].size());
	const int _N(matB.size());
	const int P(matB[0].size());

	if (N != _N) {
		cout << "Error: Incompatible matrix sizes.";
		cout << "Matrix A size (m x n): " << M << " x " << N << "\n";
		cout << "Matrix B size (n x p): " << _N << " x " << P << "\n";
		return {{}};
	}

	vector<vector<int>> matC(M, vector<int>(P, 0));

	for (size_t i(0); i < M; ++i) {
		for (size_t j(0); j < P; ++j) {
			for (size_t k(0); k < N; ++k) {
				matC[i][j] += matA[i][k] * matB[k][j];
			}
		}
	}

	return matC;
}

int main() {
	// ADD ADDITION TOOO
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