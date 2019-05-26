/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 11:45:26 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/26 17:49:58 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Projectile.hpp"

Projectile::Projectile() : direction(0, 0) {
    owner = NULL;
}

Projectile::~Projectile() {}

Projectile::Projectile(IGameEntity *owner, Point direction)
    : direction(direction), owner(owner) {}

Projectile::Projectile(Projectile const &a) { *this = a; }

Projectile &Projectile::operator=(Projectile const &a) {
    direction = a.direction;
    return *this;
}

// methods

// getters

BluePrint const &Projectile::get_blueprint() const { return blueprint; }

Point Projectile::get_direction() const { return direction; }

Point Projectile::get_move() const { return direction; }

EntityType Projectile::get_type() const { return type; }

// setters

void Projectile::set_direction(Point dir) { direction = dir; }

// collision

IGameEntity *Projectile::collide(IGameEntity *e) {
    return e->get_collided(this);
}

IGameEntity *Projectile::get_collided(Obstacle *e) {
    if (dynamic_cast<Player *>(owner)) {
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
    return e->get_collided(this);
}

IGameEntity *Projectile::get_collided(Road *e) {
    delete this;
    return (IGameEntity *)e;
}

/* PRIVATE */

// static
BluePrint const Projectile::blueprint = BluePrint(new std::string(" ' "), 1);
EntityType const Projectile::type = projectile;
