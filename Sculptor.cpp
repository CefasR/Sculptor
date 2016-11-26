#include "Sculptor.h"
#include <fstream>
using namespace std;


void Sculptor::write(const char *Arq)
{
  ofstream fout(Arq);

  fout << "OFF" << endl;
  fout << getNVertices() << " " << getNEdges() << " " << 0 << endl;

  // Desenha dodos os vértices no arquivo
  for (int i = minXYZ.x; i < minXYZ.x + dimX; ++i) {
    for (int j = minXYZ.y; j < minXYZ.y + dimY; ++j) {
      for (int k = minXYZ.z; k < minXYZ.z + dimZ; ++j) {
        if (i == 0){
          //fout << POS_3D <float> () << endl;
        }

      }
    }
  }
}
