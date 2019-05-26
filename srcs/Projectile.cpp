/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 11:45:26 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/26 19:04:40 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Projectile.hpp"

Projectile::Projectile() : direction(0, 0), score(NULL) {}

Projectile::~Projectile() {}

Projectile::Projectile(Point direction, int *score)
    : direction(direction), score(score) {}

Projectile::Projectile(Projectile const &a) { *this = a; }

Projectile &Projectile::operator=(Projectile const &a) {
    direction = a.direction;
    return *this;
}
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
    if (score) {
        (*score) += e->get_reward();
    }
    delete e;
    delete this;
    return NULL;
}

IGameEntity *Projectile::get_collided(Enemy *e) {
    if (score) {
        (*score) += e->get_reward();
    }
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
