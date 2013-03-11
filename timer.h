/**
 * ----------------------------------------------------------------------------
 *
 * "THE ANY BEVERAGE-WARE LICENSE" (Revision 42 - based on beer-ware license):
 * <dev@layer128.net> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a be(ve)er(age) in return. (I don't
 * like beer much.)
 *
 * Matthias Kleemann
 *
 * ----------------------------------------------------------------------------
 *
 * \file timer.h
 *
 * Note: It is assumed to use an ATmega8 here.
 *
 * \todo make timer functions inline, if possible/necessary
 *
 * \date Created: 28.11.2011 18:15:59
 * \author Matthias Kleemann
 **/



#ifndef TIMER_H_
#define TIMER_H_

#include "../config/timer_config.h"

// check prescaler settings - if not set, the timer is assumed off
#ifndef TIMER0_PRESCALER
//! default: TIMER 0 off
   #define TIMER0_PRESCALER      0
#endif

#ifndef TIMER1_PRESCALER
//! default: TIMER 1 off
   #define TIMER1_PRESCALER      0
#endif

#ifndef TIMER2_PRESCALER
//! default: TIMER 2 off
   #define TIMER2_PRESCALER      0
#endif

#ifndef TIMER1_COMPARE_VALUE
//! default: check available compare value setup and set to 16bit MAX
   #define TIMER1_COMPARE_VALUE  0xFFFF
#endif

#ifndef TIMER2_COMPARE_VALUE
//! default: check available compare value setup and set to 8bit MAX
   #define TIMER2_COMPARE_VALUE  0xFF
#endif

//! clear all prescaler bits to stop TIMER0 - just in case
#define TIMER0_STOP              (1 << CS02) | (1 << CS01) | (1 << CS00)
//! clear all prescaler bits to stop TIMER1 - just in case
#define TIMER1_STOP              (1 << CS12) | (1 << CS11) | (1 << CS10)
//! clear all prescaler bits to stop TIMER2 - just in case
#define TIMER2_STOP              (1 << CS22) | (1 << CS21) | (1 << CS20)

/***************************************************************************/
/* TYPEDEFINITION                                                          */
/***************************************************************************/

/**
 * @brief mode of timer initialization
 *
 * Define mode of timer (interrupt) behaviour. Four modes are available:
 * - overflow
 * - output compare (CTC)
 * - phase correct PWM
 * - fast PWM
 *
 * Note: Currently no output pin for PWM is set.
 */
typedef enum
{
   //! overflow
   TimerOverflow  = 0,
   //! output compare (CTC)
   TimerCompare   = 1,
   //! phase correct PWM
   TimerPwm       = 2,
   //! fast PWM
   TimerFastPwm   = 3
} eTimerMode;

/***************************************************************************/
/* TIMER 0                                                                 */
/***************************************************************************/

/**
 * @brief initializes Timer0 and stops
 *
 * There is no argument yet, since mode of Timer0 is overflow only at
 * ATmega8. This has to be adapted, if using another AVR.
 */
void initTimer0(void);

/**
 * @brief start Timer0
 */
void startTimer0(void);

/**
 * @brief stop Timer0
 */
void stopTimer0(void);


/***************************************************************************/
/* TIMER 1                                                                 */
/***************************************************************************/

/**
 * @brief initializes Timer1
 * @param mode of Timer1 (overflow, compare, pwm, ...)
 */
void initTimer1(eTimerMode mode);

/**
 * @brief start Timer1
 */
void startTimer1(void);

/**
 * @brief stop Timer1
 */
void stopTimer1(void);

/**
 * @brief restart Timer1 (set counter register to 0)
 */
void restartTimer1(void);

/**
 * @brief set timer counter register to value
 * @param value of timer counter
 */
void setTimer1Count(uint16_t value);

/***************************************************************************/
/* TIMER 2                                                                 */
/***************************************************************************/

/**
 * @brief initializes Timer2
 * @param mode of Timer2 (overflow, compare, pwm, ...)
 */
void initTimer2(eTimerMode mode);

/**
 * @brief start Timer2
 */
void startTimer2(void);

/**
 * @brief stop Timer2
 */
void stopTimer2(void);

/**
 * @brief restart Timer2, e.g. in compare mode
 */
void restartTimer2(void);

/**
 * @brief set timer counter register to value
 * @param value of timer counter
 */
void setTimer2Count(uint8_t value);


#endif /* TIMER_H_ */