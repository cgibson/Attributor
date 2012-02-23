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
#include <unordered_map>
#include <string>
#include <boost/signals2.hpp>

#include "Property.h"
#include "Component.h"
#include "Event.h"

using namespace boost::signals2;

#define __VALIDATE_TYPE__

typedef boost::signals2::signal<void (Event*)> SigType;

typedef std::shared_ptr<Property> PropPtr;
typedef std::shared_ptr<Component> CompPtr;
typedef std::shared_ptr<SigType> SigPtr;

typedef std::unordered_map<std::string, PropPtr> PropMap;
typedef std::unordered_map<std::string, CompPtr> CompMap;
typedef std::unordered_map<std::string, SigPtr> SigMap;

class Entity {
public:
	Entity();
	virtual ~Entity();

	//void update();
	//void invoke(std::string);

	//unsigned int &getID();
	//std::string  &getName();

	template <typename EventType>
	Entity & attachEvent( boost::function<void (Event*)> fPtr ) {

		std::string eventName = EventType::getName();
		SigMap::iterator it = m_signals.find(eventName);

		SigPtr sigPtr;
		if (it == m_signals.end()) {
			sigPtr = SigPtr(new SigType());
			m_signals[eventName] = sigPtr;
		} else {
			sigPtr = it->second;
		}

		printf("CONNECTING SIGNAL TO EVENT [%s]!\n", eventName.c_str());
		sigPtr->connect( fPtr );

		return *this;
	}

	template <typename EventType>
	void notify(Event *event) {
		std::string eventName = EventType::getName();
		SigMap::iterator it = m_signals.find(eventName);

		if (it == m_signals.end()) {
			printf("WARNING: no such event [%s]\n", eventName.c_str());
			return;
		}

		printf("RUNNING SIGNALS FOR EVENT [%s]\n", eventName.c_str());

		(*(it->second))(event);
	}

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
	SigMap m_signals;
};

#endif /* ENTITY_H_ */
