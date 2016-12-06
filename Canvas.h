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

const POS_3D <unsigned int> origin(0, 0, 0);

template <class T>
T ManhattanDistance(POS_3D <T> a, POS_3D <T> b) {
  return abs(a.x - b.x) + abs(a.y - b.y) + abs(a.z - b.z);
}

enum AXIS{
  X, Y, Z
};

class TransformationMatrix {
protected:
  float m[4][4];
  inline void fill (bool is_identity = false) {
    for (unsigned i = 0; i < 4; i++) {
      for (unsigned j = 0; j < 4; j++) {
        if (is_identity && i == j)  m[i][j] = 1;
        else m[i][j] = 0;
      }
    }
  }
public:
  TransformationMatrix (bool is_identity = true) {
    fill(is_identity);
  }

  inline TransformationMatrix & operator * (TransformationMatrix matrix) {
    TransformationMatrix tmp(false);
    for (unsigned i = 0; i < 4; i++) {
      for (unsigned j = 0; j < 4; j++) {
        for (unsigned k = 0; k < 4; k++) {
          tmp.m[i][j] += m[i][k] * matrix.m[k][j];
        }
      }
    }

    return *this = tmp;
  }

  inline friend ostream & operator << (ostream & out, const TransformationMatrix & m ) {
    for (unsigned i = 0; i < 4; i++) {
      for (unsigned j = 0; j < 4; j++) {
        out << m.m[i][j] << " ";
      }

      out << endl;
    }

    return out;
  }

  inline const TransformationMatrix operator * (TransformationMatrix matrix) const {
    TransformationMatrix tmp(false);
    return tmp = (*this ) * matrix;
  }

  POS_3D <float> transform (POS_3D <float> pos) const {
    // Vetor resultante
    return POS_3D <float> (
      pos.x * m[0][0] + pos.y * m[0][1] + pos.z * m[0][2] + m[0][3],
      pos.x * m[1][0] + pos.y * m[1][1] + pos.z * m[1][2] + m[1][3],
      pos.x * m[2][0] + pos.y * m[2][1] + pos.z * m[2][2] + m[2][3]
    );
  }

};

class TranslationMatrix : public TransformationMatrix {
public:
  inline TranslationMatrix (POS_3D <float> v) : TransformationMatrix(){
    m[0][3] = v.x; m[1][3] = v.y; m[2][3] = v.z;
  }
};


class RotationMatrix : public TransformationMatrix {
public:
  RotationMatrix (float angle, AXIS & a) {
    fill(true);
    switch (a) {
      case X:
        m[1][1] = cos(angle);   m[1][2] = sin(angle);
        m[2][1] = -sin(angle);  m[2][2] = cos(angle);
        break;

      case Y:
        m[0][0] = cos(angle);  m[0][2] = -sin(angle);
        m[2][0] = sin(angle);  m[2][2] = cos(angle);
        break;

      case Z:
        m[0][0] = cos(angle);   m[0][1] = sin(angle);
        m[1][0] = -sin(angle);  m[1][1] = cos(angle);
        break;

    }
  }
};

typedef vector<Voxel>::iterator VoxelIterator;

// Classe que auxilia na manipulação de uma matriz 3D de voxels
class Canvas{
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
  inline POS_3D <unsigned int> getNormalPos (int x, int y, int z) { return POS_3D <unsigned int> ( (x - minXYZ.x), (y - minXYZ.y), (z - minXYZ.z) ); }

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
