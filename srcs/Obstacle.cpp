/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Obstacle.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 23:21:28 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/25 19:47:38 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Obstacle.hpp"


Point   Obstacle::Rand_dir()
{
    int sign1 = ((int)((rand() / (double)RAND_MAX) * 2)) * 2 - 1;
 //   int sign2 = ((int)((rand() / (double)RAND_MAX) * 2)) * 2 - 1;
    int value1 = sign1 * (int)((rand() / (double)RAND_MAX) * 4) ;
    int value2 = (int)((rand() / (double)RAND_MAX) * 4) + 1;

    return(Point(value1, value2));
}

Obstacle::Obstacle() : direction(Rand_dir()) {init(); }

Obstacle::Obstacle(Point c_direction, int speed)
    : direction(c_direction), max_speed(speed), speed(speed) {
    init();
}

Obstacle::Obstacle(Point c_direction)
    : direction(c_direction), max_speed(20), speed(20) {
    init();
}

Obstacle::~Obstacle() {}

Obstacle::Obstacle(Obstacle const &other) { *this = other; }

Obstacle &Obstacle::operator=(Obstacle const &rhs) {
    direction = rhs.direction;
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
    Obstacle *res = new Obstacle(Point(direction.x + e->direction.x, direction.y + e->direction.y));
    delete this;
    delete e;
    return res;
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
