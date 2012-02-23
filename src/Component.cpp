/*
 * Subsystem.cpp
 *
 *  Created on: Feb 20, 2012
 *      Author: cgibson
 */

#define REGISTER_EVENT(EventType, function) \
	m_entity->attachEvent<EventType>( std::bind1st( std::mem_fun(function), this) );

#include "Component.h"
#include "Entity.h"
#include <functional>

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

	REGISTER_EVENT(RandomEvent, &MovableComponent::hello);
}

void
MovableComponent::hello(Event *e) {
	printf("Event sends message: %s\n", e->getStr().c_str());
}
