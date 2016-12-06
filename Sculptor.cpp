#include "Sculptor.h"
#include <fstream>
using namespace std;


void Sculptor::write(const char *Arq)
{
  ofstream fout(Arq);

  draw();

  fout << "OFF" << endl;
  fout << getNVertices() << " " << getNFaces() << " " << 0 << endl;

  for (int i = 0; i < dimX + 1; i++) {
    for (int j = 0; j < dimY + 1; j++) {
      for (int k = 0; k < dimZ + 1; k++) {
        POS_3D <int> pos(i, j, k);
        POS_3D <float> current = POS_3D <float> (-0.5, -0.5, -0.5) + pos;
        fout << current << endl;
      }
    }
  }

  /*
                    EXPLICAÇÃO

                       . . . . . . . . .
                    .  .    5       .  .
                 . . . . . . . . .     .
                 .     .      1  .     .
                 .  0  .    .    .  3  .
                 .     . 4       .     .
                 .     . . . . . . . . .
                 .  .       2    .  .
                 . . . . . . . . .

            Face 0 - plano XZ da esquerda
            Face 1 - plano YZ de dentro
            Face 2 - plano XY de baixo
            Face 3 - plano XZ da direita
            Face 4 - plano YZ de fora
            Face 5 - plano XY de cima

        */

  for (int i = 0; i < dimX; ++i) {
    for (int j = 0; j < dimY; ++j) {
      for (int k = 0; k < dimZ; ++k) {

        POS_3D <int> pos(i, j, k);

             // Vértices da face X da esquerda
        unsigned P0 = getVoxelVertexIndexAt(pos.x, pos.y, pos.z),
                 P1 = getVoxelVertexIndexAt(pos.x + 1, pos.y, pos.z),
                 P2 = getVoxelVertexIndexAt(pos.x + 1, pos.y, pos.z + 1),
                 P3 = getVoxelVertexIndexAt(pos.x, pos.y, pos.z + 1),
                 // Vértices da face Y de dentro
                 P4 = getVoxelVertexIndexAt(pos.x, pos.y + 1, pos.z + 1),
                 P5 = getVoxelVertexIndexAt(pos.x, pos.y + 1, pos.z),
                 // Vétices da K de baixo
                 P6 = getVoxelVertexIndexAt(pos.x + 1, pos.y + 1, pos.z),
                 // Vétices da face X da direita
                 P7 = getVoxelVertexIndexAt(pos.x + 1, pos.y + 1, pos.z + 1);

        // Pega o voxel da posição corrente
        Voxel v = at(pos);

        if (v.is_on){
          // Face da esquerda
          if (pos.y == 0 or !at(pos.x, pos.y - 1, pos.z).is_on )
          fout << 4 << " " << P0 << " " << P1 << " " << P2 << " " << P3 << " " << v.R << " " << v.G << " " << v.B << " " << v.alpha << endl;
          // Face de dentro
          if (pos.x == 0 or !at(pos.x - 1, pos.y, pos.z).is_on )
          fout << 4 << " " << P0 << " " << P3 << " " << P4 << " " << P5 << " " << v.R << " " << v.G << " " << v.B << " " << v.alpha << endl;
          // Face de baixo
          if (pos.z == 0 or !at(pos.x, pos.y, pos.z - 1).is_on )
          fout << 4 << " " << P0 << " " << P5 << " " << P6 << " " << P1 << " " << v.R << " " << v.G << " " << v.B << " " << v.alpha << endl;

          // Face da direita
          fout << 4 << " " << P5 << " " << P4 << " " << P7 << " " << P6 << " " << v.R << " " << v.G << " " << v.B << " " << v.alpha << endl;
          // Face de fora
          fout << 4 << " " << P1 << " " << P6 << " " << P7 << " " << P2 << " " << v.R << " " << v.G << " " << v.B << " " << v.alpha << endl;
          // Face de cima
          fout << 4 << " " << P3 << " " << P2 << " " << P7 << " " << P4 << " " << v.R << " " << v.G << " " << v.B << " " << v.alpha << endl;
        }
      }
    }
  }
}

