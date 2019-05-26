/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICanShoot.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 08:22:22 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/26 09:21:25 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICANSHOOT_HPP
#define ICANSHOOT_HPP

#include "Point.hpp"

class ICanShoot {
  private:
  public:
    virtual ~ICanShoot() {}
    // getters
    virtual bool get_is_shooting() const = 0;
    virtual Point get_shot() const = 0;
    // setters
    virtual void set_is_shooting(bool) = 0;
};

#endif /* ICANSHOOT_HPP */
