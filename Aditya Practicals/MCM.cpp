#include<iostream>
using namespace std;

int matrix_chain_order(int p[], int n) {
    int m[n][n], s[n][n];
    for(int i=1; i<n; i++) m[i][i] = 0;
    for(int L=2; L<n; L++) {
        for(int i=1; i<n-L+1; i++) {
            int j = i+L-1;
            m[i][j] = INT_MAX;
            for(int k=i; k<=j-1; k++) {
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j]) {

                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    return m[1][n-1];
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;
    int p[n+1];
    cout << "Enter the dimensions of the matrices:\n";
    for(int i=0; i<=n; i++) {
        cin >> p[i];
    }
    cout << "Minimum cost for matrix multiplication: " << matrix_chain_order(p, n+1) << endl;
    return 0;
}