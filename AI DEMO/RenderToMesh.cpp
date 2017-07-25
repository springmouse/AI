#include "RenderToMesh.h"



RenderToMesh * RenderToMesh::GetInstanceOfRenderToMesh()
{
    static RenderToMesh render;
    return &render;
}

void RenderToMesh::Draw(aie::Renderer2D * m_2dRenderer, aie::Font * font)
{
    NAVMANAGER->Draw(m_2dRenderer);
}


RenderToMesh::RenderToMesh()
{
}


RenderToMesh::~RenderToMesh()
{

}
