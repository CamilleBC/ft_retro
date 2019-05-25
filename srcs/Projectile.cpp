/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 11:45:26 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/25 19:08:19 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Projectile.hpp"

Projectile::Projectile() : direction(0, 0) { has_moved = false; }

Projectile::~Projectile() {}

Projectile::Projectile(Point c_direction) : direction(c_direction) {
    direction = c_direction;
}

Projectile::Projectile(Projectile const &a) { *this = a; }

Projectile &Projectile::operator=(Projectile const &a) {
    direction = a.direction;
    return *this;
}

Point Projectile::get_move() {
    if (has_moved) {
        return Point(0, 0);
    } else {
        has_moved = true;
        return direction;
    }
}

BluePrint const &Projectile::get_blueprint() const { return blueprint; }

Point Projectile::get_shoot() { return Point(0, 0); }

void Projectile::set_shoot(Point dir) { shoot = dir; }


IGameEntity *Projectile::collide(IGameEntity *e) {
    return e->get_collided(this);
}

IGameEntity *Projectile::get_collided(Obstacle *e) {
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

void Projectile::end_turn() {
    has_moved = false;
    shoot = Point(0, 0);
}

BluePrint const Projectile::blueprint = BluePrint(new std::string(" ' "), 1);
