#ifndef MatrixStack_hpp
#define MatrixStack_hpp

#include <iostream>
#include <vector>

#include "Matrix.hpp"

using namespace std;

class MatrixStack{
    private:
        vector<Matrix> stack;
    public:
        MatrixStack();
        ~MatrixStack();
        void PushMatrix();
        void PopMatrix();
        void multiply(Matrix matrix);
        Matrix top();
        void Scale(float sx, float sy);
        void Translate(float dx, float dy);
        void Rotate(float theta);

        //ostream stuff
        friend ostream& operator<<(ostream& os, const MatrixStack & matrixstack)
        {
            int i = 0;
            for(auto m = matrixstack.stack.begin(); m != matrixstack.stack.end(); m++, i++)
            {
                os << "Matrix " << i << ":\n" << *m << "\n";
            }
            return os;
        }
};

#endif

