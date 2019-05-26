/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 16:05:38 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/26 19:06:51 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player() : direction(0, 0), lives(NULL) { init(); }

Player::Player(Point c_direction, unsigned int *lives)
    : direction(c_direction), lives(lives) {
    init();
}

Player::~Player() { (*lives) = *lives - 1; }

Player::Player(Player const &a) { *this = a; }

Player &Player::operator=(Player const &a) {
    direction = a.direction;
    return *this;
}

// methods

void Player::add_score(int value) { score += value; }

// getters

BluePrint const &Player::get_blueprint() const { return blueprint; }

Point Player::get_direction() const { return direction; }

bool Player::get_is_shooting() const { return is_shooting; }

Point Player::get_move() const {
    --speed;
    if (speed == 0) {
        speed = max_speed;
        Point tmp = direction;
//        direction = Point(0, 0);
        return tmp;
    }
    return Point(0, 0);
}

Point Player::get_shot() const { return shot; }

EntityType Player::get_type() const { return type; }

int Player::get_score() const { return score; }

// setters

void Player::set_direction(Point input) { direction = input; }

void Player::set_is_shooting(bool shooting) { is_shooting = shooting; }

// collision
IGameEntity *Player::collide(IGameEntity *e) { return e->get_collided(this); }

IGameEntity *Player::get_collided(Obstacle *e) {
    delete e;
    delete this;
    return NULL;
}

IGameEntity *Player::get_collided(Enemy *e) {
    delete e;
    delete this;
    return NULL;
}

IGameEntity *Player::get_collided(Projectile *e) {
    delete e;
    delete this;
    return NULL;
}

IGameEntity *Player::get_collided(Player *e) {
    delete e;
    delete this;
    return NULL;
}

IGameEntity *Player::get_collided(Road *e) {
    delete this;
    return (IGameEntity *)e;
}

/* PRIVATE */

void Player::init() {
    score = 0;
    is_shooting = false;
    shot = Point(0, -1);
    speed = 5;
    max_speed = 5;
}

// static

BluePrint const Player::blueprint = BluePrint(new std::string(")^("), 1);
EntityType const Player::type = player;
