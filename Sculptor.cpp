#include "Sculptor.h"
#include <fstream>
using namespace std;


void Sculptor::write(const char *Arq)
{
  ofstream fout(Arq);

  draw();

  fout << "OFF" << endl;
  fout << getNVertices() << " " << getNEdges() << " " << 0 << endl;

  // Desenha dodos os vértices no arquivo
  for (int i = minXYZ.x; i < int(minXYZ.x + dimX); ++i) {
    for (int j = minXYZ.y; j < int(minXYZ.y + dimY); ++j) {
      for (int k = minXYZ.z; k < int(minXYZ.z + dimZ); ++k) {
        POS_3D <int> pos = getNormalPos (i, j, k);

        // Vértices da face X da esquerda
        POS_3D <float> P0 = POS_3D <float> (-0.5, -0.5, -0.5) + pos;
        POS_3D <float> P1 = POS_3D <float> ( 0.5, -0.5, -0.5) + pos;
        POS_3D <float> P2 = POS_3D <float> ( 0.5, -0.5,  0.5) + pos;
        POS_3D <float> P3 = POS_3D <float> (-0.5, -0.5,  0.5) + pos;

        // Vértices da face Y de dentro
        POS_3D <float> P4 = POS_3D <float> (-0.5,  0.5,  0.5) + pos;
        POS_3D <float> P5 = POS_3D <float> (-0.5,  0.5, -0.5) + pos;

        // Vétices da K de baixo
        POS_3D <float> P6 = POS_3D <float> ( 0.5,  0.5, -0.5) + pos;

        // Vétices da face X da direita
        POS_3D <float> P7 = POS_3D <float> ( 0.5,  0.5,  0.5) + pos;

        /*
        ORDEM DE DESENHO: 0 (P0), 1 (P1), 2 (P2), 3 (P3), 4 (P4), 5 (P5), 6 (P6), 7 (P7)

                       3 . . . . . . . 4
                    .  .    .       .  .
                 2 . . . . . . . 7     .
                 .     .      .  .     .
                 .  .  .    .    .  .  .
                 .     . .       .     .
                 .     0 . . . . . . . 5
                 .  .       .    .  .
                 1 . . . . . . . 6
        */


        if ( pos == POS_3D <int> (0, 0, 0) ) fout << P0 << endl;

        if ( pos.y == 0 ) {
          if (pos.z == 0) fout << P1 << endl;
          fout << P2 << endl;
          if (pos.x == 0) fout << P3 << endl;
        }

        if (pos.x == 0) {
          fout << P4 << endl;
          if (pos.z == 0) fout << P5 << endl;
        }

        if (pos.z == 0) fout << P6 << endl;

        fout << P7 << endl;

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

POS_3D <int> Sculptor::getMinXYZ() {
  POS_3D <int> minXYZ;

  for (pSolidIterator i = l.begin(); i != l.end(); ++i){
    // Instancia o mínimo corrente
    POS_3D <int> current( (*i)->getMinX(), (*i)->getMinY(), (*i)->getMinZ() );

    // Verifica se é o primeiro ou se o corrente é menor que o mínimo atual
    if (i == l.begin()) minXYZ = current;
    else if (minXYZ.x > current.x ) minXYZ.x = current.x;
    else if (minXYZ.y > current.y ) minXYZ.y = current.y;
    else if (minXYZ.z > current.z ) minXYZ.z = current.z;
  }

  return minXYZ;
}

POS_3D <int> Sculptor::getMaxXYZ() {
  POS_3D <int> maxXYZ;

  for (pSolidIterator i = l.begin(); i != l.end(); ++i){
    // Instancia o mínimo corrente
    POS_3D <int> current( (*i)->getMaxX(), (*i)->getMaxY(), (*i)->getMaxZ() );

    // Verifica se é o primeiro ou se o corrente é menor que o mínimo atual
    if (i == l.begin()) maxXYZ = current;
    else if (maxXYZ.x < maxXYZ.x ) maxXYZ.x = current.x;
    else if (maxXYZ.y < maxXYZ.y ) maxXYZ.y = current.y;
    else if (maxXYZ.z < maxXYZ.z ) maxXYZ.z = current.z;
  }

  return maxXYZ;
}

void Sculptor::draw() {
  POS_3D <int> max = getMaxXYZ(), min = getMinXYZ();
  POS_3D <int> size = max - min;

  initialize(size.x, size.y, size.z, min.x, min.y, min.z);

  cout << ( POS_3D <int> (dimX, dimY, dimZ)) << endl;

  for (pSolidIterator i = l.begin(); i != l.end(); ++i){
    (*i)->sculpt(*this);
  }
}
