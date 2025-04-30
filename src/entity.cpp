#include "entity.h"
#include "raylib.h"
#include "math.h"

void Entity::applyForce(const Vector2& force) {
    if (bType==STATIC_BODY) return;

    forceApplied.x += force.x;
    forceApplied.y += force.y;
}
/*
void Entity::applyForceAt(const Vector2& force, const Vector2& point){
    if (bType == STATIC_BODY) return;

    // linear force applied
    applyForce(force);

    TODO: fix rotation

    // torque calculation 
    // t = r x F, cross product of these two vectors 
    Vector2 r = { point.x - position.x, point.y - position.y};

    float crossProduct = r.x * force.y - r.y * force.x; 
    torque += crossProduct;

}
*/
void Entity::integrate(float dt) {
    if (bType==STATIC_BODY) return;

    // linear motion is dealt with here
    Vector2 acceleration = {forceApplied.x / mass,
                forceApplied.y / mass};

    // it's called semi implicit euler

    velocity.x += acceleration.x * dt;
    velocity.y += acceleration.y * dt;
    position.x += velocity.x * dt;
    position.y += velocity.y * dt;

    forceApplied = {0,0}; // flushing out the force which was accumulated in this iteration
    /* TODO: fix someday

    // angular motion dealing with here

    float angularAcceleration = torque / momentOfInertia;
    angularVelocity += angularAcceleration * dt;
    angle += angularVelocity * dt;

    torque to be flushed;
    */
}
/*
Vector2* Entity::getTransformedVertices() const {
    if (shape != RECTANGLE) return nullptr;
    static Vector2 vertices[4];

    float hw = size.x / 2.0f;
    float hh = size.y / 2.0f;

    Vector2 localVertices[4] = {
        {-hw, -hh},
        {hw, -hh},
        {hw, hh},
        {-hw, hh}
    };

    float cosA = cosA(angle);
    float sinA = sinA(angle);

    for (int i = 0; i < 4; i++){
        // rotating vertices         
        vertices[i].x = localVertices[i].x * cosA - localVertices[i].y * sinA;
        vertices[i].y = localVertices[i].x * sinA + localVertices[i].y * cosA;
        // transforming vertices to comply with the angular displacment
        vertices[i].x += position.x;
        vertices[i].y += position.y;
    }

    return vertices;
}*/