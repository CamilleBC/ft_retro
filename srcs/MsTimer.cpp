/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MsTimer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 17:18:30 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/26 21:01:51 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MsTimer.hpp"

MsTimer::MsTimer() {
    timeval start;
    gettimeofday(&start, NULL);
    clock_gettime(CLOCK_REALTIME, &delta_start);
    start_msec = start.tv_sec * 1000 + start.tv_usec / 1000;
    // pause_msec = 0;
    last_pause_msec = start_msec;
    total_msec = 0;
    is_paused = false;
}

MsTimer::MsTimer(MsTimer const &other) { *this = other; }

MsTimer::~MsTimer() {}

MsTimer &MsTimer::operator=(MsTimer const &rhs) {
    start_msec = rhs.start_msec;
    delta_start = rhs.delta_start;
    start_msec = 0;
    // pause_msec = 0;
    last_pause_msec = 0;
    total_msec = 0;
    return *this;
}

bool MsTimer::is_new_frame() {
    long ns_per_frame = 1E9 / FPS;
    timespec current;
    timespec delta_time;

    clock_gettime(CLOCK_REALTIME, &current);
    delta_time = substract_timespec(delta_start, current);

    if (delta_time.tv_sec > 0 || delta_time.tv_nsec >= ns_per_frame) {
        clock_gettime(CLOCK_REALTIME, &delta_start);
        return true;
    }
    return false;
}

void MsTimer::end_pause() {
    timeval current;
    gettimeofday(&current, NULL);
    last_pause_msec = current.tv_sec * 1000 + current.tv_usec / 1000;
    // total_pause_msec = end_pause_msec - pause_msec;
    // pause_msec = 0;
    is_paused = false;
}

void MsTimer::start_pause() {
    is_paused = true;
    timeval current;
    gettimeofday(&current, NULL);
    unsigned long current_msec = current.tv_sec * 1000 + current.tv_usec / 1000;
    total_msec = (current_msec - last_pause_msec) + total_msec;
    // pause_msec = current.tv_sec * 1000 + current.tv_usec / 1000;
}

unsigned long MsTimer::get_current_msec() const {
    if (is_paused) {
        return total_msec;
    }
    timeval current;
    gettimeofday(&current, NULL);
    unsigned long current_msec = current.tv_sec * 1000 + current.tv_usec / 1000;
    return (current_msec - last_pause_msec) + total_msec;
    // return current_msec - start_msec - total_pause_msec;
}

std::string MsTimer::get_current_string() const {
    std::ostringstream string_stream;
    unsigned long time_minute = 0;
    unsigned long time_sec = 0;
    unsigned long time_msec = get_current_msec();

    while (time_msec >= 60E3) {
        ++time_minute;
        time_msec -= 60E3;
    }
    while (time_msec >= 1E3) {
        ++time_sec;
        time_msec -= 1E3;
    }
    string_stream << std::setfill('0') << std::setw(2) << time_minute << ":"
                  << std::setfill('0') << std::setw(2) << time_sec << ":"
                  << std::setfill('0') << std::setw(3) << time_msec;
    return string_stream.str();
}

/* PRIVATE */

timespec MsTimer::substract_timespec(timespec t1, timespec t2) {
    timespec result;
    result.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    result.tv_sec = t2.tv_sec - t1.tv_sec;
    if (result.tv_sec > 0 && result.tv_nsec < 0) {
        result.tv_nsec += 1E9;
        result.tv_sec--;
    } else if (result.tv_sec < 0 && result.tv_nsec > 0) {
        result.tv_nsec -= 1E9;
        result.tv_sec++;
    }
    return result;
}
