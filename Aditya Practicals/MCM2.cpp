#include <bits/stdc++.h>
using namespace std;

void print_tables(int (*table)[], int n, int size) {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cout << setw(10) << table[size*(i-1)+(j-1)] << " ";
        }
        cout << endl;
    }
}

void print_optimal_parens(int (*s)[], int i, int j) {
    if(i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        print_optimal_parens(s, i, s[(i-1)*n+(j-1)]);
        print_optimal_parens(s, s[(i-1)*n+(j-1)]+1, j);
        cout << ")";
    }
}

int matrix_chain_order(int p[], int n) {
    int m[n*n], s[(n-1)*(n-1)];
    for(int i=0; i<n*n; i++) m[i] = 0;
    for(int i=0; i<(n-1)*(n-1); i++) s[i] = 0;
    for(int i=1; i<n; i++) m[(n+1)*i+i] = 0;
    for(int L=2; L<n; L++) {
        for(int i=1; i<=n-L+1; i++) {
            int j = i+L-1;
            m[(n+1)*i+j] = INT_MAX;
            for(int k=i; k<j; k++) {
                int q = m[(n+1)*i+k] + m[(n+1)*(k+1)+j] + p[i-1]*p[k]*p[j];
                if(q < m[(n+1)*i+j]) {
                    m[(n+1)*i+j] = q;
                    s[(n-1)*(i-1)+(j-2)] = k;
                }
            }
        }
    }
    cout << "m table:\n";
    print_tables(m, n, n+1);
    cout << "\ns table:\n";
    print_tables(s, n-1, n-1);
    cout << "\noptimal parenthesization: ";
    print_optimal_parens(s, 1, n-1);
    cout << endl;
    return m[n+1];
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
