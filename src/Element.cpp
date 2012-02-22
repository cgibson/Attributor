/*
 * Component.cpp
 *
 *  Created on: Feb 20, 2012
 *      Author: cgibson
 */

#include "Element.h"
#include "Entity.h"

template <typename T>
Element<T>::Element(std::string name) {
	m_name = name;

}

template <typename T>
Element<T>::Element(std::string name, T val) {
	m_name = name;
	m_value = val;

}

template <typename T>
Element<T>::~Element() {
	// TODO Auto-generated destructor stub
}

template <typename T>
void
Element<T>::setOwner(Entity* ent) {
	m_entity = ent;
}

template <typename T>
Entity *
Element<T>::getOwner() {
	return m_entity;
}

template <typename T>
std::string
Element<T>::getName() {
	return m_name;
}

template <typename T>
void
Element<T>::setValue(T val) {
	m_value = val;
}

template <typename T>
T Element<T>::getValue() {
	return m_value;
}
