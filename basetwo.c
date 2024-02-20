/**************************************************************************//**
 *
 * @file basetwo.c
 *
 * @author Sagun Karki
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
    // Ensure exponent is within the valid range [0, 31]
    exponent &= 31;

    // Left shift 1 by the value of the exponent to compute 2^exponent
    return 1 << exponent;
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
        case 0x4: return 2;
        case 0x8: return 3;
        case 0x10: return 4;
        case 0x20: return 5;
        case 0x40: return 6;
        case 0x80: return 7;
        case 0x100: return 8;
        case 0x200: return 9;
        case 0x400: return 10;
        case 0x800: return 11;
        case 0x1000: return 12;
        case 0x2000: return 13;
        case 0x4000: return 14;
        case 0x8000: return 15;
        case 0x10000: return 16;
        case 0x20000: return 17;
        case 0x40000: return 18;
        case 0x80000: return 19;
        case 0x100000: return 20;
        case 0x200000: return 21;
        case 0x400000: return 22;
        case 0x800000: return 23;
        case 0x1000000: return 24;
        case 0x2000000: return 25;
        case 0x4000000: return 26;
        case 0x8000000: return 27;
        case 0x10000000: return 28;
        case 0x20000000: return 29;
        case 0x40000000: return 30;
        case 0x80000000: return 31;
        default :
            return -1;
    }
}