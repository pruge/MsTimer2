#ifndef MsTimer2_h
#define MsTimer2_h

#ifdef __AVR__
#include <avr/interrupt.h>
#elif defined(__arm__) && defined(TEENSYDUINO)
#include <Arduino.h>
#else
#error MsTimer2 library only works on AVR architecture
#endif

namespace MsTimer2 {
extern unsigned long msecs;
extern void (*func)();
extern void (*func2)(void *);
extern void *_FuncParam;
extern volatile unsigned long count;
extern volatile char overflowing;
extern volatile unsigned int tcnt2;

void set(unsigned long ms);
void set(unsigned long ms, void (*f)());
void set(unsigned long ms, void (*f)(void *), void *parameter);
void start();
void stop();
void _overflow();
} // namespace MsTimer2

#endif
