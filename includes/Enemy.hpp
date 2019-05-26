/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 09:58:32 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/26 18:29:14 by chaydont         ###   ########.fr       */
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
    int max_speed;
    mutable int speed;
    Enemy();
    void init();

  public:
    Enemy(Point, int);
    ~Enemy();
    Enemy(Enemy const &);
    Enemy &operator=(Enemy const &);

    // methods
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
    IGameEntity *get_collided(Road *e);
};

#endif /* ENEMY_HPP */
