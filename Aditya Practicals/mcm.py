import sys

def print_tables(table, n):
    for i in range(1, n+1):
        for j in range(1, n+1):
            print("{:10d}".format(table[i][j]), end=" ")
        print()

def print_optimal_parentheses(s, i, j):
    if i == j:
        print("A{}".format(i), end="")
    else:
        print("(", end="")
        print_optimal_parentheses(s, i, s[i][j])
        print_optimal_parentheses(s, s[i][j]+1, j)
        print(")", end="")

def matrix_chain_order(p, n):
    m = [[0 for _ in range(n)] for _ in range(n)]
    s = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(1, n):
        m[i][i] = 0
    for L in range(2, n):
        for i in range(1, n-L+1):
            j = i+L-1
            m[i][j] = sys.maxsize
            for k in range(i, j):
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]
                if q < m[i][j]:
                    m[i][j] = q
                    s[i][j] = k
    print("m table:")
    print_tables(m, n-1)
    print("\ns table:")
    print_tables(s, n-1)
    print("\nOptimal Parentheses: ", end="")
    print_optimal_parentheses(s, 1, n-1)
    print()
    return m[1][n-1]

n = int(input("Enter the number of matrices: "))
p = list(map(int, input("Enter the dimensions of the matrices:\n").split()))
print("Minimum cost for matrix multiplication:", matrix_chain_order(p, n+1))
