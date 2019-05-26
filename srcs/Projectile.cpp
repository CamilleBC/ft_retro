/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 11:45:26 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/26 11:20:56 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Projectile.hpp"

Projectile::Projectile() : direction(0, 0) {
    owner = NULL;
    has_moved = false;
}

Projectile::~Projectile() {}

Projectile::Projectile(IGameEntity *owner, Point direction) : direction(direction), owner(owner) {}

Projectile::Projectile(Projectile const &a) { *this = a; }

Projectile &Projectile::operator=(Projectile const &a) {
    direction = a.direction;
    return *this;
}

// methods

void Projectile::end_turn() { has_moved = false; }

// getters

BluePrint const &Projectile::get_blueprint() const { return blueprint; }

Point Projectile::get_direction() const { return direction; }

Point Projectile::get_move() const {
    if (has_moved) {
        return Point(0, 0);
    } else {
        has_moved = true;
        return direction;
    }
}

// setters

void Projectile::set_direction(Point dir) { direction = dir; }

// collision

IGameEntity *Projectile::collide(IGameEntity *e) {
    return e->get_collided(this);
}

IGameEntity *Projectile::get_collided(Obstacle *e) {
    if (dynamic_cast<Player *>(owner)){
        dynamic_cast<Player *>(owner)->add_score(100);
    }
    delete this;
    delete e;
    return NULL;
}

IGameEntity *Projectile::get_collided(Enemy *e) {
    delete this;
    delete e;
    return NULL;
}

IGameEntity *Projectile::get_collided(Projectile *e) {
    delete this;
    delete e;
    return NULL;
}

IGameEntity *Projectile::get_collided(Player *e) {
    delete e;
    return NULL;
}

/* PRIVATE */

// static
BluePrint const Projectile::blueprint = BluePrint(new std::string(" ' "), 1);