void Sculptor::putVoxel(int X, int Y, int Z) {
  // Adiciona uma box com tamanho 1x1x1
  l.push_back(new Box(X + 1 / 2.0, Y + 1 / 2.0, Z + 1 / 2.0, R, G, B, alpha, true, 1, 1, 1));
}

void Sculptor::cutVoxel(int X, int Y, int Z) {
  // Retira uma box com tamanho 1x1x1
  l.push_back(new Box(X + 1 / 2.0, Y + 1 / 2.0, Z + 1 / 2.0, 0.0, 0.0, 0.0, 0.0, false, 1, 1, 1));
}

void Sculptor::putEllipsoid(int Xc, int Yc, int Zc, int Rx, int Ry, int Rz) {
  l.push_back(new Ellipsoid(Xc, Yc, Zc, R, G, B, alpha, true, abs(Rx), abs(Ry), abs(Rz) ));
}
void Sculptor::cutEllipsoid(int Xc, int Yc, int Zc, int Rx, int Ry, int Rz) {
    l.push_back(new Ellipsoid(Xc, Yc, Zc, R, G, B, alpha, false, abs(Rx), abs(Ry), abs(Rz) ));
}

void Sculptor::putSphere(int Xc, int Yc, int Zc, int r) {
  l.push_back(new Ellipsoid(Xc, Yc, Zc, R, G, B, alpha, true, abs(r), abs(r), abs(r) ));
}

void Sculptor::cutSphere(int Xc, int Yc, int Zc, int r) {
  l.push_back(new Ellipsoid(Xc, Yc, Zc, R, G, B, alpha, false, abs(r), abs(r), abs(r) ));
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
    if (minXYZ.x > current.x ) minXYZ.x = current.x;
    if (minXYZ.y > current.y ) minXYZ.y = current.y;
    if (minXYZ.z > current.z ) minXYZ.z = current.z;
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
    if (maxXYZ.x < current.x ) maxXYZ.x = current.x;
    if (maxXYZ.y < current.y ) maxXYZ.y = current.y;
    if (maxXYZ.z < current.z ) maxXYZ.z = current.z;
  }

  return maxXYZ;
}

void Sculptor::draw() {
  // Aplica a escala em toda as formas
  if (scale != 1.0) {
    for (pSolidIterator i = l.begin(); i != l.end(); ++i){
      (*i)->scale(scale);
    }
  }

  POS_3D <int> max = getMaxXYZ(), min = getMinXYZ();
  POS_3D <int> size = max - min;

  initialize(size.x, size.y, size.z, min.x, min.y, min.z);

  for (pSolidIterator i = l.begin(); i != l.end(); ++i){
    (*i)->sculpt(*this);
  }

  removeIrrelevantVoxels();

}

void Sculptor::putCylinder(int Xc, int Zc, int Y0, int Y1, int r) {
  l.push_back(new Cylinder(Xc, (Y0 + Y1) / 2.0, Zc, R, G, B, alpha, true, abs(r), abs(Y1 - Y0) ));
}
void Sculptor::cutCylinder(int Xc, int Zc, int Y0, int Y1, int r) {
  l.push_back(new Cylinder(Xc, (Y0 + Y1) / 2.0, Zc, R, G, B, alpha, false, abs(r), abs(Y1 - Y0) ));
}

void Sculptor::putToriod(int Xc, int Yc, int Zc, int Rt, int Rp) {
  l.push_back(new Toroid(Xc, Yc, Zc, R, G, B, alpha, true, abs(Rt), abs(Rp)) );
}

void Sculptor::cutToriod(int Xc, int Yc, int Zc, int Rt, int Rp) {
  l.push_back(new Toroid(Xc, Yc, Zc, R, G, B, alpha, false, abs(Rt), abs(Rp)) );
}


void Sculptor::putCone(int Xc, int Yc, int Z0, int Z1, int r) {
  l.push_back(new Cone(Xc, Yc, (Z0 + Z1) / 2.0, R, G, B, alpha, true, abs(r), abs(r), abs(Z1 - Z0) ));
}
void Sculptor::cutCone(int Xc, int Yc, int Z0, int Z1, int r) {
  l.push_back(new Cone(Xc, Yc, (Z0 + Z1) / 2.0, R, G, B, alpha, false, abs(r), abs(r), abs(Z1 - Z0) ));
}
