/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StatusScreen.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 22:56:31 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/26 11:12:10 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef StatusScreen_HPP
#define StatusScreen_HPP

#include "Constants.hpp"
#include "MsTimer.hpp"
#include "Screen.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ncurses.h>

class StatusScreen: public Screen{
  private:
    unsigned int lives;
    unsigned int score;
    MsTimer const *timer;

    // constructors
    StatusScreen();
    // methods
    void print_current_time();
    void print_lives();
    void print_score();

  public:
    StatusScreen(unsigned int height, unsigned int width, unsigned int starty,
                 unsigned int startx, unsigned int lives, MsTimer const *timer);
    StatusScreen(StatusScreen const &other);
    ~StatusScreen();
    // operators
    StatusScreen &operator=(StatusScreen const &rhs);
    // methods
    void print_status();
};

#endif /* StatusScreen_HPP */
