#ifndef Matrix_hpp
#define Matrix_hpp

#include <iostream>
//#include "Vertex.hpp"
class Vertex;

using namespace std;

class Matrix{
    private:
        float v[3][3];
    public:
        Matrix();
        ~Matrix();
        Matrix( float v00, float v01, float v02,
                float v10, float v11, float v12,
                float v20, float v21, float v22);

        Vertex multiply(Vertex vertex) const;
        Matrix multiply(Matrix matrix) const;

        Vertex operator*(const Vertex& vertex) const;
        Matrix operator*(const Matrix& matrix) const;


        //ostream stuff
        friend ostream& operator<<(ostream& os, const Matrix & matrix)
        {
            for(int i = 0; i<3; i++)
            {
                for(int j = 0; j<3; j++)
                {
                    os << matrix.v[i][j] << " ";
                }
                os << "\n";
            }
            return os;
        }
};

#endif
