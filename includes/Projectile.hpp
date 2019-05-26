/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 11:44:43 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/26 10:47:30 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "IGameEntity.hpp"
#include "Point.hpp"
#include <iostream>

class Projectile : public IGameEntity {
  private:
    static const BluePrint blueprint;
    static const EntityType type;
    Point direction;
    mutable bool has_moved;
    IGameEntity *owner;
    Projectile();

  public:
    Projectile(IGameEntity* owner, Point direction);
    ~Projectile();
    Projectile(Projectile const &);
    Projectile &operator=(Projectile const &);

    void end_turn();
    // getters
    BluePrint const &get_blueprint() const;
    virtual Point get_direction() const;
    Point get_move() const;
    EntityType get_type() const;
    //setters
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
