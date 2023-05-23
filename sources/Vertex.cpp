#include "../headers/Vertex.hpp"
#include "../headers/Matrix.hpp"
#include "../headers/MatrixStack.hpp"

Vertex::Vertex()
{
}

Vertex::~Vertex()
{
}


Vertex::Vertex(float init_x, float init_y, float init_z)
{
    x = init_x;
    y = init_y;
    z = init_z;
}

Vertex::Vertex(float init_x, float init_y)
{
    x = init_x;
    y = init_y;
    z = 1;
}
Vertex Vertex::apply(Matrix matrix)
{
    return matrix.multiply(Vertex(x,y,z));
}
Vertex Vertex::apply(MatrixStack matrixstack)
{
    return matrixstack.top().multiply(Vertex(x,y,z));
}

Polygon::Polygon()
{
}
Polygon::~Polygon()
{
}
void Polygon::addVertex(Vertex vertex)
{
    vertices.push_back(vertex);
}
Polygon Polygon::apply(Matrix matrix)
{
    Polygon result;
    for(auto v : vertices)
    {
        result.addVertex(matrix.multiply(v));
    }
    return result;
}
Polygon Polygon::apply(MatrixStack matrixstack)
{
    Polygon result;
    for(auto v : vertices)
    {
        result.addVertex(matrixstack.top().multiply(v));
    }
    return result;
}
