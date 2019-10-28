#ifndef TORUS_H
#define TORUS_H

#include "triMesh.h"

class Torus : public TriMesh
{
public:
    Torus(int nbCercles=20, int vertexCercle=20);
};

#endif // TORUS_H
