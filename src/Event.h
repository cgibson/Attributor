/*
 * Event.h
 *
 *  Created on: Feb 22, 2012
 *      Author: cgibson
 */

#ifndef EVENT_H_
#define EVENT_H_

#include <string>

class Event {
public:
	Event();
	virtual ~Event();

	static std::string getName() { return "no_event"; }
	virtual std::string getStr() = 0;
};

class RandomEvent : public Event {
public:
	static std::string getName() { return "random_event"; }
	std::string getStr() { return "trolololo"; }
};

#endif /* EVENT_H_ */
