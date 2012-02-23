#include <stdio.h>
#include <memory>
#include "Entity.h"
#include "Event.h"

struct vec2 {
	float x, y;
};

int main(int argc, char *argv[]) {

	printf("Hello, World.\n");

	Entity *entity = new Entity();
	printf("Setting property test to 5\n");
	entity->addTypedProperty("test", 5 );
	printf("Setting property test2 to (2.0, 3.5)\n");
	entity->addTypedProperty("test2", vec2{2.0, 3.5} );
	printf("Setting property location to (55.0, 42.0) <-- transformProperty\n");
	entity->addProperty( new TransformProperty("location", 55.0, 42.0) );

	int val = entity->getTypedProperty<int>("test");
	vec2 val2 = entity->getTypedProperty<vec2>("test2");
	TransformProperty trans = *entity->getProperty<TransformProperty>("location");

	delete entity;

	printf("Value is %d\n", val);
	printf("Value is (%.1f, %.1f)\n", val2.x, val2.y);
	printf("Value is (%.1f, %.1f)\n", trans.x, trans.y);

	entity = new Entity();
	entity->addComponent(new MovableComponent());
	entity->initComponents();
	entity->notify<RandomEvent>(new RandomEvent());

	int health = entity->getTypedProperty<int>("health");
	TransformProperty xform = *entity->getProperty<TransformProperty>("location");

	printf("Entity has health of %d\n", health);
	printf("Entity has location (%.1f, %.1f)\n", xform.x, xform.y);

	return 0;
}
