#pragma once
#include <Renderer2D.h>
#include <Input.h>
#include <list>
#include <Vector2.h>
#include "Information.h"
#include "GetAStarPath.h"
#include "TypesAndDefines.h"
#include <Texture.h>

#include "MapNode.h"
#include "NavMeshNode.h"

#define NAVMANAGER NavManager::GetInstanceOfNavManager()

class NavManager
{
public:

    static NavManager * GetInstanceOfNavManager();

    void Update(float deltaTime);

    void CreatNavMesh();
    void CreatEdges();
    void GatherEdges();

    void SetUpStartUpNodeConections();

    void MakeConnectionsToNode(SharedMeshPtr nodeA);

    void CreatNewNode();

    void DestroyNode();

    void Draw(aie::Renderer2D * m_2dRenderer);

	void ClearParents();

    void Slect();

    void Nothing();

    std::list<SharedMeshPtr> GetEdgeConnections(SharedMeshPtr node);

    SharedMeshPtr GetNode(Vector2 pos);

    void SwapDrawToNode();
    ////////////////////////////////////////////////

    std::list<SharedMapNodePtr> g_mapNodes;
    std::list<SharedMeshPtr>    g_NavNodes;
    std::list<SharedEdge>         g_mapEdges;

private:

    NavManager();

    ~NavManager();

    Vector2 start, finish;

    float m_timer, m_pathTimer;

	std::list<NavMeshNode *> nodeTest;

    aie::Texture * m_tileTexture[3];

    bool m_drawToNode;
};

