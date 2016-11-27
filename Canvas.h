#ifndef _CANVAS_H_
#define _CANVAS_H_

#include <iostream>
#include <vector>
#include <cmath>
#include "Solids.h"
using namespace std;

// Estrutura de dados que contém as informações do voxel
struct Voxel {
  float R, G, B;
  float alpha;
  bool is_on;

  // Define valores padrões para um voxel instanciado
  Voxel (
    float r=0.0,
    float g=0.0,
    float b=0.0,
    float a=1.0,
    bool on=false
  ) : R(r), G(g), B(b), alpha(a), is_on(on) {}
};


// Estrutura que guarda um vetor em R³ de um tipo especificado
template <class T>
struct POS_3D {
  T x, y, z;

  POS_3D (T px=0, T py=0, T pz=0): x(px), y(py), z(pz) { }

  inline friend ostream & operator << (ostream & out, const POS_3D <T> & pos) { out << pos.x << " " << pos.y << " " << pos.z; return out; }

  template <class T2>
  POS_3D (POS_3D <T2> pos) {
    x = pos.x; y = pos.y; z = pos.z;
  }

  inline POS_3D operator+ (POS_3D pos) {
    x += pos.x; y += pos.y; z += pos.z;
    return *this;
  }

  inline POS_3D operator- (POS_3D pos) {
    return (*this) + (-pos);
  }

  inline friend POS_3D operator- (POS_3D pos) {
    pos.x = -pos.x; pos.y = -pos.y; pos.z = -pos.z;
    return pos;
  }

  inline bool operator==(POS_3D pos) {
    return (x == pos.x && y == pos.y && z == pos.z);
  }
};

typedef vector<Voxel>::iterator VoxelIterator;

// Classe que auxilia na manipulação de uma matriz 3D de voxels
class Canvas {
protected:
  unsigned int dimX, dimY, dimZ;
  vector <Voxel> x;
  POS_3D <int> minXYZ;

  // Inicializa o canvas com os tamanhos especificados
  inline void initialize(unsigned dx, unsigned dy, unsigned dz, int mx=0, int my=0, int mz=0)
  {
    minXYZ = POS_3D <int> (mx, my, mz); dimX = unsigned(dx); dimY = unsigned(dy); dimZ = unsigned(dz);
    // Iniciaza o vetor com todos os voxeis
    if (dimX * dimX * dimX > 0)
      x = vector <Voxel> (dimX * dimY * dimZ, Voxel());
  }
public:
  friend inline int Location(unsigned int NC,unsigned int NP, int i, int j, int k) {
    int n = (NC*NP*i + NP*j + k);
    return n;
  }

  // Retorna a posição normalizada
  inline const POS_3D <unsigned int> getNormalPos (int x, int y, int z) { return POS_3D <unsigned int> ( (x - minXYZ.x), (y - minXYZ.y), (z - minXYZ.z) ); }

  inline Canvas (unsigned dx=0, unsigned dy=0, unsigned dz=0, int mx=0, int my=0, int mz=0) { initialize(dx, dy, dz, mx, my, mz); }

  // Retorna o elemento da posição espefificada
  inline const Voxel & at(int i, int j, int k) const {
      return x.at (
        i * dimY * dimZ +
        j * dimZ + k
      );
  }

  // Retorna o elemento da posição espefificada
  inline Voxel & at(int i, int j, int k) {
    return x.at (
      i * dimY * dimZ +
      j * dimZ + k
    );
  }

  // Retorna o elemento da posição espefificada
  inline const Voxel & at(const POS_3D <unsigned int> pos) const {
      return at(pos.x, pos.y, pos.z);
  }

  // Retorna o elemento da posição espefificada
  inline Voxel & at(const POS_3D <unsigned int> pos) {
    return at(pos.x, pos.y, pos.z);
  }

  // Retorna a quantidade de vértices do canvas
  inline unsigned getNVertices() const { return (dimX + 1) * (dimY + 1) * (dimZ + 1); }

  // Retorna a quantidade de faces do canvas
  inline unsigned getNEdges() {
    unsigned qtd(0);
    for (int i = minXYZ.x; i < int(minXYZ.x + dimX); ++i) {
      for (int j = minXYZ.y; j < int(minXYZ.y + dimY); ++j) {
        for (int k = minXYZ.z; k < int(minXYZ.z + dimZ); ++k) {
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
    return qtd;
  }
};

#endif //_CANVAS_H_
