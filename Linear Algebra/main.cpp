// Mr. Arkiletian ICTP 12
// Simultaneous linear equation assignment
// Solved using the STL generic vector container class

// 6 1 6 6 -2 5 2 -1 -7 -2 7 7 8 -9 2 -2 2 -7 -1 -2 -1 3 0 8 -8 -3 -7 0 -9 1 6 -6 -7 3 9 0 -1\n 60 90 -44 -3 -12 19\n

#include <cmath> // for pow function
#include <iostream>
#include <vector>

using namespace std;

typedef vector<double> Dvector;
typedef vector<Dvector> Dmatrix;

// Prototypes (variable names included, but not needed)
// DO NOT change any prototypes!! NO other functions allowed.

Dmatrix GetA();
// gets the matrix A from the user and returns it

Dvector Getb(const int& siz);
// gets the vector b from the user and returns it

void Display(const Dvector& xvect);
// displays the contents of vector xvect

void Display(const Dmatrix& Amat);
// displays the contents of matrix Amat (Note: Display function is overloaded)

Dvector Solvex(const Dmatrix& Amat, const Dvector& bvect);
// Solves for systems of linear equations in the form Ax=b using cramer's rule

double Det(const Dmatrix& Amat);
// returns the Determinant of matrix Amat using a recursive algorithm
// base case is 2x2 matrix

Dmatrix Replace(Dmatrix Rmat, const int col, const Dvector& bvect);
// Replaces the column 'col' in Rmat with bvect and returns Rmat

Dmatrix Minor(const Dmatrix& Amat, const int col);
// Gets the Minor matrix of Amat by crossing out the first row and
// column 'col' then returns that smaller matrix

//-------------------------------------------
int main()
{

    Dmatrix A;
    Dvector b, x;

    A = GetA();

    Display(A);
    b = Getb(A.size());
    x = Solvex(A, b);
    Display(x);

    return (0);
}
//-------------------------------------------

Dmatrix GetA()
{
    int siz;
    cin >> siz;

    Dmatrix a;
    for (int i = 0; i < siz; i++) {
        Dvector c;
        for (int j = 0; j < siz; j++) {
            double num;
            cin >> num;
            c.push_back(num);
        }
        a.push_back(c);
    }
    return a;
}

Dvector Getb(const int& siz)
{
    Dvector v(siz);
    for (int i = 0; i < siz; i++) {
        cin >> v[i];
    }
    return v;
}

void Display(const Dvector& xvect)
{
    for (unsigned int i = 0; i < xvect.size(); i++) {
        cout << xvect[i] << " ";
    }
    cout << endl;
}

void Display(const Dmatrix& Amat)
{
    for (unsigned int i = 0; i < Amat.size(); i++) {
        for (unsigned int j = 0; j < Amat[i].size(); j++) {
            cout << Amat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

Dvector Solvex(const Dmatrix& Amat, const Dvector& bvect)
{
    double Deta;
    Deta = Det(Amat);
    Dvector results;
    for (unsigned int i = 0; i < Amat.size(); i++) {
        double dt = Det(Replace(Amat, i, bvect));
        results.push_back(dt / Deta);
    }
    return results;
}

double Det(const Dmatrix& Amat)
{
    double sum;
    if (Amat.size() > 2) {
        for (unsigned int i = 0; i < Amat.size(); i++) {
            sum = sum + pow(-1, (2 + i)) * (Amat[0][i]) * Det(Minor(Amat, i));
        }
        return sum;
    } else {
        sum = (Amat[0][0] * Amat[1][1]) - (Amat[0][1] * Amat[1][0]);
        return sum;
    }
}

Dmatrix Replace(Dmatrix Rmat, const int col, const Dvector& bvect)
{
    for (unsigned int i = 0; i < bvect.size(); i++) {
        Rmat[i][col] = bvect[i];
    }
    return Rmat;
}

Dmatrix Minor(const Dmatrix& Amat, const int col)
{
    Dmatrix small;
    int siz = Amat.size();
    for (int i = 1; i < siz; i++) {
        Dvector c;
        for (int j = 0; j < siz; j++) {
            if (j != col) {
                c.push_back(Amat[i][j]);
            }
        }
        small.push_back(c);
    }
    return small;
}
