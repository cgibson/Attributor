/*
 * Subsystem.cpp
 *
 *  Created on: Feb 20, 2012
 *      Author: cgibson
 */

#include "Component.h"
#include "Entity.h"

Component::Component() {
	// TODO Auto-generated constructor stub

}

Component::~Component() {
	// TODO Auto-generated destructor stub
}

Component &
Component::setOwner(Entity *entity) {
	m_entity = entity;
	return *this;
}

Entity *
Component::getOwner() {
	return m_entity;
}

MovableComponent::MovableComponent() {

}

MovableComponent::~MovableComponent() {

}

void
MovableComponent::update() {

}

void
MovableComponent::init() {
	(*m_entity)
		.addTypedProperty("health", 100)
		.addProperty(new TransformProperty("location", 50, 75));
}
