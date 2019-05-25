/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGameEntity.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 22:52:17 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/25 11:55:59 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IGAMEENTITY_HPP
#define IGAMEENTITY_HPP

#include "BluePrint.hpp"
#include "Point.hpp"
#include <string>

class Obstacle;
class Enemy;

class IGameEntity {
    public:
        virtual ~IGameEntity() {}
        virtual Point get_move() = 0;

        virtual BluePrint const &get_blueprint() const = 0;

        virtual IGameEntity* collide(IGameEntity*) = 0;
        virtual IGameEntity* get_collided(Obstacle*) = 0;
        virtual IGameEntity* get_collided(Enemy*) = 0;

        virtual void end_turn() = 0;
};

#endif /* IGAMEENTITY_HPP */
