/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainScreen.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 22:56:43 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/25 10:22:37 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MainScreen.hpp"

MainScreen::MainScreen(unsigned int height, unsigned int width,
                       unsigned int starty, unsigned int startx)
    : res(width, height), pos(startx, starty) {
    std::cout << "MainScreen created." << std::endl;
}

MainScreen::~MainScreen() {
    std::cout << "MainScreen died." << std::endl;
    wborder(win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(win);
    delwin(win);
}

void MainScreen::init() {
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

void MainScreen::print(BluePrint const &object, Point coord) {
    for (size_t i = 0; i < object.size; ++i) {
        mvwprintw(win, coord.y + i , coord.x, object.content[i].c_str());
    }
}

void MainScreen::render() { wrefresh(win); }

/* PRIVATE */

MainScreen::MainScreen() : res(0, 0) {}
