#include <iostream>
#include <cstring>
using namespace std;

void printTable(int dp[][100], int m, int n) {
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

void printDirectionTable(char dir[][100], int m, int n) {
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dir[i][j] << " ";
        }
        cout << endl;
    }
}

int lcs(string s1, string s2, int m, int n)
{
    int dp[100][100];
    char dir[100][100];

    for(int i=0;i<=m;i++) {
        for(int j=0;j<=n;j++) {
            if(i==0 || j==0) {
                dp[i][j] = 0;
                dir[i][j] = ' ';
            }
            else if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                dir[i][j] = '\\';
            }
            else {
                if(dp[i-1][j] >= dp[i][j-1]) {
                    dp[i][j] = dp[i-1][j];
                    dir[i][j] = '|';
                }
                else {
                    dp[i][j] = dp[i][j-1];
                    dir[i][j] = '-';
                }
            }
        }
    }

    cout << "DP Table:" << endl;
    printTable(dp, m, n);
    cout << endl;

    cout << "Direction Table:" << endl;
    printDirectionTable(dir, m, n);
    cout << endl;

    // finding the longest common subsequence
    int index = dp[m][n];
    char lcs[index+1];
    lcs[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i-1] == s2[j-1]) {
            lcs[index-1] = s1[i-1];
            i--;
            j--;
            index--;
        }
        else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        }
        else {
            j--;
        }
    }

    cout << "Longest Common Subsequence: " << lcs << endl;
    return dp[m][n];
}

int main()
{
    string s1, s2;
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;

    int m = s1.length();
    int n = s2.length();

    cout << "Length of Longest Common Subsequence: " << lcs(s1, s2, m, n) << endl;
    return 0;
}
