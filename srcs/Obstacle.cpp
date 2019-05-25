/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Obstacle.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 23:21:28 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/25 19:07:44 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Obstacle.hpp"

Obstacle::Obstacle() : direction(0, 0) { init(); }

Obstacle::Obstacle(Point c_direction, int speed)
    : direction(c_direction), max_speed(speed), speed(speed) {
    init();
}

Obstacle::Obstacle(Point c_direction)
    : direction(c_direction), max_speed(20), speed(20) {
    init();
}

Obstacle::~Obstacle() {}

Obstacle::Obstacle(Obstacle const &a) { *this = a; }

Obstacle &Obstacle::operator=(Obstacle const &a) {
    direction = a.direction;
    return *this;
}

Point Obstacle::get_move() {
    speed--;
    if (has_moved || speed) {
        return Point(0, 0);
    } else {
        speed = max_speed;
        has_moved = true;
        return direction;
    }
}

Point Obstacle::get_shoot() { return Point(0, 0); }

void Obstacle::set_shoot(Point dir) { shoot = dir; }


BluePrint const &Obstacle::get_blueprint() const { return blueprint; }

IGameEntity *Obstacle::collide(IGameEntity *e) { return e->get_collided(this); }

IGameEntity *Obstacle::get_collided(Obstacle *e) {
    Point tmp = Point(direction.x + e->direction.x, direction.y + e->direction.y);
    delete this;
    delete e;
    return new Obstacle(tmp);
}

IGameEntity *Obstacle::get_collided(Enemy *e) {
    delete e;
    return this;
}

IGameEntity *Obstacle::get_collided(Projectile *e) {
    delete e;
    delete this;
    return NULL;
}

IGameEntity *Obstacle::get_collided(Player *e) {
    delete e;
    return NULL;
}

void Obstacle::end_turn() { has_moved = false; }

/* PRIVATE */

void Obstacle::init() {
    has_moved = false;
    shoot = Point(0, 0);
}

// static

BluePrint const Obstacle::blueprint = BluePrint(new std::string("(@)"), 1);
