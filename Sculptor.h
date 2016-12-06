#ifndef _SCULPTOR_H_
#define _SCULPTOR_H_

#include <list>
#include "Solids.h"
#include "Canvas.h"
using namespace std;

typedef list <pSolid>::iterator pSolidIterator;

class Sculptor : protected Canvas {
private:
    list <pSolid> l;
    float R, G, B, alpha, scale;
public:

    explicit inline Sculptor(float sc=1.0) : Canvas::Canvas(), R(0.0), G(0.0), B(0.0), alpha(1.0), scale(sc) { }

    void setColor(float R, float G, float B, float A) { this->R = R; this->G = G; this->B = B; alpha = A; };
    void putVoxel(int X, int Y, int Z);
    void cutVoxel(int X, int Y, int Z);
    void putBox(int X0, int X1,
                int Y0, int Y1,
                int Z0, int Z1);
    void cutBox(int X0, int X1,
                int Y0, int Y1,
                int Z0, int Z1);
    void putSphere(int Xc, int Yc, int Zc, int r);
    void cutSphere(int Xc, int Yc, int Zc, int r);
    void putEllipsoid(int Xc, int Yc, int Zc,
                      int Rx, int Ry, int Rz);
    void cutEllipsoid(int Xc, int Yc, int Zc,
                      int Rx, int Ry, int Rz);
    void putCylinder(int Xc, int Zc, int Y0, int Y1,
                      int r);
    void cutCylinder(int Xc, int Zc, int Y0, int Y1,
                      int r);
    void putCone(int Xc, int Yc, int Z0, int Z1,
                      int r);
    void cutCone(int Xc, int Yc, int Z0, int Z1,
                      int r);
    void putToriod(int Xc, int Yc, int Zc,
                    int Rt, int Rp);
    void cutToriod(int Xc, int Yc, int Zc,
                    int Rt, int Rp);
    void cleanVoxels(void);
    void write(const char *Arq);

    void setScale(float v) {
      scale = abs(v);
    }


    inline Solid & getSolidAt(unsigned n){
        list <pSolid> :: iterator i = l.begin();
        advance(i, n);
        return *(*i);
    }

    inline Solid & getLastSolid(){

        return *l.back();
    }

    // Retorna a extremidade mínima
    POS_3D <int> getMinXYZ();

    // Retorna a extremidade máxima
    POS_3D <int> getMaxXYZ();

    // Desenha as formas no canvas
    void draw();

};

#endif //_SCULPTOR_H_
