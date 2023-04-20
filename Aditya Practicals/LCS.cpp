#include <iostream>
#include <cstring>
using namespace std;

string lcs(string dna1, string dna2) {
    int m = dna1.length();
    int n = dna2.length();
    // initialize the LCS matrix with zeros
    int lcs_matrix[m+1][n+1];
    memset(lcs_matrix, 0, sizeof(lcs_matrix));
    
    // fill the LCS matrix
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (dna1[i-1] == dna2[j-1]) {
                lcs_matrix[i][j] = lcs_matrix[i-1][j-1] + 1;
            } else {
                lcs_matrix[i][j] = max(lcs_matrix[i][j-1], lcs_matrix[i-1][j]);
            }
        }
    }
    
    // find the LCS string by backtracking through the matrix
    string lcs_string = "";
    int i = m;
    int j = n;
    while (i > 0 && j > 0) {
        if (dna1[i-1] == dna2[j-1]) {
            lcs_string = dna1[i-1] + lcs_string;
            i--;
            j--;
        } else if (lcs_matrix[i-1][j] > lcs_matrix[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    
    return lcs_string;
}

int main() {
    // generate two random DNA sequences of length 20
    string dna1 = "agptaggttgattcccatga";
    string dna2 = "actatgggatagggtgtaga";
    
    // call the LCS function with the random DNA sequences
    string lcs_string = lcs(dna1, dna2);
    
    // print the random DNA sequences and their longest common subsequence
    cout << "Random DNA sequence 1: " << dna1 << endl;
    cout << "Random DNA sequence 2: " << dna2 << endl;
    cout << "Longest common subsequence: " << lcs_string << endl;
    
    return 0;
}