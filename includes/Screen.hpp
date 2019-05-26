/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 10:00:55 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/26 11:50:34 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_HPP
#define SCREEN_HPP

#include "Constants.hpp"
#include "Point.hpp"
#include "Resolution.hpp"
#include <iostream>
#include <ncurses.h>

typedef struct borders {
    char left;
    char right;
    char top;
    char bottom;
    char top_left;
    char top_right;
    char bottom_left;
    char bottom_right;
    borders(char left, char right, char top, char bottom, char top_left,
            char top_right, char bottom_left, char bottom_right)
        : left(left), right(right), top(top),
          bottom(bottom), top_left(top_left), top_right(top_right),
          bottom_left(bottom_left), bottom_right(bottom_right) {}
        borders(char const borders[9])
        : left(borders[0]), right(borders[1]), top(borders[2]),
          bottom(borders[3]), top_left(borders[4]), top_right(borders[5]),
          bottom_left(borders[6]), bottom_right(borders[7]) {}
} Borders;

class Screen {
  private:
    Borders borders;
    static size_t const box;
    Point const pos;
    Resolution const res;
    WINDOW *win;

  public:
    Screen();
    Screen(unsigned int height, unsigned int width, unsigned int starty,
           unsigned int startx, Borders borders);
    Screen(Screen const &other);
    ~Screen();
    // operators
    Screen &operator=(Screen const &rhs);
    // methods
    void init();
    void clear();
    void render();
    // getters
    WINDOW *get_win() const;
    size_t get_box() const;
};

#endif /* SCREEN_HPP */
