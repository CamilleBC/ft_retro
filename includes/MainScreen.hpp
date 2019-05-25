/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainScreen.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 22:56:31 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/25 10:06:15 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAINSCREEN_HPP
#define MAINSCREEN_HPP

#include "BluePrint.hpp"
#include "Point.hpp"
#include "Resolution.hpp"
#include <iostream>
#include <ncurses.h>

class MainScreen {
  private:
    Resolution const res;
    Point const pos;
    WINDOW *win;
    // constructors
    MainScreen();
    // methods

  public:
    MainScreen(unsigned int height, unsigned int width, unsigned int starty,
               unsigned int startx);
    MainScreen(MainScreen const &other);
    ~MainScreen();
    // operators
    MainScreen &operator=(MainScreen const &rhs);
    // methods
    void init();
    void print(BluePrint const &object, Point coord);
    void render();
};

#endif /* MAINSCREEN_HPP */
