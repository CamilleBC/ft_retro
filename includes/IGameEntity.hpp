/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGameEntity.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 22:52:17 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/27 08:44:17 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IGAMEENTITY_HPP
#define IGAMEENTITY_HPP

#include "BluePrint.hpp"
#include "Point.hpp"
#include <string>

class Obstacle;
class Projectile;
class Enemy;
class Player;
class Road;

enum EntityType
{
	enemy,
	obstacle,
	player,
	projectile,
    road
};

class IGameEntity {
  public:
    virtual ~IGameEntity() {}

    // getters
    virtual BluePrint const &get_blueprint() const = 0;
    virtual Point get_direction() const = 0;
    virtual Point get_move() const = 0;
    virtual EntityType get_type() const = 0;
    // setter
    virtual void set_direction(Point) = 0;
    // collision
    virtual IGameEntity *collide(IGameEntity *) = 0;
    virtual IGameEntity *get_collided(Obstacle *) = 0;
    virtual IGameEntity *get_collided(Enemy *) = 0;
    virtual IGameEntity *get_collided(Projectile *) = 0;
    virtual IGameEntity *get_collided(Player *) = 0;
    virtual IGameEntity *get_collided(Road *) = 0;
};

#endif /* IGAMEENTITY_HPP */
