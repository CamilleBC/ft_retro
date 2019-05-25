/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGameEntity.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 22:52:17 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/25 11:55:56 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IGAMEENTITY_HPP
#define IGAMEENTITY_HPP

#include "Point.hpp"
#include <string>

class Obstacle;
class Projectile;
class Enemy;

class IGameEntity {
    public:
        virtual ~IGameEntity() {}
        virtual Point get_move() = 0;

        virtual std::string get_texture() const = 0;

        virtual IGameEntity* collide(IGameEntity*) = 0;
        virtual IGameEntity* get_collided(Obstacle*) = 0;
        virtual IGameEntity* get_collided(Enemy*) = 0;
        virtual IGameEntity* get_collided(Projectile*) = 0;

        virtual void end_turn() = 0;
};

#include "Projectile.hpp"
#include "Enemy.hpp"
#include "Obstacle.hpp"

#endif /* IGAMEENTITY_HPP */
