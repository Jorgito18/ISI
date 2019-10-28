#include "cilinder.h"

Cilinder::Cilinder(int nbVertices, int ndisk)
{
    _name="Cilinder";

    //vertices
    for (int i=0;i<ndisk;++i) {
        float z = 1-i*2/(float(ndisk)-1);
        this->addVertex(0,0,z);
        for (float i=0; i<2*M_PI ; i+=(2/(float)nbVertices)*M_PI)
            this->addVertex(cos(i),sin(i),z);
    }

    //top disk
    for (int j=1; j<nbVertices+1; ++j)
        this->addTriangle(0,j,j%nbVertices+1);
    //bottom disk
    for (int j=0; j<nbVertices; ++j)
        this->addTriangle(j+(ndisk-1)*nbVertices+ndisk,
                          (ndisk-1)*(nbVertices+1),
                          (j+1)%nbVertices+ndisk+(ndisk-1)*nbVertices);


    //side triangles
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
