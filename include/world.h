#pragma once
#include "raylib.h"
#include "entity.h"
#include <vector>
//#include "spring.h"

class World {
public:
	Vector2 gravity;
	std::vector<Entity> entities;
	const float percent = 0.5f;  // smol = less aggresive
	const float slop = 0.0001f;	// pene allocation
	//std::vector<Spring> springs;

	World(Vector2 g) : gravity(g) {}

	void addEntity(const Entity& e);
	void update(float dt);
	void draw();
	bool checkCollision(Entity& A, Entity& B,
        Vector2& outNormal, float& outPenetration);
    void positionalCorrection(Entity& A, Entity& B, 
        Vector2& outNormal, float& outPenetration);
    void resolveCollision(Entity& A, Entity& B, Vector2& normal, float& penetration, float dt);
    void resolveImpulse(Entity& A, Entity& B, Vector2& normal);
    void handleFriction(Entity& A, Entity& B, Vector2& normal, float impulse);

    //void addSpring(Entity* a, Entity* b, float restLen, float stiffness, float damping);
    //void updateSprings();
};
