#ifndef _ESCULTOR_H_
#define _ESCULTOR_H_

#include <iostream>
#include <vector>
#include <list>
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


// Estrutura que guarda um vetor em R³
struct POS_3D {
  float x, y, z;

  POS_3D (float px=0.0, float py=0.0, float pz=0.0): x(px), y(py), z(pz) { }
};


// Classe que auxilia na manipulação de uma matriz 3D de voxels
class Canvas {
protected:
  unsigned int dimX, dimY, dimZ;
  vector <Voxel> x;

public:
  friend inline int Location(unsigned int NC,unsigned int NP, int i, int j, int k) {
    int n = (NC*NP*i + NP*j + k);
    return n;
  }

  inline const Voxel & at(unsigned i, unsigned j, unsigned k) const {
    return x.at(i * dimX + j * dimY + k);
  }

  inline Voxel & at(unsigned i, unsigned j, unsigned k) {
    return x.at(i * dimX + j * dimY + k);
  }
};

class Solid : protected Voxel {
protected:
  POS_3D pos;

public:

  inline Solid (
    float x=0.0,
    float y=0.0,
    float z=0.0,
    float r=0.0,
    float g=0.0,
    float b=0.0,
    float a=1.0,
    bool on=true
  ) : pos(x, y, z), Voxel::Voxel(r, g, b, a, on) {}

  // Método virtual para sculpt o Solid
  virtual void sculpt(Canvas& c) const = 0;


  // Métodos opcionais
  // void trasladar(int x, int y, int z);
  // void rotacionar(float a_x_y, float a_x_z, float a_y_z);

  virtual unsigned int getMaxX() const = 0;
  virtual unsigned int getMaxY() const = 0;
  virtual unsigned int getMaxZ() const = 0;

  virtual unsigned int getMinX() const = 0;
  virtual unsigned int getMinY() const = 0;
  virtual unsigned int getMinZ() const = 0;

  inline void setColor(float r, float g, float b) {
    R = r; G = g; B = b;
  }

  inline void setPos(float x, float y, float z) {
    pos.x = x; pos.y = y; pos.z = z;
  }

  inline void translade(float x, float y, float z) {
    pos.x += x; pos.y += y; pos.z += z;
  }

};


class Box : public Solid {
  unsigned int x_size, y_size, z_size;
public:
  inline Box(
    int x=0.0,
    int y=0.0,
    int z=0.0,
    float r=0.0,
    float g=0.0,
    float b=0.0,
    float a=1.0,
    bool on=true,
    unsigned int s_x=1,
    unsigned int s_y=1,
    unsigned int s_z=1
  ) : Solid(x, y, z, r, g, b, a, on), x_size(s_x), y_size(s_y), z_size(s_z){}

  // sculpt a Solid
  // template <unsigned const size_x, unsigned const size_y, unsigned const size_z>
  void sculpt(Canvas& c) const;

  unsigned int getMaxX() const;
  unsigned int getMaxY() const;
  unsigned int getMaxZ() const;

  unsigned int getMinX() const;
  unsigned int getMinY() const;
  unsigned int getMinZ() const;
};


class Sphere : public Solid{
  unsigned int raio;
public:
  inline Sphere(
    int x=0.0,
    int y=0.0,
    int z=0.0,
    float r=0.0,
    float g=0.0,
    float b=0.0,
    float a=1.0,
    bool on=true,
    unsigned int r_=1
  ) : Solid(x, y, z, r, g, b, a, on), raio(r_){}

  // sculpt a Solid
  // template <unsigned const size_x, unsigned const size_y, unsigned const size_z>
  void sculpt(Canvas& c) const;

  unsigned int getMaxX() const;
  unsigned int getMaxY() const;
  unsigned int getMaxZ() const;

  unsigned int getMinX() const;
  unsigned int getMinY() const;
  unsigned int getMinZ() const;
};


class Cylinder : public Solid{
  unsigned int raio, altura;
public:
  inline Cylinder(
    int x=0.0,
    int y=0.0,
    int z=0.0,
    float r=0.0,
    float g=0.0,
    float b=0.0,
    float a=1.0,
    bool on=true,
    unsigned int r_=1,
    unsigned int alt=1
  ) : Solid(x, y, z, r, g, b, a, on), raio(r_), altura(alt){}

  void sculpt(Canvas& c) const;

  unsigned int getMaxX() const;
  unsigned int getMaxY() const;
  unsigned int getMaxZ() const;

  unsigned int getMinX() const;
  unsigned int getMinY() const;
  unsigned int getMinZ() const;
};

class Ellipsoid : public Solid{
    float raio1, raio2, raio3;
public:
    inline Ellipsoid(
        int x=0.0,
        int y=0.0,
        int z=0.0,
        float r=0.0,
        float g=0.0,
        float b=0.0,
        float a = 1.0,
        bool on = true,
        float r_1 = 2.0,
        float r_2 = 1.0,
        float r_3 = 2.0
        ):Solid(x ,y ,z ,r ,g ,b ,a ,on), raio1(r_1), raio2(r_2), raio3(r_3){}

        void sculpt(Canvas& c) const;

        unsigned int getMaxX() const;
        unsigned int getMaxY() const;
        unsigned int getMaxZ() const;

        unsigned int getMinX() const;
        unsigned int getMinY() const;
        unsigned int getMinZ() const;
};

typedef Solid *pSolid;

class Sculptor : private Canvas{
private:
    list<pSolid> x;
    int Xmin, Xmax, Ymin, Ymax, Zmin, Zmax;
public:
    void setColor(float R, float G, float B, float A);
    void putVoxel(int X, int Y, int Z);
    void cutVoxel(int X, int Y, int Z);
    void putBox(int X0, int X1,
                int Y0, int Y1,
                int Z0, int Z1);
    void cutBox(int X0, int X1,
                int Y0, int Y1,
                int Z0, int Z1);
    void putSphere(int Xc, int Yc, int Zc, int R);
    void cutSphere(int Xc, int Yc, int Zc, int R);
    void putEllipsoid(int Xc, int Yc, int Zc,
                      int Rx, int Ry, int Rz);
    void cutEllipsoid(int Xc, int Yc, int Zc,
                      int Rx, int Ry, int Rz);
    void putCylinder(int Xc, int Yc, int Zc,
                     int R, int altura);
    void cutCylinder(int Xc, int Yc, int Zc,
                     int R, int altura);
    void cleanVoxels(void);
    void write(const char *Arq);
};

#endif
