#pragma once
#include <Renderer2D.h>
#include <Input.h>
#include <list>
#include <Vector2.h>
#include "Information.h"
#include "GetAStarPath.h"
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

    void SetUpStartUpNodeConections();

    void MakeConnectionsToNode(NavMeshNode * nodeA);

    void CreatNewNode();

    void DestroyNode();

    void Draw(aie::Renderer2D * m_2dRenderer);

	void ClearParents();

    void Slect();

    void Nothing();

    std::list<NavMeshNode *> GetEdgeConnections(NavMeshNode * node);

    NavMeshNode * GetNode(Vector2 pos);

    void SwapDrawToNode();
    ////////////////////////////////////////////////

    std::list<MapNode *> g_mapNodes;
    std::list<NavMeshNode *> g_NavNodes;


private:

    NavManager();

    ~NavManager();

    Vector2 start, finish;

    float m_timer, m_pathTimer;

	std::list<NavMeshNode *> nodeTest;

    aie::Texture * m_tileTexture[3];

    bool m_drawToNode;
};

