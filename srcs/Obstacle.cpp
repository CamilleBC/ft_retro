/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Obstacle.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 23:21:28 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/25 10:40:10 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Obstacle.hpp"

Obstacle::Obstacle() : direction(0, 0) { has_moved = false; }

Obstacle::~Obstacle() {}

Obstacle::Obstacle(Point c_direction) : direction(c_direction) {
    direction = c_direction;
}

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

std::string Obstacle::get_texture() const { return "(@)"; }

IGameEntity *Obstacle::collide(IGameEntity *e) { return e->get_collided(this); }

IGameEntity *Obstacle::get_collided(Obstacle *e) {
    return new Obstacle(
        Point(direction.x + e->direction.x, direction.y + e->direction.y));
}

IGameEntity *Obstacle::get_collided(Enemy *e) {
    (void)e;
    return this;
}

void Obstacle::end_turn() { has_moved = false; }
