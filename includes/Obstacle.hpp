/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Obstacle.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 23:17:24 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/26 21:48:01 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include "Constants.hpp"
#include "Enemy.hpp"
#include "IGameEntity.hpp"
#include "Player.hpp"
#include "Point.hpp"
#include "Projectile.hpp"
#include "Road.hpp"
#include <iostream>

class Obstacle : public IGameEntity {
  private:
    static const int colour;
    static const BluePrint blueprint;
    static const EntityType type;
    static const int reward;
    Point direction;
    int max_speed;
    mutable int speed;

  public:
    Obstacle();
    Obstacle(Point c_direction);
    Obstacle(Point c_direction, int speed);
    Obstacle(Obstacle const &other);
    ~Obstacle();
    Obstacle &operator=(Obstacle const &rhs);

    void init();
    // getters
    BluePrint const &get_blueprint() const;
    virtual Point get_direction() const;
    Point get_move() const;
    int get_reward() const;
    EntityType get_type() const;
    // setters
    void set_direction(Point dir);
    // collision
    IGameEntity *collide(IGameEntity *);
    IGameEntity *get_collided(Obstacle *);
    IGameEntity *get_collided(Enemy *);
    IGameEntity *get_collided(Projectile *);
    IGameEntity *get_collided(Player *);
    IGameEntity *get_collided(Road *);
};

#endif /* OBSTACLE_HPP */
