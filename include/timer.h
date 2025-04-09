#ifndef TIMER_H
#define TIMER_H

#include <SDL2/SDL.h>
#include <functional>

class Timer {
public:
    Timer(Uint32 interval = 1000);
    ~Timer();
    
    // Consulta o valor atual
    Uint32 getTotalTime() const;
    
    // Controle do timer
    void start();
    void stop();
    void reset();
    
private:
    static Uint32 callbackWrapper(Uint32 interval, void* param);
    Uint32 handleCallback(Uint32 interval);
    
    SDL_TimerID timerID = 0;
    Uint32 counter = 0;
    Uint32 lastUpdate = 0;
    Uint32 timerInterval = 1000;
    bool isRunning = false;
};

#endif