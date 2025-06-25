#include "Rubiks.h"

// Getting the color of the cube
char RubiksCube::getColorLetter(Color color)
{
    switch (color)
    {
    case Color::blue:
        return 'B';
    case Color::green:
        return 'G';
    case Color::red:
        return 'R';
    case Color::white:
        return 'W';
    case Color::orange:
        return 'O';
    case Color::yellow:
        return 'Y';
    }
    return '?';
}

// getting the move
string RubiksCube::getMove(Move ind)
{
    switch (ind)
    {
    case Move::L:
        return "L";
    case Move::Lp:
        return "L'";
    case Move::L2:
        return "L2";
    case Move::R:
        return "R";
    case Move::Rp:
        return "R'";
    case Move::R2:
        return "R2";
    case Move::U:
        return "U";
    case Move::Up:
        return "U'";
    case Move::U2:
        return "U2";
    case Move::D:
        return "D";
    case Move::Dp:
        return "D'";
    case Move::D2:
        return "D2";
    case Move::F:
        return "F";
    case Move::Fp:
        return "F'";
    case Move::F2:
        return "F2";
    case Move::B:
        return "B";
    case Move::Bp:
        return "B'";
    case Move::B2:
        return "B2";
    }
    return "?";
}

// Perform a move using move index

RubiksCube &RubiksCube::move(Move ind)
{
    switch (ind)
    {
    case Move::L:
        return this->l();
    case Move::Lp:
        return this->lP();
    case Move::L2:
        return this->l2();
    case Move::R:
        return this->r();
    case Move::Rp:
        return this->rP();
    case Move::R2:
        return this->r2();
    case Move::U:
        return this->u();
    case Move::Up:
        return this->uP();
    case Move::U2:
        return this->u2();
    case Move::D:
        return this->d();
    case Move::Dp:
        return this->dP();
    case Move::D2:
        return this->d2();
    case Move::F:
        return this->f();
    case Move::Fp:
        return this->fP();
    case Move::F2:
        return this->f2();
    case Move::B:
        return this->b();
    case Move::Bp:
        return this->bP();
    case Move::B2:
        return this->b2();
    }
    return *this;
}

RubiksCube &RubiksCube::invert(Move ind)
{
    switch (ind)
    {
    case Move::L:
        return this->lP();
    case Move::Lp:
        return this->l();
    case Move::L2:
        return this->l2();
    case Move::R:
        return this->rP();
    case Move::Rp:
        return this->r();
    case Move::R2:
        return this->r2();
    case Move::U:
        return this->uP();
    case Move::Up:
        return this->u();
    case Move::U2:
        return this->u2();
    case Move::D:
        return this->dP();
    case Move::Dp:
        return this->d();
    case Move::D2:
        return this->d2();
    case Move::F:
        return this->fP();
    case Move::Fp:
        return this->f();
    case Move::F2:
        return this->f2();
    case Move::B:
        return this->bP();
    case Move::Bp:
        return this->b();
    case Move::B2:
        return this->b2();
    }
    return *this;
}

void RubiksCube::print() const
{
    cout << "RUBVIK'S CUBE\n";

    for (int row = 0; row < 3; ++row)
    {
        for (unsigned i = 0; i < 7; ++i)
            cout << ' ';
        for (int col = 0; col < 3; ++col)
        {
            cout << getColorLetter(getColor(Face::Up, row, col)) << ' ';
        }
        cout << "\n";
    }
    cout << '\n';

    for (int row = 0; row < 3; ++row)
    {

        for (int col = 0; col < 3; ++col)
        {
            cout << getColorLetter(getColor(Face::Left, row, col)) << ' ';
        }
        cout << ' ';

        for (int col = 0; col < 3; ++col)
        {
            cout << getColorLetter(getColor(Face::Front, row, col)) << ' ';
        }
        cout << ' ';

        for (int col = 0; col < 3; ++col)
        {
            cout << getColorLetter(getColor(Face::Right, row, col)) << ' ';
        }
        cout << ' ';

        for (int col = 0; col < 3; ++col)
        {
            cout << getColorLetter(getColor(Face::Back, row, col)) << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    for (int row = 0; row < 3; ++row)
    {
        for (unsigned i = 0; i < 7; ++i)
            cout << ' ';
        for (int col = 0; col < 3; ++col)
        {
            cout << getColorLetter(getColor(Face::Down, row, col)) << ' ';
        }
        cout << "\n";
    }
    cout << '\n';
}

vector<RubiksCube::Move> RubiksCube::randomShuffleCube(unsigned times)
{
    vector<Move> moves_performed;
    srand(time(0));
    for (unsigned i = 0; i < times; i++)
    {
        unsigned int selectMove = (rand() % 18);
        moves_performed.push_back(static_cast<Move>(selectMove));
        this->move(static_cast<Move>(selectMove));
    }
    return moves_performed;
}