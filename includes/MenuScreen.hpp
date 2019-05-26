/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MenuScreen.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 13:34:17 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/26 13:57:13 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENUSCREEN_HPP
#define MENUSCREEN_HPP

#include "Screen.hpp"

class MenuScreen : public Screen {
  private:
    // constructors
    MenuScreen();

  public:
    MenuScreen(unsigned int height, unsigned int width, unsigned int starty,
               unsigned int startx);
    MenuScreen(MenuScreen const &other);
    ~MenuScreen();
    // operators
    MenuScreen &operator=(MenuScreen const &rhs);
    // methods
    void print_menu();
};

#endif /* MENUSCREEN_HPP */
