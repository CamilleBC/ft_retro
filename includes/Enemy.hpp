/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 09:58:32 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/25 19:43:10 by cbaillat         ###   ########.fr       */
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
    Point direction;
    bool has_moved;
    Point shoot;
    Enemy();
    void init();

  public:
    Enemy(Point);
    ~Enemy();
    Enemy(Enemy const &);
    Enemy &operator=(Enemy const &);

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

#endif /* ENEMY_HPP */
