/*
 * Subsystem.h
 *
 *  Created on: Feb 20, 2012
 *      Author: cgibson
 */

#ifndef SUBSYSTEM_H_
#define SUBSYSTEM_H_

#include "Event.h"
#include <string>

class Entity;

class Component {
public:
	Component();
	virtual ~Component();

	virtual std::string getName() = 0;
	virtual void update() = 0;
	virtual void init() = 0;

	Component & setOwner(Entity*);
	Entity* getOwner();

protected:
	Entity *m_entity;

};

class MovableComponent : public Component {
public:
	MovableComponent();
	virtual ~MovableComponent();

	std::string getName() { return "movable_component"; }
	void update();
	void init();
	void hello(Event* e);
};

#endif /* SUBSYSTEM_H_ */
