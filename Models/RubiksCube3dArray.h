#ifndef RUBIKSCUBE3DARRAY_H
#define RUBIKSCUBE3DARRAY_H

#include "Rubiks.h"

class RubiksCube3dArray : public RubiksCube
{
private:
    void rotateFace(int f);

public:
    char cube[6][3][3]{};
    RubiksCube3dArray();
    Color getColor(Face face, unsigned row, unsigned col) const override;
    bool isSolved() const override;
    RubiksCube &u() override;
    RubiksCube &u2() override;
    RubiksCube &uP() override;
    RubiksCube &d() override;
    RubiksCube &d2() override;
    RubiksCube &dP() override;
    RubiksCube &l() override;
    RubiksCube &l2() override;
    RubiksCube &lP() override;
    RubiksCube &r() override;
    RubiksCube &r2() override;
    RubiksCube &rP() override;
    RubiksCube &f() override;
    RubiksCube &f2() override;
    RubiksCube &fP() override;
    RubiksCube &b() override;
    RubiksCube &b2() override;
    RubiksCube &bP() override;
    bool operator==(const RubiksCube3dArray &other) const;
    RubiksCube3dArray &operator=(const RubiksCube3dArray &other);
};

struct Hash3D
{
    size_t operator()(const RubiksCube3dArray &r1) const
    {
        string str = "";
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    str += r1.cube[i][j][k];
                }
            }
        }
        return hash<string>()(str);
    }
};

#endif