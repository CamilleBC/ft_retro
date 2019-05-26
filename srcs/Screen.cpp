/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 10:03:49 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/26 11:52:15 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Screen.hpp"

Screen::Screen(unsigned int height, unsigned int width, unsigned int starty,
               unsigned int startx, Borders borders)
    : borders(borders), pos(startx, starty), res(width, height) {
    std::cout << "Screen created." << std::endl;
}

Screen::~Screen() { std::cout << "Screen died." << std::endl; }

// methods

void Screen::clear() { wclear(win); }

void Screen::init() {
    win = newwin(res.height, res.width, pos.y, pos.x);
    cbreak();           /* Line buffering disabled */
    noecho();           /* Don't echo() while we do getch */
    nodelay(win, true); /* getch is non-blocking */
    wborder(win, borders.left, borders.right, borders.top, borders.bottom,
            borders.top_left, borders.top_right, borders.bottom_left,
            borders.bottom_right);
    wrefresh(win);
}

void Screen::render() { wrefresh(win); }

// getters

WINDOW *Screen::get_win() const { return win; }

size_t Screen::get_box() const { return box; }

/* PRIVATE */

Screen::Screen() : borders("        "), pos(0, 0), res(0, 0) {}

// static

size_t const Screen::box = 1;
