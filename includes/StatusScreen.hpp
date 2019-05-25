/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StatusScreen.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 22:56:31 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/25 18:48:15 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef StatusScreen_HPP
#define StatusScreen_HPP

#include "BluePrint.hpp"
#include "Constants.hpp"
#include "Point.hpp"
#include "Resolution.hpp"
#include "MsTimer.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ncurses.h>

class StatusScreen {
  private:
    static size_t const box;
    Resolution const res;
    Point const pos;
    WINDOW *win;
    // status
    unsigned int lives;
    unsigned int score;
    MsTimer const *timer;

    // constructors
    StatusScreen();
    // methods
    void print_current_time();

  public:
    StatusScreen(unsigned int height, unsigned int width, unsigned int starty,
                 unsigned int startx, unsigned int lives, MsTimer const *timer);
    StatusScreen(StatusScreen const &other);
    ~StatusScreen();
    // operators
    StatusScreen &operator=(StatusScreen const &rhs);
    // methods
    void init();
    void clear();
    void print();
    void render();
};

#endif /* StatusScreen_HPP */
