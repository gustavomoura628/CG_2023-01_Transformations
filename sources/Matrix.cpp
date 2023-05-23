#include "../headers/Matrix.hpp"
#include "../headers/Vertex.hpp"

Matrix::Matrix()
{
}

Matrix::~Matrix()
{
}

Matrix::Matrix( float v00, float v01, float v02,
                float v10, float v11, float v12,
                float v20, float v21, float v22)
{
    v[0][0] = v00;
    v[0][1] = v01;
    v[0][2] = v02;
    v[1][0] = v10;
    v[1][1] = v11;
    v[1][2] = v12;
    v[2][0] = v20;
    v[2][1] = v21;
    v[2][2] = v22;
}

Vertex Matrix::multiply(Vertex vertex) const
{
    return Vertex(  v[0][0]*vertex.x + v[0][1]*vertex.y + v[0][2]*vertex.z,
                    v[1][0]*vertex.x + v[1][1]*vertex.y + v[1][2]*vertex.z,
                    v[2][0]*vertex.x + v[2][1]*vertex.y + v[2][2]*vertex.z);
}

Matrix Matrix::multiply(Matrix matrix) const
{
    Matrix result;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            result.v[i][j] = 0;
            for(int k=0; k<3; k++)
            {
                result.v[i][j] += v[i][k] * matrix.v[k][j];
            }
        }
    }
    return result;
}

Vertex Matrix::operator*(const Vertex& vertex) const
{
    return multiply(vertex);
}

Matrix Matrix::operator*(const Matrix& matrix) const
{
    return multiply(matrix);
}

