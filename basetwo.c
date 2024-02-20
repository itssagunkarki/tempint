/**************************************************************************//**
 *
 * @file basetwo.c
 *
 * @author (TYPE YOUR NAME HERE)
 * @author (TYPE YOUR PARTNER'S NAME HERE, IF APPLICABLE)
 *
 * @brief Functions that students must implement for IntegerLab to demonstrate
 * understanding of base two exponentiation and logarithms.
 *
 ******************************************************************************/

/*
 * IntegerLab assignment and starter code (c) 2018-22 Christopher A. Bohn
 * IntegerLab solution (c) the above-named student(s)
 */

#include "alu.h"

/**
 * Computes a power of two, specifically, the value of 2 raised to the power of <code>exponent</code>.
 * foo == exponentiate(bar) \<--> bar == lg(foo). The exponent must be a non-negative value strictly less than 32.
 * @param exponent the exponent to which 2 will be raised
 * @return 2 raised to the power of <code>exponent</code>
 */
uint32_t exponentiate(int exponent) {
    return 0;
}

/**
 * Determines the base-two logarithm of an integer that is a power of two.
 * foo == exponentiate(bar) \<--> bar == lg(foo). The argument must be a positive power of two.
 * @param power_of_two the value whose logarithm will be determined
 * @return base-2 logarithm of the argument
 */
int lg(uint32_t power_of_two) {
    switch (power_of_two) {
        case 0x1 :
            return 0;
        case 0x2 :
            return 1;
        default :
            return -1;
    }
}