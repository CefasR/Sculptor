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

  inline friend ostream & operator << (ostream & out, const POS_3D <T> & pos) { out << pos.x << " " << pos.y << " " << pos.z; return out; }

  template <class T2>
  POS_3D (POS_3D <T2> pos) {
    x = pos.x; y = pos.y; z = pos.z;
  }

  inline POS_3D operator+ (POS_3D pos) const {
    return POS_3D (x + pos.x, y + pos.y, z + pos.z);
  }

  inline POS_3D operator- (POS_3D pos) const {
    return (*this) + (-pos);
  }

  inline T operator* (POS_3D pos) const{
    return (x * pos.x) +  (y * pos.y) +  (z * pos.z);
  }

  inline friend POS_3D operator- (POS_3D pos) {
    return POS_3D (-pos.x, -pos.y, -pos.z);
  }

  inline bool operator == (POS_3D pos) {
    return (x == pos.x && y == pos.y && z == pos.z);
  }

  inline bool operator != (POS_3D pos) {
    return ! (*this == pos);
  }
};

enum AXIS{
  X, Y, Z
};

typedef POS_3D <float> POS_3Df;

class Matrix3D {
protected:
    vector < POS_3Df > colunas;
public:
    Matrix3D () {
      colunas.reserve(3);
      colunas.push_back(POS_3D <float> (1.0, 0.0, 0.0));
      colunas.push_back(POS_3D <float> (0.0, 1.0, 0.0));
      colunas.push_back(POS_3D <float> (0.0, 0.0, 1.0));
    }

    friend POS_3Df operator* (POS_3Df pos, Matrix3D matrix) {
      return POS_3Df ( pos * matrix.colunas.at(0),  pos * matrix.colunas.at(1), pos * matrix.colunas.at(2) );
    }

    Matrix3D operator * (Matrix3D m) const {
      Matrix3D tmp;
    }
};

class RotationMatrix3D : public Matrix3D{
public:
  RotationMatrix3D (AXIS a, float angle) {
    colunas.reserve(3);
    switch (a) {
      case X:
        colunas.push_back(POS_3D <float> (0.0, 1.0, 0.0));
        colunas.push_back(POS_3D <float> (0.0, cos(angle), sin(angle)));
        colunas.push_back(POS_3D <float> (0.0, -sin(angle), cos(angle)));
        break;
      case Y:
        colunas.push_back(POS_3D <float> (cos(angle), 0.0, sin(angle)));
        colunas.push_back(POS_3D <float> (0.0, 1.0, 0.0));
        colunas.push_back(POS_3D <float> (-sin(angle), 0.0, -cos(angle)));
        break;
      case Z:
        colunas.push_back(POS_3D <float> (cos(angle), sin(angle), 0.0));
        colunas.push_back(POS_3D <float> (-sin(angle), cos(angle), 0.0));
        colunas.push_back(POS_3D <float> (0.0, 0.0, 1.0));
        break;
    }
  }
};

typedef vector<Voxel>::iterator VoxelIterator;

const POS_3D <unsigned int> origin(0, 0, 0);

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

  // Retorna a posição normalizada
  inline const POS_3D <unsigned int> getNormalPos (int x, int y, int z) { return POS_3D <unsigned int> ( (x - minXYZ.x), (y - minXYZ.y), (z - minXYZ.z) ); }

  inline Canvas (unsigned dx=0, unsigned dy=0, unsigned dz=0, int mx=0, int my=0, int mz=0) { initialize(dx, dy, dz, mx, my, mz); }

  // Retorna o elemento da posição espefificada
  inline const Voxel & at(unsigned i, unsigned j, unsigned k) const {
      return x.at (
        i * dimY * dimZ +
        j * dimZ + k
      );
  }

  // Retorna o elemento da posição espefificada
  inline Voxel & at(unsigned i, unsigned j, unsigned k) {
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
  unsigned getNFaces() const;

  void removeIrrelevantVoxels();

  inline unsigned int getVoxelVertexIndexAt(unsigned i, unsigned j, unsigned k) {
    return i * (dimZ + 1) * (dimY + 1) + j * (dimZ + 1) + k;
  }

  inline unsigned int getVoxelVertexIndexAt(POS_3D <unsigned int> pos) {
    getVoxelVertexIndexAt(pos.x, pos.y, pos.z);
  }
};

#endif //_CANVAS_H_
