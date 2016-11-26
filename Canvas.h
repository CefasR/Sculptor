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
};

// Classe que auxilia na manipulação de uma matriz 3D de voxels
class Canvas {
protected:
  unsigned int dimX, dimY, dimZ;
  vector <Voxel> x;
  POS_3D <int> minXYZ;
public:
  friend inline int Location(unsigned int NC,unsigned int NP, int i, int j, int k) {
    int n = (NC*NP*i + NP*j + k);
    return n;
  }

  // Inicializa o canvas com os tamanhos especificados
  inline void initialize(unsigned dx, unsigned dy, unsigned dz, int mx=0, int my=0, int mz=0)
  {
    minXYZ = POS_3D <int> (mx, my, mz); dimX = unsigned(dx); dimY = unsigned(dy); dimZ = unsigned(dz);
    // Iniciaza o vetror com todos os voxeis
    x = vector <Voxel> (dimX * dimY * dimZ, Voxel());
  }

  // Retorna o elemento da posição espefificada considerando as coordenadas mínimas do canvas
  inline const Voxel & at(int i, int j, int k) const {
      return x.at( abs(
        (i - minXYZ.x) * dimX * dimY +
        (j - minXYZ.y) * dimY +
        k - minXYZ.z
      ));
  }

  // Retorna o elemento da posição espefificada considerando as coordenadas mínimas do canvas
  inline Voxel & at(int i, int j, int k) {
    return x.at( abs(
      (i - minXYZ.x) * dimX * dimY +
      (j - minXYZ.y) * dimY +
      k - minXYZ.z
    ));
  }

  // Retorna a quantidade de vértices do canvas

};

#endif //_CANVAS_H_
