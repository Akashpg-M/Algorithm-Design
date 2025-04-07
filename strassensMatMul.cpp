#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> add(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n=A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            C[i][j]=A[i][j]+B[i][j];
    return C;
}

vector<vector<int>> subtract(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n=A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            C[i][j]=A[i][j] - B[i][j];
    return C;
}

vector<vector<int>> strassen(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n=A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));

    if (n == 1) {
        C[0][0]=A[0][0] * B[0][0];
        return C;
    }

    int mid=n / 2;
    vector<vector<int>> A11(mid, vector<int>(mid)), A12(mid, vector<int>(mid));
    vector<vector<int>> A21(mid, vector<int>(mid)), A22(mid, vector<int>(mid));
    vector<vector<int>> B11(mid, vector<int>(mid)), B12(mid, vector<int>(mid));
    vector<vector<int>> B21(mid, vector<int>(mid)), B22(mid, vector<int>(mid));

    for (int i=0; i<mid; i++) {
        for (int j=0; j<mid; j++) {
            A11[i][j]=A[i][j];
            A12[i][j]=A[i][j+mid];
            A21[i][j]=A[i+mid][j];
            A22[i][j]=A[i+mid][j+mid];

            B11[i][j]=B[i][j];
            B12[i][j]=B[i][j+mid];
            B21[i][j]=B[i+mid][j];
            B22[i][j]=B[i+mid][j+mid];
        }
    }

    vector<vector<int>> M1=strassen(add(A11, A22), add(B11, B22));
    vector<vector<int>> M2=strassen(add(A21, A22), B11);
    vector<vector<int>> M3=strassen(A11, subtract(B12, B22));
    vector<vector<int>> M4=strassen(A22, subtract(B21, B11));
    vector<vector<int>> M5=strassen(add(A11, A12), B22);
    vector<vector<int>> M6=strassen(subtract(A21, A11), add(B11, B12));
    vector<vector<int>> M7=strassen(subtract(A12, A22), add(B21, B22));

    vector<vector<int>> C11=add(subtract(add(M1, M4), M5), M7);
    vector<vector<int>> C12=add(M3, M5);
    vector<vector<int>> C21=add(M2, M4);
    vector<vector<int>> C22=add(subtract(add(M1, M3), M2), M6);

    // Combine result into a single vector<vector<int>>
    for (int i=0; i<mid; i++) {
        for (int j=0; j<mid; j++) {
            C[i][j]=C11[i][j];
            C[i][j+mid]=C12[i][j];
            C[i+mid][j]=C21[i][j];
            C[i+mid][j+mid]=C22[i][j];
        }
    }

    return C;
}

void printMatrix(const vector<vector<int>>& mat) {
    for (const auto& row : mat) {
        for (int val : row)
            cout<<val<<" ";
        cout<<endl;
    }
}

vector<vector<int>> padToPowerOfTwo(const vector<vector<int>>& mat, int newSize) {
    vector<vector<int>> padded(newSize, vector<int>(newSize, 0));
    int oldSize=mat.size();
    for (int i=0; i<oldSize; i++)
        for (int j=0; j<oldSize; j++)
            padded[i][j]=mat[i][j];
    return padded;
}

int main() {
    vector<vector<int>> A={{1, 2}, {3, 4}};
    vector<vector<int>> B={{5, 6}, {7, 8}};

    int n=A.size();
    int m=1;

    while (m<n) m *= 2;

    vector<vector<int>> ANew=padToPowerOfTwo(A, m);
    vector<vector<int>> BNew=padToPowerOfTwo(B, m);

    vector<vector<int>> result=strassen(ANew, BNew);

    cout<<"Strassen Multiplication Result:\n";
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
