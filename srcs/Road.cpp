#include "Road.hpp"

Road::Road() : direction(1, 0) { has_moved = false; }

Road::~Road() {}

Road::Road(Point c_direction) : direction(c_direction) {
    direction = c_direction;
}

Road::Road(Road const &a) { *this = a; }

Road &Road::operator=(Road const &a) {
    direction = a.direction;
    return *this;
}

// methods

void Road::end_turn() {
    has_moved = false;
}

// getters

BluePrint const &Road::get_blueprint() const { return blueprint; }

Point Road::get_direction() const { return direction; }

Point Road::get_move() const {
    if (has_moved) {
        return Point(0, 0);
    } else {
        has_moved = true;
        return direction;
    }
}

EntityType Road::get_type() const { return type; }

// setters

void Road::set_direction(Point dir) { direction = dir; }

// collision

IGameEntity *Road::collide(IGameEntity *e) {
    return e->get_collided(this);
}

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
BluePrint const Road::blueprint = BluePrint(new std::string("###"), 1);
EntityType const Road::type = road;
