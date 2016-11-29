#include "Sculptor.h"
#include <fstream>
using namespace std;


void Sculptor::write(const char *Arq)
{
  ofstream fout(Arq);

  draw();

  fout << "OFF" << endl;
  fout << getNVertices() << " " << getNEdges() << " " << 0 << endl;

  POS_3D <int> pos;

  // Desenha dodos os vértices no arquivo
  pos = origin;

  for (int i = 0; i < dimX + 1; i++) {
    for (int j = 0; j < dimY + 1; j++) {
      for (int k = 0; k < dimZ + 1; k++) {

        POS_3D <int> pos(i, j, k);

    POS_3D <float> current = POS_3D <float> (-0.5, -0.5, -0.5) + pos;
    fout << current << endl;
        // POS_3D <int> pos = getNormalPos (i, j, k);
        //
        // // Vértices da face X da esquerda
        // POS_3D <float> P0 = POS_3D <float> (-0.5, -0.5, -0.5) + pos;
        // POS_3D <float> P1 = POS_3D <float> ( 0.5, -0.5, -0.5) + pos;
        // POS_3D <float> P2 = POS_3D <float> ( 0.5, -0.5,  0.5) + pos;
        // POS_3D <float> P3 = POS_3D <float> (-0.5, -0.5,  0.5) + pos;
        //
        // // Vértices da face Y de dentro
        // POS_3D <float> P4 = POS_3D <float> (-0.5,  0.5,  0.5) + pos;
        // POS_3D <float> P5 = POS_3D <float> (-0.5,  0.5, -0.5) + pos;
        //
        // // Vétices da K de baixo
        // POS_3D <float> P6 = POS_3D <float> ( 0.5,  0.5, -0.5) + pos;
        //
        // // Vétices da face X da direita
        // POS_3D <float> P7 = POS_3D <float> ( 0.5,  0.5,  0.5) + pos;
        //
        // /*
        // ORDEM DE DESENHO: 0 (P0), 1 (P1), 2 (P2), 3 (P3), 4 (P4), 5 (P5), 6 (P6), 7 (P7)
        //
        //                3 . . . . . . . 4
        //             .  .    .       .  .
        //          2 . . . . . . . 7     .
        //          .     .      .  .     .
        //          .  .  .    .    .  .  .
        //          .     . .       .     .
        //          .     0 . . . . . . . 5
        //          .  .       .    .  .
        //          1 . . . . . . . 6
        // */
        //
        //
        // if ( pos == POS_3D <int> (0, 0, 0) ) fout << P0 << endl;
        //
        // if ( pos.y == 0 ) {
        //   if (pos.z == 0) fout << P1 << endl;
        //   fout << P2 << endl;
        //   if (pos.x == 0) fout << P3 << endl;
        // }
        //
        // if (pos.x == 0) {
        //   fout << P4 << endl;
        //   if (pos.z == 0) fout << P5 << endl;
        // }
        //
        // if (pos.z == 0) fout << P6 << endl;
        //
        // fout << P7 << endl;

  }}}

  pos = origin;

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

  }}}

  // Desenha todas as faces no arquivo
  // for (int i = 0; i < dimX; ++i) {
  //   for (int j = 0; j < dimY; ++j) {
  //     for (int k = 0; k < dimZ; ++k) {
  //       unsigned n = (i + 1) * (dimY + 1) * (dimZ + 1) + (j + 1) * (dimZ + 1);
  //       /*
  //                   EXPLICAÇÃO
  //
  //                      . . . . . . . . .
  //                   .  .    5       .  .
  //                . . . . . . . . .     .
  //                .     .      1  .     .
  //                .  0  .    .    .  3  .
  //                .     . 4       .     .
  //                .     . . . . . . . . .
  //                .  .       2    .  .
  //                . . . . . . . . .
  //
  //           Face 0 - plano XZ da esquerda
  //           Face 1 - plano YZ de dentro
  //           Face 2 - plano XY de baixo
  //           Face 3 - plano XZ da direita
  //           Face 4 - plano YZ de fora
  //           Face 5 - plano XY de cima
  //       */
  //       Voxel current = at(i, j, k);
  //       if ( current.is_on ) {
  //         // As faces 4, 3 e 5 sempre serão desenhadas,
  //         //assim todo voxel terá ao menos 3 faces desenhadas no arquivo
  //         //qtd += 3;
  //         // Verifica se a face 0 deve ser desenhada (face XZ da esqueda)
  //         // A codição é que esse voxel esteja na extremidade esquerda (j == 0)
  //         // ou que voxel do lado esquerdo não esteja marcado para ser desenhado
  //         // Desenha a face 0
  //         if (j == 0 or !at(i, j - 1, k).is_on ) {
  //           fout << 4 << " "
  //                << current.R << " "
  //                << current.G << " "
  //                << current.B << " "
  //                << current.alpha << " "
  //                <<
  //         }
  //         // Verifica se a face 1 deve ser desenhada (face YK de dentro)
  //         // A codição é que esse voxel esteja na extremidade de dentro (i == 0)
  //         // ou que voxel do lado dentro não esteja marcado para ser desenhado
  //         //if (i == 0 or !at(i - 1, j, k).is_on ) ++qtd;
  //         // Verifica se a face 2 deve ser desenhada (face XY de dentro)
  //         // A codição é que esse voxel esteja na extremidade de baixo (k == 0)
  //         // ou que voxel do lado de baixo não esteja marcado para ser desenhado
  //         //if (k == 0 or !at(i, j, k - 1).is_on ) ++qtd;
  //       }
  //     }
  //   }
  // }

}

void Sculptor::putVoxel(int X, int Y, int Z) {
  // Adiciona uma box com tamanho 1x1x1
  l.push_back(new Box(X, Y, Z, R, G, B, alpha));
}

void Sculptor::cutVoxel(int X, int Y, int Z) {
  // Retira uma box com tamanho 1x1x1
  l.push_back(new Box(X, Y, Z, 0.0, 0.0, 0.0, 0.0, false));
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

    cout << (*i)->getMinY() << endl;

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

    cout << (*i)->getMaxX() << endl;

    // Verifica se é o primeiro ou se o corrente é menor que o mínimo atual
    if (i == l.begin()) maxXYZ = current;
    else if (maxXYZ.x < current.x ) maxXYZ.x = current.x;
    else if (maxXYZ.y < current.y ) maxXYZ.y = current.y;
    else if (maxXYZ.z < current.z ) maxXYZ.z = current.z;
  }

  return maxXYZ;
}

void Sculptor::draw() {
  POS_3D <int> max = getMaxXYZ(), min = getMinXYZ();
  POS_3D <int> size = max - min;

  initialize(size.x, size.y, size.z, min.x, min.y, min.z);

  cout << "oa " << ( POS_3D <int> (dimX, dimY, dimZ)) << endl;

  for (pSolidIterator i = l.begin(); i != l.end(); ++i){
    (*i)->sculpt(*this);
  }

  removeIrrelevantVoxels();
}

void Sculptor::putCylinder(int Xc, int Yc, float Zc, int r, int height){
  l.push_back(new Cylinder(Xc, Yc, Zc, R, G, B, alpha, true, abs(r), abs(height) ));
}
void Sculptor::cutCylinder(int Xc, int Yc, float Zc, int r, int height){
  l.push_back(new Cylinder(Xc, Yc, Zc, R, G, B, alpha, false, abs(r), abs(height) ));
}
