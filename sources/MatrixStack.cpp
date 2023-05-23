#include <cmath>
#include "../headers/MatrixStack.hpp"

MatrixStack::MatrixStack()
{
    stack.push_back(Matrix(1,0,0,0,1,0,0,0,1)); //Identity
}

MatrixStack::~MatrixStack()
{
}


void MatrixStack::PushMatrix()
{
    stack.push_back(stack.back());
}

void MatrixStack::PopMatrix()
{
    stack.pop_back();
}

void MatrixStack::multiply(Matrix matrix)
{
    stack.back() = stack.back().multiply(matrix);
}

Matrix MatrixStack::top()
{
    return stack.back();
}

void MatrixStack::Scale(float sx, float sy)
{
    multiply(Matrix( sx, 0, 0,
                      0,sy, 0,
                      0, 0, 1));
}

void MatrixStack::Translate(float dx, float dy)
{
    multiply(Matrix(  1, 0,dx,
                      0, 1,dy,
                      0, 0, 1));
}

void MatrixStack::Rotate(float theta)
{
    theta = theta * 3.141592653589793 / 180; //DEGREES TO RADIANS

    multiply(Matrix(  cos(theta), -sin(theta), 0,
                      sin(theta),  cos(theta), 0,
                               0,           0, 1));
}
