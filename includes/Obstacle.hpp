/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Obstacle.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 23:17:24 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/25 16:20:49 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include "IGameEntity.hpp"
#include "Enemy.hpp"
#include "Point.hpp"
#include <iostream>

class Obstacle : public IGameEntity {
    private:
        static const BluePrint blueprint;
        Point direction;
        bool has_moved;
        Obstacle();
        void init();

    public:
        Obstacle(Point);
        ~Obstacle();
        Obstacle(Obstacle const &);
        Obstacle &operator=(Obstacle const &);

        Point get_move();

        BluePrint const &get_blueprint() const;

        IGameEntity*  collide(IGameEntity*);
        IGameEntity*  get_collided(Obstacle*);
        IGameEntity*  get_collided(Enemy*);
        IGameEntity*  get_collided(Projectile*);
        IGameEntity*  get_collided(Player*);
        void  end_turn();
};

#endif /* OBSTACLE_HPP */
