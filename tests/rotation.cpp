#include "../Sculptor.h"
#include "../Canvas.h"
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

int main() {
  POS_3D <int> pos (10, 10, 10);
  AXIS axis = Z;

  TransformationMatrix M;

  M = TranslationMatrix(POS_3D <int> (-5, -5, -5) ) * M;
  M = RotationMatrix(M_PI / 3.0, axis) * M;
  M = TranslationMatrix(POS_3D <int> (5, 5, 5) ) * M;
  M = ScaleMatrix(3) * M;

  cout << M.transform(pos) << endl;
}
