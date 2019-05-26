/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainScreen.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 22:56:31 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/26 16:27:16 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAINSCREEN_HPP
#define MAINSCREEN_HPP

#include "BluePrint.hpp"
#include "Point.hpp"
#include "Constants.hpp"
#include "IGameEntity.hpp"
#include "Screen.hpp"
#include <iostream>
#include <ncurses.h>

class MainScreen : public Screen {
  private:
    static size_t const x_factor;
    // constructors
    MainScreen();
    // methods
    void print_empty(Point coord);
    void print_object(BluePrint const &object, Point coord);

  public:
    MainScreen(unsigned int height, unsigned int width, unsigned int starty,
               unsigned int startx);
    MainScreen(MainScreen const &other);
    ~MainScreen();
    // operators
    MainScreen &operator=(MainScreen const &rhs);
    // methods
    void print(IGameEntity ***grid);
};

#endif /* MAINSCREEN_HPP */
