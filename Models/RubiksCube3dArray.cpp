#include "RubiksCube3dArray.h"

// Helper to rotate a face 90 degrees clockwise
void RubiksCube3dArray::rotateFace(int f)
{
    char temp[3][3]{};
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            temp[i][j] = cube[f][i][j];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cube[f][j][2 - i] = temp[i][j];
}

// Constructor: initialize cube to solved state
RubiksCube3dArray::RubiksCube3dArray()
{
    for (int i = 0; i < 6; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
                cube[i][j][k] = getColorLetter(Color(i));
}

// Return color at specified face/row/col as enum
RubiksCube::Color RubiksCube3dArray::getColor(Face face, unsigned row, unsigned col) const
{
    char color = cube[int(face)][row][col];
    switch (color)
    {
    case 'B':
        return Color::blue;
    case 'R':
        return Color::red;
    case 'G':
        return Color::green;
    case 'O':
        return Color::orange;
    case 'Y':
        return Color::yellow;
    default:
        return Color::white;
    }
}

// Check if cube is solved
bool RubiksCube3dArray::isSolved() const
{
    for (int f = 0; f < 6; f++)
        for (int r = 0; r < 3; r++)
            for (int c = 0; c < 3; c++)
                if (cube[f][r][c] != getColorLetter(Color(f)))
                    return false;
    return true;
}

// ----------------- MOVES -----------------

RubiksCube &RubiksCube3dArray::u()
{
    rotateFace(int(Face::Up));
    char temp[3];
    for (int i = 0; i < 3; ++i)
        temp[i] = cube[int(Face::Front)][0][i];
    for (int i = 0; i < 3; ++i)
        cube[int(Face::Front)][0][i] = cube[int(Face::Right)][0][i];
    for (int i = 0; i < 3; ++i)
        cube[int(Face::Right)][0][i] = cube[int(Face::Back)][0][i];
    for (int i = 0; i < 3; ++i)
        cube[int(Face::Back)][0][i] = cube[int(Face::Left)][0][i];
    for (int i = 0; i < 3; ++i)
        cube[int(Face::Left)][0][i] = temp[i];
    return *this;
}
RubiksCube &RubiksCube3dArray::u2()
{
    u();
    u();
    return *this;
}
RubiksCube &RubiksCube3dArray::uP()
{
    u();
    u();
    u();
    return *this;
}

RubiksCube &RubiksCube3dArray::d()
{
    rotateFace(int(Face::Down));
    char temp[3];
    for (int i = 0; i < 3; ++i)
        temp[i] = cube[int(Face::Front)][2][i];
    for (int i = 0; i < 3; ++i)
        cube[int(Face::Front)][2][i] = cube[int(Face::Left)][2][i];
    for (int i = 0; i < 3; ++i)
        cube[int(Face::Left)][2][i] = cube[int(Face::Back)][2][i];
    for (int i = 0; i < 3; ++i)
        cube[int(Face::Back)][2][i] = cube[int(Face::Right)][2][i];
    for (int i = 0; i < 3; ++i)
        cube[int(Face::Right)][2][i] = temp[i];
    return *this;
}
RubiksCube &RubiksCube3dArray::d2()
{
    d();
    d();
    return *this;
}
RubiksCube &RubiksCube3dArray::dP()
{
    d();
    d();
    d();
    return *this;
}

RubiksCube &RubiksCube3dArray::l()
{
    rotateFace(int(Face::Left));
    char temp[3];
    for (int i = 0; i < 3; ++i)
        temp[i] = cube[int(Face::Up)][i][0];
    for (int i = 0; i < 3; ++i)
        cube[int(Face::Up)][i][0] = cube[int(Face::Back)][2 - i][2];
    for (int i = 0; i < 3; ++i)
        cube[int(Face::Back)][2 - i][2] = cube[int(Face::Down)][i][0];
    for (int i = 0; i < 3; ++i)
        cube[int(Face::Down)][i][0] = cube[int(Face::Front)][i][0];
    for (int i = 0; i < 3; ++i)
        cube[int(Face::Front)][i][0] = temp[i];
    return *this;
}
RubiksCube &RubiksCube3dArray::l2()
{
    l();
    l();
    return *this;
}
RubiksCube &RubiksCube3dArray::lP()
{
    l();
    l();
    l();
    return *this;
}

RubiksCube &RubiksCube3dArray::r()
{
    rotateFace(int(Face::Right));
    char temp[3];
    for (int i = 0; i < 3; ++i)
        temp[i] = cube[int(Face::Up)][i][2];
    for (int i = 0; i < 3; ++i)
        cube[int(Face::Up)][i][2] = cube[int(Face::Front)][i][2];
    for (int i = 0; i < 3; ++i)
        cube[int(Face::Front)][i][2] = cube[int(Face::Down)][i][2];
    for (int i = 0; i < 3; ++i)
        cube[int(Face::Down)][i][2] = cube[int(Face::Back)][2 - i][0];
    for (int i = 0; i < 3; ++i)
        cube[int(Face::Back)][2 - i][0] = temp[i];
    return *this;
}
RubiksCube &RubiksCube3dArray::r2()
{
    r();
    r();
    return *this;
}
RubiksCube &RubiksCube3dArray::rP()
{
    r();
    r();
    r();
    return *this;
}

RubiksCube &RubiksCube3dArray::f()
{
    rotateFace(int(Face::Front));
    char temp[3];
    for (int i = 0; i < 3; ++i)
        temp[i] = cube[int(Face::Up)][2][i];
    for (int i = 0; i < 3; ++i)
        cube[int(Face::Up)][2][i] = cube[int(Face::Left)][2 - i][2];
    for (int i = 0; i < 3; ++i)
        cube[int(Face::Left)][i][2] = cube[int(Face::Down)][0][i];
    for (int i = 0; i < 3; ++i)
        cube[int(Face::Down)][0][i] = cube[int(Face::Right)][2 - i][0];
    for (int i = 0; i < 3; ++i)
        cube[int(Face::Right)][i][0] = temp[i];
    return *this;
}
RubiksCube &RubiksCube3dArray::f2()
{
    f();
    f();
    return *this;
}
RubiksCube &RubiksCube3dArray::fP()
{
    f();
    f();
    f();
    return *this;
}

RubiksCube &RubiksCube3dArray::b()
{
    rotateFace(int(Face::Back));
    char temp[3];
    for (int i = 0; i < 3; ++i)
        temp[i] = cube[int(Face::Up)][0][i];
    for (int i = 0; i < 3; ++i)
        cube[int(Face::Up)][0][i] = cube[int(Face::Right)][i][2];
    for (int i = 0; i < 3; ++i)
        cube[int(Face::Right)][i][2] = cube[int(Face::Down)][2][2 - i];
    for (int i = 0; i < 3; ++i)
        cube[int(Face::Down)][2][i] = cube[int(Face::Left)][i][0];
    for (int i = 0; i < 3; ++i)
        cube[int(Face::Left)][i][0] = temp[2 - i];
    return *this;
}
RubiksCube &RubiksCube3dArray::b2()
{
    b();
    b();
    return *this;
}
RubiksCube &RubiksCube3dArray::bP()
{
    b();
    b();
    b();
    return *this;
}

bool RubiksCube3dArray::operator==(const RubiksCube3dArray &other) const
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (other.cube[i][j][k] != cube[i][j][k])
                    return false;
            }
        }
    }
    return true;
}

RubiksCube3dArray &RubiksCube3dArray::operator=(const RubiksCube3dArray &other) {
    for(int i = 0; i < 6; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            for(int k = 0; k < 3; ++k){
                cube[i][j][k] = other.cube[i][j][k];
            }
        }
    }

    return *this;
}