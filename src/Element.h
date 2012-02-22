
#ifndef ELEMENT_H_
#define ELEMENT_H_

#include <string>

class Entity;

template <class T>
class Element {
public:
	Element(std::string);
	Element(std::string, T);
	virtual ~Element();

	void setOwner(Entity*);
	Entity *getOwner();

	std::string getName();

	void setValue(T);
	T getValue();

protected:
	T m_value;

	std::string m_name;
	Entity *m_entity;
};

#endif
