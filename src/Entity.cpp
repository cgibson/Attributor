/*
 * Entity.cpp
 *
 *  Created on: Feb 20, 2012
 *      Author: cgibson
 */

#include "Entity.h"

Entity::Entity() {
	// TODO Auto-generated constructor stub

}

Entity::~Entity() {
	// TODO Auto-generated destructor stub
}

void
Entity::initComponents() {
	CompMap::iterator b = m_components.begin();
	CompMap::iterator e = m_components.end();

	for(; b != e; b++) {
		printf("INITIALIZING [%s]\n", b->first.c_str());
		b->second->init();
	}
}
