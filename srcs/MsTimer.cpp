/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MsTimer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 17:18:30 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/25 19:56:09 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MsTimer.hpp"

MsTimer::MsTimer() {
    clock_gettime(CLOCK_REALTIME, &start);
    delta_start = start;
}

MsTimer::MsTimer(MsTimer const &other) { *this = other; }

MsTimer::~MsTimer() {}

MsTimer &MsTimer::operator=(MsTimer const &rhs) {
    start = rhs.start;
    delta_start = rhs.delta_start;
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

timespec MsTimer::get_current_time() const {
    timespec current;
    timespec result;
    clock_gettime(CLOCK_REALTIME, &current);
    result.tv_sec = current.tv_sec - start.tv_sec;
    result.tv_nsec = current.tv_nsec - start.tv_nsec;
    return result;
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
