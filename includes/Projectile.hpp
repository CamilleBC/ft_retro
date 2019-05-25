/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 11:44:43 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/25 12:01:27 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "IGameEntity.hpp"
#include "Point.hpp"
#include <iostream>

class Projectile : public IGameEntity {
    private:
        bool    has_moved;
        Projectile();

    public:
        Projectile(Point);
        ~Projectile();
        Projectile(Projectile const &);
        Projectile &operator=(Projectile const &);

        Point get_move();

        std::string get_texture() const;

        IGameEntity*  collide(IGameEntity*);
        IGameEntity*  get_collided(Obstacle*);
        IGameEntity*  get_collided(Projectile*);
        IGameEntity*  get_collided(Enemy*);
        void  end_turn();
};


#endif /* PROJECTILE_HPP */
