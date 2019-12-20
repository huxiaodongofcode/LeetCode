/*
ʱ�䣺2019��12��20�� 16:19:32
��Ŀ��Given n and m which are the dimensions of a matrix initialized by zeros 
and given an array indices where indices[i] = [ri, ci]. 
For each pair of [ri, ci] you have to increment all cells in row ri and column ci by 1
���⣺��ri�м�һ��ci�м�һ
*/

#include<vector>
#include<iostream>
using namespace std;
/*
Runtime: 4 ms, faster than 83.07% of C++ online submissions for Cells with Odd Values in a Matrix.
Memory Usage: 9.2 MB, less than 100.00% of C++ online submissions for Cells with Odd Values in a Matrix.
*/
#define MAXN 55
#define MAXM 55
int cells[MAXN][MAXM];
int oddCells_1(int n, int m, vector<vector<int>>& indices) {//ֱ�ӱ������
	int odd = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cells[i][j] = 0;
	for (size_t i = 0; i < indices.size(); i++) {
		int a = indices[i][0];
		int b = indices[i][1];
		for (int i = 0; i < m; i++)
			cells[a][i]++;
		for (int i = 0; i < n; i++)
			cells[i][b]++;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (cells[i][j] % 2 != 0)
				odd++;
	return odd;
}
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Cells with Odd Values in a Matrix.
Memory Usage: 9.3 MB, less than 100.00% of C++ online submissions for Cells with Odd Values in a Matrix.
*/
int oddCells_2(int n, int m, vector<vector<int>>& indices) {
	vector<int> oddRows;
	vector<int> oddCols;
	//��ʼ������������,0��ż��
	oddRows.assign(n, 0);
	oddCols.assign(m, 0);


	for (const auto &elem : indices) {
		oddRows[elem[0]] = 1 - oddRows[elem[0]];
		oddCols[elem[1]] = 1 - oddCols[elem[1]];
	}
	//ͳ������������
	int numOddCols = 0;
	for (const auto c : oddCols)//����д������·��ٶȿ�
		numOddCols += c;
	/*for (size_t i = 0; i < oddCols.size(); i++)
		if (oddCols[i] == 1)
			numOddCols++;*/

	int numEvenCols = m - numOddCols;

	//�����������
	int Odd = 0;
	for (auto r:oddRows)
		Odd += r ? numEvenCols : numOddCols;
	return Odd;
}

int main() {
	vector<vector<int>> indices = { {1,1},{0,0} };
	vector<vector<int>> indices2 = { { 0,1 },{ 1,1 } };
	int odd1=oddCells_1(2, 2, indices);
	int odd2= oddCells_2(2, 3, indices2);
	cout << odd2;
}

