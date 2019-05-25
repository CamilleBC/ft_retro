/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Obstacle.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 23:17:24 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/25 09:20:01 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include "IGameEntity.hpp"
#include "Point.hpp"
#include <iostream>

class Obstacle : public IGameEntity {
    private:
        Point direction;
        bool has_moved;
        Obstacle();

    public:
        Obstacle(Point);
        ~Obstacle();
        Obstacle(Obstacle const &);
        Obstacle &operator=(Obstacle const &);

        Point get_move();
        IGameEntity*  collide(Obstacle*);
        void  end_turn();
};

#endif /* OBSTACLE_HPP */
