#include "Sculptor.h"
#include <fstream>
using namespace std;


void Sculptor::write(const char *Arq)
{
  ofstream fout(Arq);


  dimX = 2;
  dimY = 2;
  dimZ = 2;

  fout << "OFF" << endl;
  fout << getNVertices() << " " << getNEdges() << " " << 0 << endl;

  // Desenha dodos os vértices no arquivo
  for (int i = minXYZ.x; i < minXYZ.x + dimX; ++i) {
    for (int j = minXYZ.y; j < minXYZ.y + dimY; ++j) {
      for (int k = minXYZ.z; k < minXYZ.z + dimZ; ++k) {
        POS_3D <int> pos = getNormalPos (i, j, k);

        cout << pos << endl;

        // Vértices da face X da esquerda

        // 1
        POS_3D <float> P0 = POS_3D <float> (-0.5, -0.5, -0.5) + pos;
        // 2
        POS_3D <float> P1 = POS_3D <float> (0.5, -0.5, -0.5) + pos;
        // 3
        POS_3D <float> P2 = POS_3D <float> (0.5, -0.5, 0.5) + pos;
        // 4
        POS_3D <float> P3 = POS_3D <float> (-0.5, -0.5, 0.5) + pos;

        fout << pos << endl;
        if (pos == POS_3D <int> (0, 0, 0) ){
          fout << "P0 " << P0 << endl;
        }

        if (pos.y == 0 && pos.z == 0) {
          fout << "P1 " << P1 << endl;
        }

        fout << "P2 " << P2 << endl;
        fout << "P3 " << P3 << endl;

        // Vértices da face Y de dentro

        // 5
        POS_3D <float> P4 = POS_3D <float> (-0.5, 0.5, 0.5) + pos;
        // 6
        POS_3D <float> P5 = POS_3D <float> (-0.5, 0.5, -0.5) + pos;

        if (pos.x == 0 && pos.z == 0) {
          fout << "P4 " << P4 << endl;
          fout << "P5 " << P5 << endl;
        }

        // Vértices da face Z de baixo

        // 7
        POS_3D <float> P6 = POS_3D <float> (0.5, 0.5, -0.5) + pos;

        if (pos.z == 0)
        fout << "P6 " << P6 << endl;

        // Vértices da face Z de cima

        // 8
        POS_3D <float> P7 = POS_3D <float> (0.5, 0.5, 0.5) + pos;

        fout << "P7 " << P7 << endl;

      }
    }
  }
}

void Sculptor::putVoxel(int X, int Y, int Z) {
  // Adiciona uma box com tamanho 1x1x1
  l.push_back(new Box(X, Y, Z, R, G, B, alpha));
}

void Sculptor::cutVoxel(int X, int Y, int Z) {
  // Retira uma box com tamanho 1x1x1
  l.push_back(new Box(X, Y, Z, 0.0, 0.0, 0.0, 0.0, false));
}

void Sculptor::putSphere(int Xc, int Yc, int Zc, int R) {
  l.push_back(new Ellipsoid(Xc, Yc, Zc, R, G, B, alpha, true, abs(R), abs(R), abs(R) ));
}

void Sculptor::cutSphere(int Xc, int Yc, int Zc, int R) {
  l.push_back(new Ellipsoid(Xc, Yc, Zc, R, G, B, alpha, false, abs(R), abs(R), abs(R) ));
}

void Sculptor::putBox(int X0, int X1, int Y0, int Y1, int Z0, int Z1) {
  // Adiciona uma box com tamanho x1x1
  l.push_back(
    new Box(
      (X1 + X0) / 2.0,
      (Y1 + Y0) / 2.0,
      (Z1 + Z0) / 2.0,
      R, G, B, alpha, true,
      abs(X1 - X0), abs(Y1 - Y0), abs(Z1 - Z0)
    )
  );
}

void Sculptor::cutBox(int X0, int X1, int Y0, int Y1, int Z0, int Z1) {
  // Retira uma box com tamanho 1x1x1
  l.push_back(
    new Box(
      (X1 + X0) / 2.0,
      (Y1 + Y0) / 2.0,
      (Z1 + Z0) / 2.0,
      R, G, B, alpha, false,
      abs(X1 - X0), abs(Y1 - Y0), abs(Z1 - Z0)
    )
  );
}
