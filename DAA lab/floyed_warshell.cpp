#include <bits/stdc++.h>
using namespace std;
	void sol(vector<vector<int>>&matrix) {
		int n = matrix.size();
		
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					matrix[i][j] = min(matrix[i][j],
					                   matrix[i][k] + matrix[k][j]);
				}
			}
		}
	}



int main() {

	int V,e ;
	cout<<"give size of matrix and edges"<<endl;
	cin>>V>>e;
	vector<vector<int>> matrix(V, vector<int>(V, 1e9));
	
	for (int i = 0; i < e; i++)
    {
        vector<int> edgewt(3);
        for (int j = 0; j < 3; j++)
            cin >> edgewt[j];
        matrix[edgewt[0]][edgewt[1]] = edgewt[2];
    }

	sol(matrix);

	for (auto row : matrix) {
		for (auto cell : row) {
			cout << cell << " ";
		}
		cout << endl;
	}

	return 0;
}