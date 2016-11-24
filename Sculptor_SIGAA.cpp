#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct Voxel {
    float r,g,b; // Colors
    float a;     // Transparency
    bool is_on;  // Included or not
};

class Canvas   // Matrix 3D de Voxels
{
private:
    // Matriz 3D:
    // De 0 a dimX-1, 0 a dimY-1, 0 a dimZ-1
    unsigned dimX, dimY, dimZ;
    vector<Voxel> x;
};

class Solid
{
};

typedef Solid *pSolid;

class Box: public Solid
{
};

class Sculptor
{
private:
    list<pSolid> x;
    // Sculptor:
    // De Xmin a Xmax, Ymin a Ymax, Zmin a Zmax
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
    void cleanVoxels(void);
    void write(const char *Arq);
};
