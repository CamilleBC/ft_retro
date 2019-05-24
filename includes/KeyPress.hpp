/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KeyPress.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 00:34:54 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/25 01:13:07 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYPRESS_HPP
#define KEYPRESS_HPP

#include <cstddef> // size_t def

// DEBUG:
#include <iostream>

class KeyPress {
  private:
    static int const key_empty;
    size_t const size;
    int *keys;
    // constructor
    KeyPress();

  public:
    KeyPress(size_t size);
    KeyPress(KeyPress const &other);
    ~KeyPress();
    // operator
    KeyPress &operator=(KeyPress const);
    // methods
    void add(int key);
    void clear();
    bool contains(int key);
    // DEBUG
    void display_content();
};

#endif /* KEYPRESS_HPP */
