#ifndef _CANVAS_H_
#define _CANVAS_H_

#include <iostream>
#include <vector>
#include <cmath>
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

  inline friend ofstream & operator << (ofstream & out, const POS_3D & pos) { out << pos.x << " " << pos.y << " " << pos.z; return out; }
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
        i * dimX * dimY +
        j * dimY + k
      );
  }

  // Retorna o elemento da posição espefificada
  inline Voxel & at(int i, int j, int k) {
    return x.at (
      i * dimX * dimY +
      j * dimY + k
    );
  }

  // Retorna o elemento da posição espefificada
  inline const Voxel & at(const POS_3D <unsigned int> pos) const {
      return x.at (
        pos.x * dimX * dimY +
        pos.y * dimY + pos.z
      );
  }

  // Retorna o elemento da posição espefificada
  inline Voxel & at(const POS_3D <unsigned int> pos) {
    return x.at (
      pos.x * dimX * dimY +
      pos.y * dimY + pos.z
    );
  }

  // Retorna a quantidade de vértices do canvas
  inline unsigned getNVertices() const { return (dimX + 1) * (dimY + 1) * (dimZ + 1); }

  // Retorna a quantidade de faces do canvas
  inline unsigned getNEdges() {
    unsigned qtd(0);
    for (VoxelIterator i = x.begin();  i != x.end(); ++i) if ((*i).is_on) ++qtd;
    return qtd;
  }
};

#endif //_CANVAS_H_
