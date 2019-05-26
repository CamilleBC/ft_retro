/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 09:59:28 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/26 21:54:21 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy() : direction(1, 0) { init(); }

Enemy::~Enemy() {}

Enemy::Enemy(Point c_direction, int speed)
    : direction(c_direction), max_speed(speed), speed(speed) {
    init();
}

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
    reload--;
    if (reload == 0)
        reload = max_reload;
    if (speed == 0) {
        speed = max_speed;
        return direction;
    } else {
        return Point(0, 0);
    }
}

EntityType Enemy::get_type() const { return type; }

bool Enemy::get_is_shooting() const { return reload == 1; }

Point Enemy::get_shot() const { return Point(0, 1); }

int Enemy::get_reward() const { return reward; }

// setters

void Enemy::set_direction(Point dir) { direction = dir; }

void Enemy::set_is_shooting(bool shooting) { (void)shooting; }

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
    e->add_score(reward);
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
    max_reload = 200;
    reload = max_reload;
}

// static

BluePrint const Enemy::blueprint = BluePrint(new std::string("|o|"), 1, colour);
EntityType const Enemy::type = enemy;
int const Enemy::reward = 100;
int const Enemy::colour = ENEMY_PAIR;
