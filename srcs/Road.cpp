#include "Road.hpp"

Road::Road() : direction(1, 0), max_speed(20), speed(20) { }

Road::~Road() {}

Road::Road(Point c_direction, int speed) : direction(c_direction), max_speed(speed), speed(speed) {
    direction = c_direction;
}

Road::Road(Road const &a) { *this = a; }

Road &Road::operator=(Road const &a) {
    direction = a.direction;
    return *this;
}

// getters

BluePrint const &Road::get_blueprint() const { return blueprint; }

Point Road::get_direction() const { return direction; }

Point Road::get_move() const {
    speed--;
    if (speed == 0){
        speed = max_speed;
        return direction;
    } else {
        return Point(0, 0);
    }
}

EntityType Road::get_type() const { return type; }

// setters

void Road::set_direction(Point dir) { direction = dir; }

// collision

IGameEntity *Road::collide(IGameEntity *e) { return e->get_collided(this); }

IGameEntity *Road::get_collided(Obstacle *e) {
    delete e;
    return this;
}

IGameEntity *Road::get_collided(Enemy *e) {
    delete e;
    return this;
}

IGameEntity *Road::get_collided(Projectile *e) {
    delete e;
    return this;
}

IGameEntity *Road::get_collided(Road *e) {
    delete e;
    return this;
}

IGameEntity *Road::get_collided(Player *e) {
    delete e;
    return this;
}

/* PRIVATE */

// static
BluePrint const Road::blueprint = BluePrint(new std::string("###"), 1, colour);
EntityType const Road::type = road;
int const Road::colour = ROAD_PAIR;
