/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 16:04:49 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/25 19:05:10 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "IGameEntity.hpp"

class Player : public IGameEntity {
  private:
    static const BluePrint blueprint;
    Point direction;
    bool has_moved;
    Point shoot;
    Player();
    void init();

  public:
    Player(Point);
    ~Player();
    Player(Player const &);
    Player &operator=(Player const &);

    Point get_move();
    Point get_shoot();
    void set_shoot(Point);
    void set_shoot();
    BluePrint const &get_blueprint() const;

    void set_direction(Point);
    IGameEntity *collide(IGameEntity *);
    IGameEntity *get_collided(Obstacle *);
    IGameEntity *get_collided(Enemy *);
    IGameEntity *get_collided(Projectile *);
    IGameEntity *get_collided(Player *);
    void end_turn();
};

#endif /* PLAYER_HPP */
