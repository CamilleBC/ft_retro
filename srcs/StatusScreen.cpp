/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StatusScreen.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 22:56:43 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/26 11:06:39 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StatusScreen.hpp"

StatusScreen::StatusScreen(unsigned int height, unsigned int width,
                           unsigned int starty, unsigned int startx,
                           unsigned int lives, MsTimer const *timer)
    : res(width, height), pos(startx, starty), lives(lives), score(0),
      timer(timer) {
    std::cout << "StatusScreen created." << std::endl;
}

StatusScreen::~StatusScreen() {
    std::cout << "StatusScreen died." << std::endl;
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

void StatusScreen::set_score(int new_score) { score = new_score; }

void StatusScreen::print() {
    print_current_time();
    print_score();
}

void StatusScreen::clear() { wclear(win); }

void StatusScreen::render() { wrefresh(win); }

/* PRIVATE */

StatusScreen::StatusScreen() : res(0, 0), lives(0), score(0), timer(NULL) {}

void StatusScreen::print_current_time() {
    timespec time = timer->get_current_time();

    std::ostringstream string_stream;
    unsigned int minute = 0;
    while (time.tv_sec >= 60) {
        ++minute;
        time.tv_sec -= 60;
    }

    string_stream << "Elapsed time: " << std::setfill('0') << std::setw(2)
                  << minute << ":" << std::setfill('0') << std::setw(2)
                  << (unsigned long)time.tv_sec;
    std::string time_str = string_stream.str();
    time_str.resize(20);
    mvwprintw(win, 5, 5, time_str.c_str());
}

void StatusScreen::print_score() {
    std::ostringstream string_stream;

    string_stream << "Score : " << score << " points";
    mvwprintw(win, 6, 5, string_stream.str().c_str());
}

// static

size_t const StatusScreen::box = 1;
