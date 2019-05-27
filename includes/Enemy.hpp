/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 09:58:32 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/27 08:44:17 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "IGameEntity.hpp"
#include "Constants.hpp"
#include "Obstacle.hpp"
#include "Player.hpp"
#include "Point.hpp"
#include "Projectile.hpp"
#include "ICanShoot.hpp"
#include "Road.hpp"
#include <iostream>

class Enemy : public IGameEntity, public ICanShoot {
  private:
    static const int colour;
    static const BluePrint blueprint;
    static const EntityType type;
    static const int reward;
    Point direction;
    int max_speed;
    mutable int speed;
    int max_reload;
    mutable int reload;
    Enemy();
    void init();

  public:
    Enemy(Point, int);
    ~Enemy();
    Enemy(Enemy const &);
    Enemy &operator=(Enemy const &);

    // getters
    Point get_direction() const;
    BluePrint const &get_blueprint() const;
    Point get_move() const;
    int get_reward() const;
    EntityType get_type() const;
    bool get_is_shooting() const;
    Point get_shot() const;
    // setters
    void set_is_shooting(bool);
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
