#ifndef ANIMALS_H
#define ANIMALS_H

#include <vector>
#include <string>
#include "park.h"
// #include "positions.h"


using namespace std;


class Mouse : public Animal {
friend class Scene;
public:
	Mouse(string s, Position coords);
	virtual bool Chase();
};

class Cat : public Animal {
friend class Scene;
public:
	Cat(string s, Position coords);
	virtual bool Chase();

};

class Person : public Animal {
friend class Scene;
public:
	Person(string s, Position coords);
	virtual bool Chase();

};
#endif