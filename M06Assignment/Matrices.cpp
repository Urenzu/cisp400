#include "Matrices.h"

namespace Matrices
{
    Matrix::Matrix(int _rows, int _cols)
    {
        rows = _rows;
        cols = _cols;
        a.resize(_rows, vector<double>(_cols, 0));
        /*for(size_t i = 0; i < _rows; i++)
        {
            a.at(i).resize(_cols, 0);
        }*/
    }
    ///Add each corresponding element.
    ///usage:  c = a + b;
    Matrix operator+(const Matrix& a, const Matrix& b)
    {
        if(a.getRows() != b.getRows() || a.getCols() != b.getCols()) error("a and b mismatching dimensions");
        int rows = a.getRows();
        int cols = b.getCols();
        Matrix c(rows, cols);
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                c(i,j) = a(i,j) + b(i,j);
            }
        }
        return c;
    }

    ///Matrix multiply.  See description.
    ///usage:  c = a * b;
    Matrix operator*(const Matrix& a, const Matrix& b)
    {
        if(a.getCols() != b.getRows()) error("a and b mismatching dimensions");
        Matrix c(a.getRows(), b.getCols());
        for(int k = 0; k < b.getCols(); k++)
        {
            for(int i = 0; i < a.getRows(); i++)
            {
                for(int j = 0; j < a.getCols(); j++ )
                {
                    c(i,k) += a(i,j) * b(j,k); 
                }
            }
        }
        return c;
    }

    ///Matrix comparison.  See description.
    ///usage:  a == b
    bool operator==(const Matrix& a, const Matrix& b)
    {
        if(a.getRows() != b.getRows() || a.getCols() != b.getCols()) return false;
        int rows = a.getRows();
        int cols = b.getCols();

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++ )
            {
                    ///if(a(i,j) != b(i,j)) return false;
                    if(fabs(a(i,j) - b(i,j) > 0.001)) return false;
            }
        }
        return true;
    }

    ///Matrix comparison.  See description.
    ///usage:  a != b
    bool operator!=(const Matrix& a, const Matrix& b)
    {
        return !(a == b);
    }

    ///Output matrix.
    ///Separate columns by ' ' and rows by '\n'
    ostream& operator<<(ostream& os, const Matrix& a)
    {
        ///cout << a(0,0) << " " << c(0,1) << endl;
        ///cout << c(1,0) << " " << c(1,1) << endl;
        for(int i = 0; i < a.getRows(); i++)
        {
            for(int j = 0; j < a.getCols(); j++ )
            {
                os << setw(10) <<  a(i,j) << ' ';
            }
            os << endl;
        }
        return os;
    }

    ///push back x into the first row and y into the second row
    ///add one to cols member variable to keep track
    void Matrix::addCoordinate(double x, double y)
    {
        a.at(0).push_back(x);
        a.at(1).push_back(y);
        cols++;
    }

    RotationMatrix::RotationMatrix(double theta):Matrix(2,2)
    {
        a.at(0).at(0) = cos(theta);
        a.at(0).at(1) = -sin(theta);
        a.at(1).at(0) = sin(theta);
        a.at(1).at(1) = cos(theta);
    }

    ScalingMatrix::ScalingMatrix(double scale):Matrix(2,2)
    {
        a.at(0).at(0) = scale;
        a.at(0).at(1) = 0;
        a.at(1).at(0) = 0;
        a.at(1).at(1) = scale;
    }

    TranslationMatrix::TranslationMatrix(double xShift, double yShift, int nCols):Matrix(2,nCols)
    {
        for(int i = 0; i < nCols; i++)
        {
            a.at(0).at(i) = xShift;
            a.at(1).at(i) = yShift;
        }
    }

}