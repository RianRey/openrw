#pragma once
#ifndef _PICKUPOBJECT_HPP_
#define _PICKUPOBJECT_HPP_
#include <engine/GameObject.hpp>
#include <bullet/btBulletCollisionCommon.h>
#include <BulletCollision/CollisionDispatch/btGhostObject.h>
#include <glm/glm.hpp>

class CharacterObject;

/**
 * @brief The PickupObject class
 * Implements interface and base behaviour for pickups
 */
class PickupObject : public GameObject
{
	btPairCachingGhostObject* _ghost;
	btSphereShape* _shape;
	bool _enabled;
	float _enableTimer;
	int _modelID;
public:

	PickupObject(GameWorld* world, const glm::vec3& position, int modelID);

	~PickupObject();

	int getModelID() const { return _modelID; }

	Type type() { return Pickup; }

	void tick(float dt);

	virtual bool onCharacterTouch(CharacterObject* character) = 0;

	bool isEnabled() const { return _enabled; }
	void setEnabled(bool enabled);
};

#endif