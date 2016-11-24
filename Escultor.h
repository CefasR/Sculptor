#ifndef _ESCULTOR_H_
#define _ESCULTOR_H_

#include <iostream>
#include <list>
using namespace std;

typedef float byte;

struct Voxel{
  byte R, G, B;
  float alpha;
  bool is_on;

  Voxel(
      byte r=0.0,
      byte g=0.0,
      byte b=0.0,
      float a=1.0,
      bool on=false
  ):R(r), G(g), B(b), alpha(a), is_on(on){}
};


struct XYZ_POS{
  unsigned int x, y, z;

  XYZ_POS(unsigned int x_=0, unsigned int y_=0, unsigned int z_=0): x(x_), y(y_), z(z_){}
};

class Forma{
protected:
  XYZ_POS pos;
  byte R, G, B;
  float alpha;
  bool is_on;
public:

  inline Forma(
    int x=0,
    int y=0,
    int z=0,
    byte r=0.0,
    byte g=0.0,
    byte b=0.0,
    float a=1.0,
    bool on=true
  ) : pos(x, y, z), R(r), G(g), B(b), alpha(a), is_on(on) {}

  // Método virtual para esculpir a forma
  virtual unsigned int esculpir(Voxel ***matriz) const = 0;


  // Métodos opcionais
  // void trasladar(int x, int y, int z);
  // void rotacionar(float a_x_y, float a_x_z, float a_y_z);

  virtual unsigned int getMaxX() const = 0;
  virtual unsigned int getMaxY() const = 0;
  virtual unsigned int getMaxZ() const = 0;

  virtual unsigned int getMinX() const = 0;
  virtual unsigned int getMinY() const = 0;
  virtual unsigned int getMinZ() const = 0;
};


class Caixa : public Forma{
  unsigned int x_size, y_size, z_size;
public:
  inline Caixa(
    int x=0,
    int y=0,
    int z=0,
    byte r=0.0,
    byte g=0.0,
    byte b=0.0,
    float a=1.0,
    bool on=true,
    unsigned int s_x=1,
    unsigned int s_y=1,
    unsigned int s_z=1
  ) : Forma(x, y, z, r, g, b, a, on), x_size(s_x), y_size(s_y), z_size(s_z){}

  // Esculpir a forma
  // template <unsigned const size_x, unsigned const size_y, unsigned const size_z>
  unsigned int esculpir(Voxel ***matriz) const;

  unsigned int getMaxX() const;
  unsigned int getMaxY() const;
  unsigned int getMaxZ() const;

  unsigned int getMinX() const;
  unsigned int getMinY() const;
  unsigned int getMinZ() const;
};


class Esfera : public Forma{
  unsigned int raio;
public:
  inline Esfera(
    int x=0,
    int y=0,
    int z=0,
    byte r=0.0,
    byte g=0.0,
    byte b=0.0,
    float a=1.0,
    bool on=true,
    unsigned int r_=1
  ) : Forma(x, y, z, r, g, b, a, on), raio(r_){}

  // Esculpir a forma
  // template <unsigned const size_x, unsigned const size_y, unsigned const size_z>
  unsigned int esculpir(Voxel ***matriz) const;

  unsigned int getMaxX() const;
  unsigned int getMaxY() const;
  unsigned int getMaxZ() const;

  unsigned int getMinX() const;
  unsigned int getMinY() const;
  unsigned int getMinZ() const;
};


class Cilindro : public Forma{
  unsigned int raio, altura;
public:
  inline Cilindro(
    int x=0,
    int y=0,
    int z=0,
    byte r=0.0,
    byte g=0.0,
    byte b=0.0,
    float a=1.0,
    bool on=true,
    unsigned int r_=1,
    unsigned int alt=1
  ) : Forma(x, y, z, r, g, b, a, on), raio(r_), altura(alt){}

  unsigned int esculpir(Voxel ***matriz) const;

  unsigned int getMaxX() const;
  unsigned int getMaxY() const;
  unsigned int getMaxZ() const;

  unsigned int getMinX() const;
  unsigned int getMinY() const;
  unsigned int getMinZ() const;
};

#endif
