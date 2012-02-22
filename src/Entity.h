/*
 * Entity.h
 *
 *  Created on: Feb 20, 2012
 *      Author: cgibson
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include <stdlib.h>
#include <vector>
#include <memory>
#include "Property.h"
#include "Component.h"
#include <unordered_map>
#include <string>

#define __VALIDATE_TYPE__

typedef std::unordered_map<std::string, std::shared_ptr<Property> > PropMap;
typedef std::unordered_map<std::string, std::shared_ptr<Component> > CompMap;

class Entity {
public:
	Entity();
	virtual ~Entity();

	//void update();
	//void invoke(std::string);

	//unsigned int &getID();
	//std::string  &getName();

	void initComponents();

	Entity & addComponent(Component *comp) {
		comp->setOwner(this);
		m_components[comp->getName()] = std::shared_ptr<Component>(comp);

		return *this;
	}

	void removeComponent(std::string name) {
		m_components.erase(name);
	}

	Entity & addProperty(Property *val) {
		m_properties[val->getName()] = std::shared_ptr<Property>(val);
		return *this;
	}

	template <typename T>
	Entity & addTypedProperty(std::string name, T val) {

		m_properties[name] = std::shared_ptr<Property>(new TypedProperty<T>(name, val));

		return *this;
	}

	//void removeProperty(std::string);

	template <class T = Property>
	std::shared_ptr<T> getProperty(std::string name) {
		std::shared_ptr<T> pPtr = std::dynamic_pointer_cast<T>(m_properties.at(name));

#ifdef __VALIDATE_TYPE__
		if (!pPtr) {
			printf("Error: property [%s] returned unexpected property type.\n", name.c_str());
			exit(1);
		}
#endif
		return pPtr;

	}

	template <typename T>
	T getTypedProperty(std::string name) {
		std::shared_ptr<TypedProperty<T> > pPtr = std::dynamic_pointer_cast<TypedProperty<T> >(m_properties.at(name));

#ifdef __VALIDATE_TYPE__
		if (!pPtr) {
			printf("Error: property [%s] returned unexpected type.\n", name.c_str());
			exit(1);
		}
#endif

		return pPtr->value;
	}



protected:

	unsigned int m_ID;
	static unsigned int nextID;
	std::string m_name;

	PropMap m_properties;
	CompMap m_components;
};

#endif /* ENTITY_H_ */
