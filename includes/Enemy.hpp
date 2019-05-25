/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 09:58:32 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/25 10:32:02 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "IGameEntity.hpp"
#include "Point.hpp"
#include <iostream>

class Enemy : public IGameEntity {
  private:
    Point direction;
    bool has_moved;
    Enemy();

  public:
    Enemy(Point);
    ~Enemy();
    Enemy(Enemy const &);
    Enemy &operator=(Enemy const &);

    Point get_move();

    std::string get_texture() const;

    IGameEntity *collide(IGameEntity *);
    IGameEntity *get_collided(Obstacle *);
    IGameEntity *get_collided(Enemy *);
    void end_turn();
};

#endif /* ENEMY_HPP */
