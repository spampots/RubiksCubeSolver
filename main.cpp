#include "Models/RubiksCube3dArray.cpp"
//#include "Models/RubiksCube1dArray.cpp"
//#include "Models/RubiksCubeBitboard.cpp"

#include "Solvers/dfsSolver.h"
#include "Solvers/bfsSolver.h"
#include "Solvers/iddfsSolver.h"
#include "Solvers/IDAstarSolver.h"

#include <iostream>

int main() {
    RubiksCube3dArray cube;
    std::vector<RubiksCube::Move> scramble = cube.randomShuffleCube(7); // Scramble with 10 random moves

    std::cout << "Scramble Moves: ";
    for(auto move : scramble){
        std::cout << RubiksCube::getMove(move) << " ";
    }
    cout << std::endl;

    IDDFSSolver<RubiksCube3dArray, Hash3D> solver(cube);

    auto solution = solver.solve();

    std::cout << "Solution moves: ";
    for (auto move : solution)
        std::cout << RubiksCube::getMove(move) << " ";
    std::cout << std::endl;

    // Verify
    RubiksCube3dArray testCube = cube;
    for (auto move : solution)
        testCube.move(move);

    if (testCube.isSolved())
        std::cout << "Cube solved successfully!" << std::endl;
    else
        std::cout << "Solution incorrect." << std::endl;

    return 0;
}