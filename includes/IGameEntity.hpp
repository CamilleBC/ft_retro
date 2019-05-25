/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGameEntity.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 22:52:17 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/25 09:20:25 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IGAMEENTITY_HPP
#define IGAMEENTITY_HPP

#include "Point.hpp"

class Obstacle;

class IGameEntity {
    public:
        virtual ~IGameEntity() {}
        virtual Point get_move() = 0;
        virtual IGameEntity* collide(Obstacle*) = 0;
        virtual void end_turn() = 0;
};

#endif /* IGAMEENTITY_HPP */
