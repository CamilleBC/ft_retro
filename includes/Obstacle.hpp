/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Obstacle.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 23:17:24 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/25 19:07:55 by chaydont         ###   ########.fr       */
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
    static const BluePrint blueprint;
    Point direction;
    bool has_moved;
    int max_speed;
    int speed;
    Point shoot;

    Obstacle();
    void init();

  public:
    Obstacle(Point);
    Obstacle(Point direction, int speed);
    ~Obstacle();
    Obstacle(Obstacle const &);
    Obstacle &operator=(Obstacle const &);

    Point get_move();
    Point get_shoot();
    void set_shoot(Point);

    BluePrint const &get_blueprint() const;

    IGameEntity *collide(IGameEntity *);
    IGameEntity *get_collided(Obstacle *);
    IGameEntity *get_collided(Enemy *);
    IGameEntity *get_collided(Projectile *);
    IGameEntity *get_collided(Player *);
    void end_turn();
};

#endif /* OBSTACLE_HPP */
