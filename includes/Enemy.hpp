/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 09:58:32 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/26 09:15:44 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "IGameEntity.hpp"
#include "Obstacle.hpp"
#include "Point.hpp"
#include <iostream>

class Enemy : public IGameEntity {
  private:
    static const BluePrint blueprint;
    static const EntityType type;
    Point direction;
    mutable bool has_moved;
    Enemy();
    void init();

  public:
    Enemy(Point);
    ~Enemy();
    Enemy(Enemy const &);
    Enemy &operator=(Enemy const &);

    // methods
    void end_turn();
    // getters
    Point get_direction() const;
    BluePrint const &get_blueprint() const;
    Point get_move() const;
    EntityType get_type() const;
    //setters
    void set_direction(Point dir);
    // collision
    IGameEntity *collide(IGameEntity *);
    IGameEntity *get_collided(Obstacle *);
    IGameEntity *get_collided(Enemy *);
    IGameEntity *get_collided(Projectile *);
    IGameEntity *get_collided(Player *);
};

#endif /* ENEMY_HPP */
