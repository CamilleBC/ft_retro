/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 11:44:43 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/26 21:52:07 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "Constants.hpp"
#include "Enemy.hpp"
#include "IGameEntity.hpp"
#include "Obstacle.hpp"
#include "Player.hpp"
#include "Point.hpp"
#include "Road.hpp"
#include <iostream>

class Projectile : public IGameEntity {
  private:
    static const int colour;
    static const BluePrint blueprint;
    static const EntityType type;
    Point direction;
    int *score;
    Projectile();

  public:
    Projectile(Point direction, int *score);
    ~Projectile();
    Projectile(Projectile const &);
    Projectile &operator=(Projectile const &);

    void add_score(int value);
    void end_turn();
    // getters
    BluePrint const &get_blueprint() const;
    virtual Point get_direction() const;
    Point get_move() const;
    EntityType get_type() const;
    // setters
    void set_direction(Point dir);
    // collision
    IGameEntity *collide(IGameEntity *);
    IGameEntity *get_collided(Obstacle *);
    IGameEntity *get_collided(Projectile *);
    IGameEntity *get_collided(Enemy *);
    IGameEntity *get_collided(Player *);
    IGameEntity *get_collided(Road *);
};

#endif /* PROJECTILE_HPP */
