/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 11:44:43 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/26 09:16:20 by cbaillat         ###   ########.fr       */
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
    Point direction;
    mutable bool has_moved;
    Projectile();

  public:
    Projectile(Point);
    ~Projectile();
    Projectile(Projectile const &);
    Projectile &operator=(Projectile const &);

    void end_turn();
    // getters
    BluePrint const &get_blueprint() const;
    virtual Point get_direction() const;
    Point get_move() const;
    //setters
    void set_direction(Point dir);
    // collision
    IGameEntity *collide(IGameEntity *);
    IGameEntity *get_collided(Obstacle *);
    IGameEntity *get_collided(Projectile *);
    IGameEntity *get_collided(Enemy *);
    IGameEntity *get_collided(Player *);
};

#endif /* PROJECTILE_HPP */
