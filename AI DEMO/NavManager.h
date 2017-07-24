#pragma once
#include <Renderer2D.h>
#include <Input.h>
#include <list>
#include <Vector2.h>
#include "Node.h"
#include "Information.h"
#include "GetAStarPath.h"



#define NAVMANAGER NavManager::GetInstanceOfNavManager()

class NavManager
{
public:

    static NavManager * GetInstanceOfNavManager();

    void Update(float deltaTime);

    void SetUpStartUpNodeConections();

    void CreatNewNode(Vector2 mousePos);

    void DestroyNode(Vector2 mousePos);

    void Draw(aie::Renderer2D * m_2dRenderer);

    std::list<Node *> GetEdgeConnections(Node * node);

    Node * GetNode(Vector2 pos);

    ////////////////////////////////////////////////

    std::list<Node *> g_nodes;

private:
    NavManager();

    ~NavManager();

    Vector2 start, finish;

    float m_timer, m_pathTimer;

    std::list<Vector2 *> test;
};

