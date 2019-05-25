/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 16:05:38 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/25 16:33:40 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player() : direction(0, 0) { init(); }

Player::Player(Point c_direction) : direction(c_direction) { init(); }

Player::~Player() {}

Player::Player(Player const &a) { *this = a; }

Player &Player::operator=(Player const &a) {
    direction = a.direction;
    return *this;
}

Point Player::get_move() {
    if (has_moved) {
        return Point(0, 0);
    } else {
        Point tmp(direction);
        direction = Point(0, 0);
        has_moved = true;
        return tmp;
    }
}

BluePrint const &Player::get_blueprint() const { return blueprint; }

IGameEntity *Player::collide(IGameEntity *e) { return e->get_collided(this); }

IGameEntity *Player::get_collided(Obstacle *e) {
    delete this;
    delete e;
    return NULL;
}

IGameEntity *Player::get_collided(Enemy *e) {
    delete e;
    return this;
}

IGameEntity *Player::get_collided(Projectile *e) {
    delete e;
    delete this;
    return NULL;
}

IGameEntity *Player::get_collided(Player* e){
    delete e;
    return NULL;
}

void Player::set_direction(Point input) { direction = input; }

void Player::end_turn() { has_moved = false; }

/* PRIVATE */

void Player::init() { has_moved = false; }

// static

BluePrint const Player::blueprint = BluePrint(new std::string(")^("), 1);
