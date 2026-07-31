#include <iostream>
using namespace std;
#include "Model/RubiksCube3dArray.cpp"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.
    RubiksCube3dArray object3DArray;
    object3DArray.print();
  //  if (object3DArray.isSolved()) cout<<"solved"<<endl;
  //  else cout<<"not solved"<<endl;
  //  vector<RubiksCube::MOVE> movesToShuffle=object3DArray.randomShuffleCube(3);
   // for(auto move: movesToShuffle) cout<<object3DArray.getMove(move)<<" ";
   // cout<<"\n";

    object3DArray.l();
    object3DArray.print();
    if (object3DArray.isSolved()) cout<<"solved"<<endl;
    else cout<<"not solved"<<endl;

    object3DArray.lPrime();
    object3DArray.print();
    if (object3DArray.isSolved()) cout<<"solved"<<endl;
    else cout<<"not solved"<<endl;

}