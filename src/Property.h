/*
 * Component.h
 *
 *  Created on: Feb 20, 2012
 *      Author: cgibson
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <string>

class Property {
public:
	Property(std::string name);
	virtual ~Property();

	std::string getName();

protected:
	std::string m_name;
};

template <typename T>
class TypedProperty : public Property {
public:
	TypedProperty(std::string name, T val):Property(name), value(val){}
	T value;
};

class TransformProperty : public Property {
public:
	TransformProperty(std::string name, float X, float Y):Property(name), x(X), y(Y){}
	float x, y;
};

#endif /* COMPONENT_H_ */
