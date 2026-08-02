#include <iostream>
#include "Model/RubiksCube3dArray.cpp"
#include "Solver/DFSSolver.h"
using namespace std;

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.
  //  if (object3DArray.isSolved()) cout<<"solved"<<endl;
  //  else cout<<"not solved"<<endl;
  //  vector<RubiksCube::MOVE> movesToShuffle=object3DArray.randomShuffleCube(3);
   // for(auto move: movesToShuffle) cout<<object3DArray.getMove(move)<<" ";
   // cout<<"\n";

   // object3DArray.l();
   // object3DArray.print();
   // if (object3DArray.isSolved()) cout<<"solved"<<endl;
   // else cout<<"not solved"<<endl;

    //object3DArray.lPrime();
  //  object3DArray.print();
  //  if (object3DArray.isSolved()) cout<<"solved"<<endl;
  //  else cout<<"not solved"<<endl;


//    RubiksCube3dArray cube1;
//    RubiksCube3dArray cube2;
//    if (cube1==cube2) cout<<"cubes are equal"<<endl;
//    else cout<<"cubes are not equal"<<endl;
//    cube2.l();
//    if (cube1==cube2) cout<<"cubes are equal"<<endl;
//    else cout<<"cubes are not equal"<<endl;
//    cube2.lPrime();
//    if (cube1==cube2) cout<<"cubes are equal"<<endl;
//    else cout<<"cubes are not equal"<<endl;

    RubiksCube3dArray object3DArray;
    object3DArray.print();

    vector<RubiksCube::MOVE> movesToShuffle=object3DArray.randomShuffleCube(4);
    object3DArray.print();
    for (auto move : movesToShuffle) cout << object3DArray.getMove(move) << endl;
    cout << endl;

    DFSSolver<RubiksCube3dArray,Hash3d> dfsSolver(object3DArray,6);

    vector<RubiksCube::MOVE> movesToSolve=dfsSolver.solve();
    dfsSolver.rubiksCube.print();
    for (auto move:movesToSolve) cout << object3DArray.getMove(move) << endl;
    cout << endl;


}