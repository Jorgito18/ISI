#include "diskhole.h"
#include "cmath"

DiskHole::DiskHole(int nbVertices, float radius, int ndisk) : TriMesh()
{
    _name = "DiskHole";

    //vertices
    for (int i=0;i<ndisk;++i) {
        float r = 1-(1-radius)*i/((float)ndisk-1);
        this->addVertex(0,0,0);
        for (float i=0; i<2*M_PI ; i+=(2/(float)nbVertices)*M_PI)
            this->addVertex(r*cos(i),r*sin(i),0);
    }

    // triangles
    for(int i=0;i<ndisk-1;++i) {
        for (int j=1; j<nbVertices+1; ++j)
            this->addTriangle(1+j%nbVertices+i*(nbVertices+1),
                              j+i*(nbVertices+1),
                              j+1+nbVertices+i*(nbVertices+1));
        for (int j=1; j<nbVertices+1; ++j)
            this->addTriangle(j%nbVertices+2+nbVertices+i*(nbVertices+1),
                              j%nbVertices+1+i*(nbVertices+1),
                              nbVertices+j+1+i*(nbVertices+1));
    }
    computeNormalsT();
    computeNormalsV();
}
