#include<bits/stdc++.h>
#include "../Models/Rubiks.h"
#include "DFSSolver.h"

#ifndef RUBIKS_CUBE_SOLVER_IDDFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_IDDFSSOLVER_H

template<typename T, typename H>
class IDDFSSolver {
private:
    int max_search_depth;
    vector<RubiksCube::Move> moves;

public:
    T rubiksCube;

    IDDFSSolver(T _rubiksCube, int _max_search_depth = 7) {
        rubiksCube = _rubiksCube;
        max_search_depth = _max_search_depth; 
    }

    vector<RubiksCube::Move> solve() {
        for(int i = 1; i <= max_search_depth; ++i){
            DFSSolver<T, H> DFSSolver(rubiksCube, i);
            moves = DFSSolver.solve();
            if(DFSSolver.rubiksCube.isSolved()) {
                rubiksCube = DFSSolver.rubiksCube;
                break;
            }
        }
        return moves;
    }
};

#endif