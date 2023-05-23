#ifndef Vertex_hpp
#define Vertex_hpp

#include <vector>
#include <iostream>

class Matrix;
class MatrixStack;

using namespace std;

class Vertex{
    public:
        float x;
        float y;
        float z;

        Vertex();
        ~Vertex();
        Vertex(float init_x, float init_y);
        Vertex(float init_x, float init_y, float init_z);
        Vertex apply(Matrix matrix);
        Vertex apply(MatrixStack matrix);

        //ostream stuff
        friend ostream& operator<<(ostream& os, const Vertex & vertex)
        {
            return os << "(" << vertex.x << "," << vertex.y << "," << vertex.z << ")";
        }

};

class Polygon{
    public:
        vector<Vertex> vertices;
        Polygon();
        ~Polygon();
        void addVertex(Vertex vertex);
        Polygon apply(Matrix matrix);
        Polygon apply(MatrixStack matrix);

        //ostream stuff
        friend ostream& operator<<(ostream& os, const Polygon & polygon)
        {
            for(auto i : polygon.vertices)
            {
                os << i << "\n";
            }
            return os;
        }
};

#endif

