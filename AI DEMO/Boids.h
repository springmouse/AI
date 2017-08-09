#pragma once
#include "Object.h"

class BoidsBlackBoard;

class Boids :
    public Object
{
public:
    Boids(BoidsBlackBoard * blackBoard, Vector2 center);
    ~Boids();

    bool operator== (Boids & other);
    bool operator!= (ShareBoidPtr & other);

    void Update(float deltaTime);

    void CalculateSeperation();
    void CalculateAlignment();
    void CalculateCohesion();
    void CalculateSeek();
    void CalculateWonder();

    void SetLeader(bool seter);

    Vector2 GetVelocity();

    void Draw(aie::Renderer2D * rendere);

private:

    Vector2 m_speration;
    Vector2 m_alignment;
    Vector2 m_cohesion;

    Vector2 m_velocity;
    float m_maxVelocity;
    float m_minVolocity;

    Vector2 m_acceleration;

    BoidsBlackBoard * m_blackBoard;

    float m_septerationRadius;
    float m_alignmentRadius;
    float m_cohesionRadius;

    float m_seperationWeight;
    float m_alignmentWeight;
    float m_cohesionWeight;

    float m_seekWeight;
    float m_wonderWeight;

    bool m_leader;
        
    Vector2 m_leaderTarget;
};

