/*
 * matrix.h
 */

#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>

class Matrix {
    public:
        Matrix(int, int);
        Matrix(double**, int, int);
        Matrix();
        ~Matrix();
        Matrix(const Matrix&);
        Matrix& operator=(const Matrix&);

        inline double& operator()(int x, int y) { return p[x][y]; }

        Matrix& operator+=(const Matrix&);
        Matrix& operator-=(const Matrix&);
        Matrix& operator*=(const Matrix&);
        Matrix& operator*=(double);
        Matrix& operator/=(double);
        Matrix  operator^(int);
        
        friend std::ostream& operator<<(std::ostream&, const Matrix&);
        friend std::istream& operator>>(std::istream&, Matrix&);

        void swapRows(int, int);
        int rows() { return this->rows_; }
        int cols() { return this->cols_; }
        Matrix transpose();

        static Matrix createIdentity(int);
        static Matrix solve(Matrix, Matrix);
        static Matrix bandSolve(Matrix, Matrix, int);

        // functions on vectors
        static double dotProduct(Matrix, Matrix);

        // functions on augmented matrices
        static Matrix augment(Matrix, Matrix);
        Matrix gaussianEliminate();
        Matrix rowReduceFromGaussian();
        void readSolutionsFromRREF(std::ostream& os);
        Matrix inverse();

    protected:
        int rows_, cols_;
        double **p;

        void allocSpace();
        Matrix expHelper(const Matrix&, int);
};

class VectorRow : public Matrix {
public:
    VectorRow(double** d, int c) { m = Matrix(d, 1, c); }
    VectorRow() {}

    VectorRow& operator+=(const VectorRow&);
    VectorRow& operator*=(double);

    int rows() { return this->m.rows(); }
    int cols() { return this->m.cols(); }

    inline double& operator()(int x, int y) { return m(x, y); }

    friend std::ostream& operator<<(std::ostream&, const VectorRow&);
    friend std::istream& operator>>(std::istream&, VectorRow&);

private:
    Matrix m;
};

Matrix operator+(const Matrix&, const Matrix&);
Matrix operator+(Matrix, VectorRow);
VectorRow operator+(VectorRow, VectorRow);
Matrix operator-(const Matrix&, const Matrix&);
Matrix operator*(const Matrix&, const Matrix&);
Matrix operator*(const Matrix&, double);
Matrix operator*(double, const Matrix&);
Matrix operator/(const Matrix&, double);

#endif
