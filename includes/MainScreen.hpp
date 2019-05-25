/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainScreen.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 22:56:31 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/25 17:25:56 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAINSCREEN_HPP
#define MAINSCREEN_HPP

#include "BluePrint.hpp"
#include "Constants.hpp"
#include "IGameEntity.hpp"
#include "Point.hpp"
#include "Resolution.hpp"
#include <iostream>
#include <ncurses.h>

class MainScreen {
  private:
    static size_t const box;
    Resolution const res;
    Point const pos;
    static size_t const x_factor;
    WINDOW *win;
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
    void init();
    void clear();
    WINDOW *get_win();
    void print(IGameEntity *grid[GRID_HEIGHT][GRID_WIDTH]);
    void render();
};

#endif /* MAINSCREEN_HPP */
