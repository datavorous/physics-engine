#pragma once
#include "raylib.h"

enum BodyType {
    RIGID_BODY,
    STATIC_BODY
};

class Entity {
public:
    float mass;
    float restitution = 0.7;
    int radius;
    short shapeId;
    Vector2 position;
    Vector2 velocity;
    Vector2 forceApplied;
    BodyType bType;
    Color c;

    float invMass() const {
        return (bType == STATIC_BODY || mass == 0.0f) ? 
                0.0f : 1.0f / mass;
        };

    Entity(float m, Vector2 pos, BodyType b, int r, Color cc):
          c(cc),
          mass(m),
          radius(r), 
          position(pos), 
          velocity({0, 0}), 
          forceApplied({0, 0}), 
          shapeId(0), 
          bType(b) {}
          
    void applyForce(const Vector2& force);
    void integrate(float dt);
};
