#pragma once
#include <functional>
#include <memory>


class NavMeshNode;
class MapNode;
class Entity;

typedef std::shared_ptr<MapNode>        SharedMapNodePtr;
typedef std::shared_ptr<NavMeshNode>     SharedMeshPtr;
typedef std::shared_ptr<Entity>         SharedEntityPtr;

#define myFUNC_0(ret_)                      std::function<##ret_()>
#define myBIND_0(func_, objectAddr_)        std::bind(&##func_,##objectAddr_)

#define myFUNC_1(ret_, arg_)                std::function<##ret_(##arg_)>
#define myBIND_1(func_, objectAddr_)        std::bind(&##func_, ##objectAddr_, std::placeholders::_1)

#define myFUNC_2(ret_, arg1_, arg2_)        std::function<##ret_(##arg1_, ##arg2_)>
#define myBIND_2(func_, objectAddr_)        std::bind(&##func_, ##objectAddr_, std::placeholders::_1, std::placeholders::_2)