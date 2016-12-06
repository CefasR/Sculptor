#ifndef _SOLIDS_H_
#define _SOLIDS_H_

#include "Canvas.h"
using namespace std;

class Solid : protected Voxel {
protected:
  POS_3D <float> pos;
  TransformationMatrix TM;

  virtual POS_3D <float> getLimMin() const = 0;
  virtual POS_3D <float> getLimMax() const = 0;

public:
  inline Solid (
    float x=0.0,
    float y=0.0,
    float z=0.0,
    float r=0.0, float g=0.0, float b=0.0, float a=1.0,
    bool on=true
  ) : pos(x, y, z), Voxel::Voxel (r, g, b, a, on) { }

  // Método virtual para sculpt o Solid
  virtual void sculpt(Canvas& c) const = 0;

  inline void translate(float x, float y, float z) {
    TM = TranslationMatrix(POS_3D <float>(x, y, z)) * TM;
  }
  inline void rotate(float angle, AXIS a, int x, int y, int z) {
    TM = RotationMatrix(angle, a) * TM;
  }

  inline void rotate(float angle, AXIS a) {
    TM = TranslationMatrix(pos) * RotationMatrix(angle, a) * TranslationMatrix(-pos) * TM;
  }

  int getMaxX() const;
  int getMaxY() const;
  int getMaxZ() const;

  int getMinX() const;
  int getMinY() const;
  int getMinZ() const;

  inline void setColor(float r, float g, float b) {
    R = r; G = g; B = b;
  }

  inline void setPos(float x, float y, float z) {
    pos.x = x; pos.y = y; pos.z = z;
  }
  inline virtual ~Solid() {}

};


class Box : public Solid {
protected:
  POS_3D <float> getLimMin() const;
  POS_3D <float> getLimMax() const;

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
};

class Cylinder : public Solid{
protected:
  POS_3D <float> getLimMin() const;
  POS_3D <float> getLimMax() const;

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
};

class Ellipsoid : public Solid{
protected:
  POS_3D <float> getLimMin() const;
  POS_3D <float> getLimMax() const;

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
};

class Toroid : public Solid {
protected:
  POS_3D <float> getLimMin() const;
  POS_3D <float> getLimMax() const;

  float t_radius, p_radius;
public:
    inline Toroid (
        // Posição XYZ
        float x=0.0, float y=0.0, float z=0.0,
        // Cor + Alpha
        float r=0.0, float g=0.0, float b=0.0, float a = 1.0,
        // Ativo (sim ou não)
        bool on = true,
        // Raios do toroide
        float tR = 1.0, float pR = 1.0
      ) : Solid(x, y, z, r, g, b, a, on), t_radius(tR), p_radius(pR) {}

      void sculpt(Canvas& c) const;
};

class Cone : public Solid {
protected:
  POS_3D <float> getLimMin() const;
  POS_3D <float> getLimMax() const;

  float x_radius, y_radius, height;
public:
  inline Cone (
    // Posição XYZ
    float x=0.0, float y=0.0, float z=0.0,
    // Cor + Alpha
    float r=0.0, float g=0.0, float b=0.0, float a = 1.0,
    // Ativo (sim ou não)
    bool on = true,
    // Raios do toroide
    float xR = 1.0, float yR = 1.0, float h = 1.0
  ) : Solid(x, y, z, r, g, b, a, on), x_radius(xR), y_radius(yR), height(h) {}

  void sculpt(Canvas& c) const;
};

typedef Solid *pSolid;

#endif //_SOLIDS_H_
