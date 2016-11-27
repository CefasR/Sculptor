#ifndef _SOLIDS_H_
#define _SOLIDS_H_

#include "Canvas.h"
using namespace std;

class Solid : protected Voxel {
protected:
  POS_3D <float> pos;

public:

  inline Solid (
    // Posição XYZ
    float x=0.0, float y=0.0, float z=0.0,
    // Cor + Alpha
    float r=0.0, float g=0.0, float b=0.0, float a=1.0,
    // Ativo (sim ou não)
    bool on=true
  ) : pos(x, y, z), Voxel::Voxel (r, g, b, a, on) {}

  // Método virtual para sculpt o Solid
  virtual void sculpt(Canvas& c) const = 0;


  // Métodos opcionais
  // void trasladar(int x, int y, int z);
  // void rotacionar(float a_x_y, float a_x_z, float a_y_z);

  virtual int getMaxX() const = 0;
  virtual int getMaxY() const = 0;
  virtual int getMaxZ() const = 0;

  virtual int getMinX() const = 0;
  virtual int getMinY() const = 0;
  virtual int getMinZ() const = 0;

  inline void setColor(float r, float g, float b) {
    R = r; G = g; B = b;
  }

  inline void setPos(float x, float y, float z) {
    pos.x = x; pos.y = y; pos.z = z;
  }

  inline void translade(float x, float y, float z) {
    pos.x += x; pos.y += y; pos.z += z;
  }

  inline virtual ~Solid() {}

};


class Box : public Solid {
  unsigned int width, length, height;
public:
  inline Box(
    // Posição XYZ
    float x=0.0, float y=0.0, float z=0.0,
    // Cor + Alpha
    float r=0.0, float g=0.0, float b=0.0, float a=1.0,
    // Ativo (sim ou não)
    bool on=true,
    // Largura (eixo x) | Comprimento (eixo y) | Altura (eixo z)
    unsigned int w=1, unsigned int l=1, unsigned int h=1
  ) : Solid(x, y, z, r, g, b, a, on), width(w), length(l), height(h) { }

  // sculpt a Solid
  void sculpt(Canvas& c) const;

  int getMaxX() const;
  int getMaxY() const;
  int getMaxZ() const;

  int getMinX() const;
  int getMinY() const;
  int getMinZ() const;
};


// class Sphere : public Solid{
//   unsigned int radius;
// public:
//   inline Sphere(
//     int x=0.0,
//     int y=0.0,
//     int z=0.0,
//     float r=0.0,
//     float g=0.0,
//     float b=0.0,
//     float a=1.0,
//     bool on=true,
//     float r_=1.0
//   ) : Solid(x, y, z, r, g, b, a, on), radius(abs(r_)){}
//
//   // sculpt a Solid
//   // template <unsigned const size_x, unsigned const size_y, unsigned const size_z>
//   void sculpt(Canvas& c) const;
//
//   unsigned int getMaxX() const;
//   unsigned int getMaxY() const;
//   unsigned int getMaxZ() const;
//
//   unsigned int getMinX() const;
//   unsigned int getMinY() const;
//   unsigned int getMinZ() const;
// };


class Cylinder : public Solid{
  float radius, height;
public:
  inline Cylinder (
    // Posição XYZ
    float x=0.0, float y=0.0, float z=0.0,
    // Cor + Alpha
    float r=0.0, float g=0.0, float b=0.0, float a=1.0,
    // Ativo (sim ou não)
    bool on=true,
    // Raio | Altura do cilindro
    unsigned int rad=1.0, unsigned int h=1
  ) : Solid(x, y, z, r, g, b, a, on), radius(rad), height(h) {}

  void sculpt(Canvas& c) const;

  int getMaxX() const;
  int getMaxY() const;
  int getMaxZ() const;

  int getMinX() const;
  int getMinY() const;
  int getMinZ() const;
};

class Ellipsoid : public Solid{
    float x_radius, y_radius, z_radius;
public:
    inline Ellipsoid (
        // Posição XYZ
        float x=0.0, float y=0.0, float z=0.0,
        // Cor + Alpha
        float r=0.0, float g=0.0, float b=0.0, float a = 1.0,
        // Ativo (sim ou não)
        bool on = true,
        // Raios do elipsoide
        float rx = 1.0, float ry = 1.0, float rz = 1.0
      ) : Solid(x, y, z, r, g, b, a, on), x_radius(rx), y_radius(ry), z_radius(rz){}

      void sculpt(Canvas& c) const;

      int getMaxX() const;
      int getMaxY() const;
      int getMaxZ() const;

      int getMinX() const;
      int getMinY() const;
      int getMinZ() const;
};

typedef Solid *pSolid;

#endif //_SOLIDS_H_
