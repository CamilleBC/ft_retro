/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MsTimer.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 17:22:56 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/26 20:56:45 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSTIMER_HPP
#define MSTIMER_HPP

#include "Constants.hpp"
#include <cstddef>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/time.h>

class MsTimer {
  private:
    timespec delta_start;
    unsigned long start_msec;
    // unsigned long pause_msec;
    // unsigned long total_pause_msec;
    unsigned long last_pause_msec;
    unsigned long total_msec;
    bool is_paused;

    timespec substract_timespec(timespec t1, timespec t2);

  public:
    MsTimer();
    MsTimer(MsTimer const &other);
    ~MsTimer();
    MsTimer &operator=(MsTimer const &rhs);
    unsigned long get_current_msec() const;
    std::string get_current_string() const;
    bool is_new_frame();
    void end_pause();
    void start_pause();
};

#endif /* TIMER_HPP */
