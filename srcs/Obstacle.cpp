/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Obstacle.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 23:21:28 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/25 11:59:23 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Obstacle.hpp"


Point   Obstacle::Rand_dir()
{
    int sign1 = ((int)((rand() / (double)RAND_MAX) * 2)) * 2 - 1;
 //   int sign2 = ((int)((rand() / (double)RAND_MAX) * 2)) * 2 - 1;
    int value1 = sign1 * (int)((rand() / (double)RAND_MAX) * 4) ;
    int value2 = (int)((rand() / (double)RAND_MAX) * 4) + 1; 
 
    return(Point(value1, value2));
}

Obstacle::Obstacle() : direction(Rand_dir()) {init(); }

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
    Obstacle *res = new Obstacle(Point(direction.x + e->direction.x, direction.y + e->direction.y)); 
    delete this;
    delete e;
    return res;
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

void Obstacle::end_turn() { has_moved = false; }

/* PRIVATE */

void Obstacle::init() { has_moved = false; }

// static

BluePrint const Obstacle::blueprint = BluePrint(new std::string("(@)"), 1);
