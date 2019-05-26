/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 09:59:28 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/26 18:23:31 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy() : direction(1, 0) { init(); }

Enemy::~Enemy() {}

Enemy::Enemy(Point c_direction, int speed) : direction(c_direction), max_speed(speed), speed(speed) { init(); }

Enemy::Enemy(Enemy const &a) { *this = a; }

Enemy &Enemy::operator=(Enemy const &a) {
    direction = a.direction;
    return *this;
}

// methods

// getters

BluePrint const &Enemy::get_blueprint() const { return blueprint; }

Point Enemy::get_direction() const { return direction; }

Point Enemy::get_move() const {
    speed--;
    if (speed == 0){
        speed = max_speed;
        return direction;
    } else {
        return Point(0, 0);
    }
}

EntityType Enemy::get_type() const { return type; }

// setters

void Enemy::set_direction(Point dir) { direction = dir; }

// collision

IGameEntity *Enemy::collide(IGameEntity *e) { return e->get_collided(this); }

IGameEntity *Enemy::get_collided(Enemy *e) {
    delete this;
    delete e;
    return NULL;
}

IGameEntity *Enemy::get_collided(Obstacle *e) {
    delete this;
    return (IGameEntity *)e;
}

IGameEntity *Enemy::get_collided(Projectile *e) {
    delete this;
    delete e;
    return NULL;
}

IGameEntity *Enemy::get_collided(Player *e) {
    delete e;
    return NULL;
}

IGameEntity *Enemy::get_collided(Road *e) {
    delete this;
    return (IGameEntity *)e;
}

/* PRIVATE */

void Enemy::init() {
    max_speed = 10;
    speed = max_speed;
}

// static

BluePrint const Enemy::blueprint = BluePrint(new std::string("|o|"), 1);
EntityType const Enemy::type = enemy;

