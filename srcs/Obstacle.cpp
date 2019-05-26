/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Obstacle.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 23:21:28 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/26 18:55:05 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Obstacle.hpp"

Obstacle::Obstacle() : direction(get_rand_dir()) { init(); }

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

// methods

void Obstacle::end_turn() { has_moved = false; }

// getters

BluePrint const &Obstacle::get_blueprint() const { return blueprint; }

Point Obstacle::get_direction() const { return direction; }

Point Obstacle::get_move() const {
    speed--;
    if (has_moved || speed) {
        return Point(0, 0);
    } else {
        speed = max_speed;
        has_moved = true;
        return direction;
    }
}

Point Obstacle::get_rand_dir() const {
    int sign1 = ((int)((rand() / (double)RAND_MAX) * 2)) * 2 - 1;
    //   int sign2 = ((int)((rand() / (double)RAND_MAX) * 2)) * 2 - 1;
    int value1 = sign1 * (int)((rand() / (double)RAND_MAX) * 4);
    int value2 = (int)((rand() / (double)RAND_MAX) * 4) + 1;

    return (Point(value1, value2));
}

int Obstacle::get_reward() const { return reward; }

EntityType Obstacle::get_type() const { return type; }

// setters

void Obstacle::set_direction(Point dir) { direction = dir; }

// collision

IGameEntity *Obstacle::collide(IGameEntity *e) { return e->get_collided(this); }

IGameEntity *Obstacle::get_collided(Obstacle *e) {
    Obstacle *res = new Obstacle(
        Point(direction.x, direction.y), speed + 1);
    delete this;
    delete e;
    return res;
}

IGameEntity *Obstacle::get_collided(Enemy *e) {
    delete e;
    return this;
}

IGameEntity *Obstacle::get_collided(Projectile *e) {
    e->add_score(reward);
    delete e;
    delete this;
    return NULL;
}

IGameEntity *Obstacle::get_collided(Player *e) {
    delete e;
    delete this;
    return NULL;
}

IGameEntity *Obstacle::get_collided(Road *e) {
    delete this;
    return (IGameEntity *)e;
}


/* PRIVATE */

void Obstacle::init() {
    has_moved = false;
    shoot = Point(0, 0);
}

// static

BluePrint const Obstacle::blueprint = BluePrint(new std::string("(@)"), 1);
EntityType const Obstacle::type = obstacle;
int const Obstacle::reward = 20;
