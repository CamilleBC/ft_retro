/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Obstacle.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 23:17:24 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/25 19:47:28 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include "Enemy.hpp"
#include "IGameEntity.hpp"
#include "Point.hpp"
#include <iostream>

class Obstacle : public IGameEntity {
  private:
    Point direction;
    int max_speed;
    int speed;
    Point shoot;
    static const BluePrint blueprint;
    bool has_moved;

  public:
    Obstacle();
    Obstacle(Point c_direction);
    Obstacle(Point c_direction, int speed);
    Obstacle(Obstacle const &other);
    ~Obstacle();
    Obstacle &operator=(Obstacle const &rhs);
    void init();

    Point Rand_dir();

    Point get_move();
    Point get_shoot();
    void set_shoot(Point);

    // getters
    BluePrint const &get_blueprint() const;
    // collision
    IGameEntity *collide(IGameEntity *);
    IGameEntity *get_collided(Obstacle *);
    IGameEntity *get_collided(Enemy *);
    IGameEntity *get_collided(Projectile *);
    IGameEntity *get_collided(Player *);
    void end_turn();
};

#endif /* OBSTACLE_HPP */
