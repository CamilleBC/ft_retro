/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Obstacle.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 23:21:28 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/25 16:30:29 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Obstacle.hpp"

Obstacle::Obstacle() : direction(0, 0) { init(); }

Obstacle::Obstacle(Point c_direction) : direction(c_direction) { init(); }

Obstacle::~Obstacle() {}

Obstacle::Obstacle(Obstacle const &a) { *this = a; }

Obstacle &Obstacle::operator=(Obstacle const &a) {
    direction = a.direction;
    return *this;
}

Point Obstacle::get_move() {
    if (has_moved) {
        return Point(0, 0);
    } else {
        has_moved = true;
        return direction;
    }
}

BluePrint const &Obstacle::get_blueprint() const { return blueprint; }

IGameEntity *Obstacle::collide(IGameEntity *e) { return e->get_collided(this); }

IGameEntity *Obstacle::get_collided(Obstacle *e) {
    delete this;
    delete e;
    return new Obstacle(
        Point(direction.x + e->direction.x, direction.y + e->direction.y));
}

IGameEntity *Obstacle::get_collided(Enemy *e) {
    delete e;
    return this;
}

IGameEntity *Obstacle::get_collided(Projectile *e) {
    delete e;
    delete this;
    return NULL;
}

IGameEntity *Obstacle::get_collided(Player* e){
    delete e;
    return NULL;
}

void Obstacle::end_turn() { has_moved = false; }

/* PRIVATE */

void Obstacle::init() { has_moved = false; }

// static

BluePrint const Obstacle::blueprint = BluePrint(new std::string("(@)"), 1);
