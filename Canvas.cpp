#include "Canvas.h"
using namespace std;

unsigned Canvas::getNFaces() const {
  unsigned qtd(0);
  for (int i = 0; i < dimX; ++i) {
    for (int j = 0; j < dimY; ++j) {
      for (int k = 0; k < dimZ; ++k) {
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

        // Verifica se o voxel está ativo
        if ( at(i, j, k).is_on ) {
          // As faces 4, 3 e 5 sempre serão desenhadas,
          //assim todo voxel terá ao menos 3 faces desenhadas no arquivo
          qtd += 3;
          // Verifica se a face 0 deve ser desenhada (face XZ da esqueda)
          // A codição é que esse voxel esteja na extremidade esquerda (j == 0)
          // ou que voxel do lado esquerdo não esteja marcado para ser desenhado
          if (j == 0 or !at(i, j - 1, k).is_on ) ++qtd;
          // Verifica se a face 1 deve ser desenhada (face YK de dentro)
          // A codição é que esse voxel esteja na extremidade de dentro (i == 0)
          // ou que voxel do lado dentro não esteja marcado para ser desenhado
          if (i == 0 or !at(i - 1, j, k).is_on ) ++qtd;
          // Verifica se a face 2 deve ser desenhada (face XY de dentro)
          // A codição é que esse voxel esteja na extremidade de baixo (k == 0)
          // ou que voxel do lado de baixo não esteja marcado para ser desenhado
          if (k == 0 or !at(i, j, k - 1).is_on ) ++qtd;
        }
      }
    }
  }
  return qtd;
}

typedef POS_3D <int> pInt;

void Canvas::removeIrrelevantVoxels() {
  //vector <pInt> posicoes;
  //posicoes.reserve(dimX * dimY * dimZ);

  for (int i = 0; i < dimX; ++i) {
    for (int j = 0; j < dimY; ++j) {
      for (int k = 0; k < dimZ; ++k) {
        if (
          // Se ele não pertencer a nenhuma das extremidades e se esle está ativo
          i != 0 && j != 0 && k != 0 && at(i, j, k).is_on &&
          i < (dimX - 1) && j < (dimY - 1) && k < (dimZ - 1) &&
          // Se ele estiver rodeado de mais 6 voxeis
          at(i - 1, j, k).is_on &&
          at(i + 1, j, k).is_on &&
          at(i, j - 1, k).is_on &&
          at(i, j + 1, k).is_on &&
          at(i, j, k - 1).is_on &&
          at(i, j, k + 1).is_on
        ) {
          at(i, j, k).alpha = 0.0;
         }
      }
    }
  }


    for (int i = 0; i < dimX; ++i) {
      for (int j = 0; j < dimY; ++j) {
        for (int k = 0; k < dimZ; ++k) {
          if (at(i, j, k).alpha == 0.0) at(i, j, k).is_on = false;
        }
      }
    }
}
