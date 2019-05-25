/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 15:27:38 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/25 15:42:44 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "IGameEntity.hpp"
class Player : public IGameEntity {
  private:
  public:
    Player();
    Player(Player const &other);
    ~Player();
    Player const &operator=(Player const &rhs);
    Point get_move();

    BluePrint const &get_blueprint() const;

    IGameEntity* collide(IGameEntity*);
    IGameEntity* get_collided(Obstacle*);
    IGameEntity* get_collided(Enemy*);

    void end_turn() = 0;
};

#endif /* PLAYER_HPP */
