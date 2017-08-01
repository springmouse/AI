#pragma once
#include <list>
#include <functional>

class Entity;

class PlayerUnitDecsisionTree
{

public:

    PlayerUnitDecsisionTree(Entity * unit);
    ~PlayerUnitDecsisionTree();

    Entity * myUnit;

    class Node
    {

    public:
        Node() {};
        ~Node() {};

        std::function<bool()> run;

        Node * yes;
        Node * no;

        std::string comment;
    };

    void Update();

    void CreatNodes();

    std::list<Node *> nodes;
    
    Node * start;

};