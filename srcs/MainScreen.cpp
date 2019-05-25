/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainScreen.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 22:56:43 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/25 15:02:33 by cbaillat         ###   ########.fr       */
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
    keypad(win,TRUE);
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

// void MainScreen::print(IGameEntity ***grid) {
void MainScreen::print(IGameEntity *grid[GRID_HEIGHT][GRID_WIDTH]) {
    for (size_t h = 0; h < GRID_HEIGHT; ++h) {
        for (size_t w = 0; w < GRID_WIDTH; ++w) {
            if (grid[h][w] != NULL) {
                print_object(grid[h][w]->get_blueprint(), Point(w, h));
            } else {
                print_empty(Point(w, h));
            }
        }
    }
}

void MainScreen::print_empty(Point coord) {
    std::string empty(x_factor, '*');
    mvwprintw(win, coord.y + box, coord.x * x_factor + box, empty.c_str());
}

void MainScreen::print_object(BluePrint const &object, Point coord) {
        mvwprintw(win, coord.y + box, coord.x * x_factor + box,
                  object.texture->c_str());
    // for (size_t i = 0; i < object.size; ++i) {
    //     mvwprintw(win, coord.y + i + box, coord.x * x_factor + box,
    //               object.texture[i].c_str());
    // }
}

void MainScreen::render() { wrefresh(win); }

/* PRIVATE */

MainScreen::MainScreen() : res(0, 0) {}

// static

size_t const MainScreen::x_factor = 3;
size_t const MainScreen::box = 1;
