/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 16:05:38 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/26 09:54:37 by cbaillat         ###   ########.fr       */
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

// methods

void Player::end_turn() { has_moved = false; }

// getters

BluePrint const &Player::get_blueprint() const { return blueprint; }

Point Player::get_direction() const { return direction; }

bool Player::get_is_shooting() const { return is_shooting; }

Point Player::get_move() const {
    if (has_moved) {
        return Point(0, 0);
    } else {
        Point tmp(direction);
        direction = Point(0, 0);
        has_moved = true;
        return tmp;
    }
}

Point Player::get_shot() const { return shot; }

EntityType Player::get_type() const { return type; }

// setters

void Player::set_direction(Point input) { direction = input; }

void Player::set_is_shooting(bool shooting) { is_shooting = shooting; }

// collision
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

IGameEntity *Player::get_collided(Player *e) {
    delete e;
    return NULL;
}

/* PRIVATE */

void Player::init() {
    is_shooting = false;
    has_moved = false;
    shot = Point(0, -1);
}

// static

BluePrint const Player::blueprint = BluePrint(new std::string(")^("), 1);
EntityType const Player::type = player;
