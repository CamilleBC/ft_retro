/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainScreen.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 22:56:31 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/25 01:00:40 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAINSCREEN_HPP
#define MAINSCREEN_HPP

#include <ncurses.h>
#include <iostream>

typedef struct SResolution {
    unsigned int width;
    unsigned int height;
    SResolution(unsigned int width, unsigned int height)
        : width(width), height(height) {}
} Resolution;

// total width 334
// total heigh 84

class MainScreen {
  private:
    Resolution const res;
    WINDOW *win;
    // constructors
    MainScreen();
    // methods
    void init();

  public:
    MainScreen(unsigned int height, unsigned int width, unsigned int starty,
               unsigned int startx);
    MainScreen(MainScreen const &other);
    ~MainScreen();
    // operators
    MainScreen &operator=(MainScreen const &rhs);
    // methods
    void render();
};

#endif /* MAINSCREEN_HPP */
