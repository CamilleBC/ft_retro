/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 09:59:28 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/25 10:40:17 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy() : direction(0, 0) { has_moved = false; }

Enemy::~Enemy() {}

Enemy::Enemy(Point c_direction) : direction(c_direction) {
    direction = c_direction;
}

Enemy::Enemy(Enemy const &a) { *this = a; }

Enemy &Enemy::operator=(Enemy const &a) {
    direction = a.direction;
    return *this;
}

Point Enemy::get_move() {
    if (has_moved) {
        return Point(0, 0);
    } else {
        has_moved = true;
        return direction;
    }
}

std::string Enemy::get_texture() const { return "|o|"; }

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

void Enemy::end_turn() { has_moved = false; }
