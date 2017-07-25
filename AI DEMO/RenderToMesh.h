#pragma once
#include <Texture.h>
#include <Renderer2D.h>
#include "NavManager.h"


#define RENDER RenderToMesh::GetInstanceOfRenderToMesh()

class RenderToMesh
{
public:

    static RenderToMesh * GetInstanceOfRenderToMesh();

    void Draw(aie::Renderer2D * m_2dRenderer, aie::Font* font);

private:

    RenderToMesh();
    ~RenderToMesh();

};

