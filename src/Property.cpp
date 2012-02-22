/*
 * Component.cpp
 *
 *  Created on: Feb 20, 2012
 *      Author: cgibson
 */

#include "Property.h"

Property::Property(std::string name): m_name(name) {
	// TODO Auto-generated constructor stub

}

Property::~Property() {
	// TODO Auto-generated destructor stub
}

std::string
Property::getName() {
	return m_name;
}

