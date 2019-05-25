/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StatusScreen.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 22:56:31 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/25 11:25:44 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef StatusScreen_HPP
#define StatusScreen_HPP

#include "Constants.hpp"
#include "BluePrint.hpp"
#include "Point.hpp"
#include "Resolution.hpp"
#include <iostream>
#include <ncurses.h>

class StatusScreen {
  private:
    static size_t const box;
    Resolution const res;
    Point const pos;
    static size_t const x_factor;
    WINDOW *win;
    // constructors
    StatusScreen();
    // methods

  public:
    StatusScreen(unsigned int height, unsigned int width, unsigned int starty,
               unsigned int startx);
    StatusScreen(StatusScreen const &other);
    ~StatusScreen();
    // operators
    StatusScreen &operator=(StatusScreen const &rhs);
    // methods
    void init();
    void print();
    void render();
};

#endif /* StatusScreen_HPP */
