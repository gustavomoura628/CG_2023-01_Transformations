#include "headers/Vertex.hpp"
#include "headers/Matrix.hpp"
#include "headers/MatrixStack.hpp"

using namespace std;

int main()
{
    Vertex vertex(1,2);
    cout << vertex << "\n\n";

    Polygon polygon;
    polygon.addVertex(Vertex(0,1));
    polygon.addVertex(Vertex(3,4));
    polygon.addVertex(Vertex(5,6));

    cout << polygon;

    Matrix matrix(  1,2,3,
                    4,5,6,
                    7,8,9);

    Matrix matrix2( 1,1,3,
                    2,1,3,
                    1,3,3);

    cout << matrix;
    cout << matrix2;

    cout << matrix*matrix2 << "\n";

    cout << "Stack Stuff\n";

    MatrixStack MS;
    //MS.PushMatrix();
    //MS.multiply(matrix);
    //MS.PushMatrix();
    //MS.multiply(matrix2);
    MS.PushMatrix();
    MS.Translate(5,7);
    MS.Rotate(-3.141592653589793/2);
    MS.Scale(2,3);

    cout << MS;

    cout << "before: \n" << polygon << "after:\n" << polygon.apply(MS);
    MS.PopMatrix();
    cout << "after pop:\n" << polygon.apply(MS);

}
