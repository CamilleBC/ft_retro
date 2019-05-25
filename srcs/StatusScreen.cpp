/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StatusScreen.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 22:56:43 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/25 15:35:21 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StatusScreen.hpp"

StatusScreen::StatusScreen(unsigned int height, unsigned int width,
                           unsigned int starty, unsigned int startx)
    : res(width, height), pos(startx, starty) {
    std::cout << "StatusScreen created." << std::endl;
}

StatusScreen::~StatusScreen() {
    std::cout << "StatusScreen died." << std::endl;
    // wborder(win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    // wrefresh(win);
    // delwin(win);
}

void StatusScreen::init() {
    win = newwin(res.height, res.width, pos.y, pos.x);
    cbreak();           /* Line buffering disabled */
    noecho();           /* Don't echo() while we do getch */
    nodelay(win, true); /* getch is non-blocking */
    wborder(win, ACS_LTEE, ACS_RTEE, ACS_TTEE, ACS_BTEE, ACS_ULCORNER,
            ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
    /* The parameters taken are
     * 1. win: the window on which to operate
     * 2. ls: character to be used for the left side of the window
     * 3. rs: character to be used for the right side of the window
     * 4. ts: character to be used for the top side of the window
     * 5. bs: character to be used for the bottom side of the window
     * 6. tl: character to be used for the top left corner of the window
     * 7. tr: character to be used for the top right corner of the window
     * 8. bl: character to be used for the bottom left corner of the window
     * 9. br: character to be used for the bottom right corner of the window
     */
    wrefresh(win);
}

void StatusScreen::print() {}

void StatusScreen::clear() { wclear(win); }

void StatusScreen::render() { wrefresh(win); }

/* PRIVATE */

StatusScreen::StatusScreen() : res(0, 0) {}

// static

size_t const StatusScreen::x_factor = 1;
size_t const StatusScreen::box = 1;
