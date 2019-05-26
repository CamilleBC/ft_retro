/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 16:04:49 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/26 09:19:27 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "ICanShoot.hpp"
#include "IGameEntity.hpp"

class Player : public IGameEntity, public ICanShoot {
  private:
    static const BluePrint blueprint;
    static const EntityType type;
    mutable Point direction;
    mutable bool has_moved;
    bool is_shooting;
    Point shot;
    Player();
    void init();

  public:
    Player(Point);
    ~Player();
    Player(Player const &);
    Player &operator=(Player const &);

    void end_turn();
    // getters
    bool get_is_shooting() const;
    BluePrint const &get_blueprint() const;
    Point get_direction() const;
    Point get_move() const;
    Point get_shot() const;
    EntityType get_type() const;

    // setters
    void set_is_shooting(bool shooting);
    void set_direction(Point);
    // collision
    IGameEntity *collide(IGameEntity *);
    IGameEntity *get_collided(Obstacle *);
    IGameEntity *get_collided(Enemy *);
    IGameEntity *get_collided(Projectile *);
    IGameEntity *get_collided(Player *);
    IGameEntity *get_collided(Road *);
};

#endif /* PLAYER_HPP */
