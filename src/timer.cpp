#include "timer.h"
#include <iostream>

Timer::Timer(Uint32 interval) : timerInterval(interval) {
    lastUpdate = SDL_GetTicks();
}

Timer::~Timer() {
    stop();
}

Uint32 Timer::getTotalTime() const {
    return counter;
}

void Timer::start() {
    if (!isRunning) {
        timerID = SDL_AddTimer(timerInterval, &Timer::callbackWrapper, this);
        isRunning = true;
        lastUpdate = SDL_GetTicks();
    }
}

void Timer::stop() {
    if (isRunning) {
        SDL_RemoveTimer(timerID);
        isRunning = false;
    }
}

void Timer::reset() {
    counter = 0;
    lastUpdate = SDL_GetTicks();
}

// Função static que redireciona para a função de membro
Uint32 Timer::callbackWrapper(Uint32 interval, void* param) {
    Timer* timer = static_cast<Timer*>(param);
    return timer->handleCallback(interval);
}

// Função de callback real
Uint32 Timer::handleCallback(Uint32 interval) {
    Uint32 now = SDL_GetTicks();
    counter += (now - lastUpdate);
    lastUpdate = now;
    return interval;
}