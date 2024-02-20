/**************************************************************************//**
 *
 * @file alu.c
 *
 * @author (TYPE YOUR NAME HERE)
 * @author (TYPE YOUR PARTNER'S NAME HERE, IF APPLICABLE)
 *
 * @brief Functions that students must implement for IntegerLab to demonstrate
 * understanding of boolean logic and bit-limited integer arithmetic.
 *
 ******************************************************************************/

/*
 * IntegerLab assignment and starter code (c) 2018-22 Christopher A. Bohn
 * Integerlab solution (c) the above-named student(s)
 */

#include "alu.h"

/**
 * Determines whether a bit vector, when interpreted as a two's complement signed integer, is negative.
 * @param value the bit vector to be evaluated
 * @return 1 if the interpreted argument is less than zero; 0 otherwise
 */
bool is_negative(uint16_t value) {
    return false;
}

/**
 * Determines whether two values are equal. Two values are considered equal if their bit vectors are identical.
 * @param value1 the first value for the comparison
 * @param value2 the second value for the comparison
 * @return 1 if the two arguments are equal; 0 otherwise
 */
bool equal(uint16_t value1, uint16_t value2) {
    return false;
}

/**
 * Determines whether two values are not equal. Two values are considered equal if their bit vectors are identical.
 * @param value1 the first value for the comparison
 * @param value2 the second value for the comparison
 * @return 0 if the two arguments are equal; 1 otherwise
 */
bool not_equal(uint16_t value1, uint16_t value2) {
    return false;
}

/**
 * Computes the logical inverse of the argument.
 * @param value the value to be inverted; 0 is considered <code>false</code>, and non-zero values are considered <code>true</code>
 * @return 1 if the argument is 0; 0 otherwise
 */
bool logical_not(uint32_t value) {
    return false;
}

/**
 * Computes the logical conjunction of the arguments.
 * @param value1 the first operand for the conjunction; 0 is considered <code>false</code>, and non-zero values are considered <code>true</code>
 * @param value2 the second operand for the conjunction; 0 is considered <code>false</code>, and non-zero values are considered <code>true</code>
 * @return 1 if both arguments are <code>true</code>; 0 otherwise.
 */
bool logical_and(uint32_t value1, uint32_t value2) {
    return false;
}

/**
 * Computes the logical disjunction of the arguments.
 * @param value1 the first operand for the disjunction; 0 is considered <code>false</code>, and non-zero values are considered <code>true</code>
 * @param value2 the second operand for the disjunction; 0 is considered <code>false</code>, and non-zero values are considered <code>true</code>
 * @return 1 if either (or both) argument is <code>true</code>; 0 otherwise.
 */
bool logical_or(uint32_t value1, uint32_t value2) {
    return false;
}

/**
 * Performs binary addition for one bit position.
 * Given input bits a, b, and c_in, computes sum = a + b + c, with c_out (carry_out) as 0 or 1 depending on whether or
 * not the full sum fits into a single bit.
 * @param bits the <code>struct</code> with the input bits
 * @return The <code>struct</code> with the output (and input) bits
 */
one_bit_adder_t one_bit_full_addition(one_bit_adder_t bits) {
//    bits.sum = ...;
//    bits.c_out = ...;
    return bits;
}

/**
 * Uses 32 one-bit full adders (or, equivalently, uses 1 one-bit full adder 32 times) to add two 32-bit integers.
 * While a carry-in bit is provided for the least-significant bit, the carry-out bit from the most-significant bit is
 * not preserved (as it is not needed for any part of this assignment).
 * @param value1 the first number to be added
 * @param value2 the second number to be added
 * @param initial_carry_in The carry-in bit for the least-significant bit's adder
 * @return the 32-bit sum of the arguments
 */
uint32_t ripple_carry_addition(uint32_t value1, uint32_t value2, uint8_t initial_carry_in) {
    uint8_t carry = initial_carry_in & 0x1;
    uint32_t sum = 0;
    return sum;
}

/**
 * <p>Adds two 16-bit integers. The arguments are bit vectors that can be interpreted either as unsigned integers or as
 * signed integers. After computing the sum, this function determines whether overflow occurs when the bit vectors are
 * interpreted as unsigned integers, and this function also determines whether overflow occurs when the bit vectors are
 * interpreted as signed integers.</p>
 *
 * <p>This function does not alter the ALU's <code>supplemental_result</code> field, and it sets the ALU's
 * <code>divide_by_zero</code> flag to 0.</p>
 *
 * @param augend the number to be added to
 * @param addend the number to be added to the augend
 * @return the sum in the ALU's <code>result</code> field, and the <code>unsigned_overflow</code> and <code>signed_overflow</code> flags set appropriately
 */
alu_result_t add(uint16_t augend, uint16_t addend) {
    alu_result_t sum = {};          // empty initializer to suppress uninitialized variable warning in the starter code
    return sum;
}

/**
 * <p>Subtracts two 16-bit integers. The arguments are bit vectors that can be interpreted either as unsigned integers
 * or as signed integers. After computing the difference, this function determines whether overflow occurs when the bit
 * vectors are interpreted as unsigned integers, and this function also determines whether overflow occurs when the bit
 * vectors are interpreted as signed integers.</p>
 *
 * <p>This function does not alter the ALU's <code>supplemental_result</code> field, and it sets the ALU's
 * <code>divide_by_zero</code> flag to 0.</p>
 *
 * @param menuend the number to be subtracted from
 * @param subtrahend the number to be subtracted from the menuend
 * @return the difference in the ALU's <code>result</code> field, and the <code>unsigned_overflow</code> and <code>signed_overflow</code> flags set appropriately
 */
alu_result_t subtract(uint16_t menuend, uint16_t subtrahend) {
    alu_result_t difference = {};   // empty initializer to suppress uninitialized variable warning in the starter code
    return difference;
}

/**
 * Determines whether the first value is strictly less than the second.
 * @param value1 the value on the left side of the inequality comparison
 * @param value2 the value on the right side of the inequality comparison
 * @return 1 if the first argument is strictly less than the second; 0 otherwise
 */
bool less_than(uint16_t value1, uint16_t value2) {
    return false;
}

/**
 * Determines whether the first value is at most the second; that is, whether the first value is less than or equal to
 * the second.
 * @param value1 the value on the left side of the inequality comparison
 * @param value2 the value on the right side of the inequality comparison
 * @return 1 if the first argument is at most the second; 0 otherwise
 */
bool at_most(uint16_t value1, uint16_t value2) {
    return false;
}

/**
 * Determines whether the first value is at least the second; that is, whether the first value is greater than or equal
 * to the second.
 * @param value1 the value on the left side of the inequality comparison
 * @param value2 the value on the right side of the inequality comparison
 * @return 1 if the first argument is at least the second; 0 otherwise
 */
bool at_least(uint16_t value1, uint16_t value2) {
    return false;
}

/**
 * Determines whether the first value is strictly greater than the second.
 * @param value1 the value on the left side of the inequality comparison
 * @param value2 the value on the right side of the inequality comparison
 * @return 1 if the first argument is strictly greater than the second; 0 otherwise
 */
bool greater_than(uint16_t value1, uint16_t value2) {
    return false;
}

/**
 * Multiplies two 16-bit integers, producing a 32-bit integer. The second argument <i>must</i> be zero or a power of
 * two.
 * @param value the number to be multiplied
 * @param power_of_two the number that the first is to be multiplied by
 * @return the full product of the two arguments
 */
uint32_t multiply_by_power_of_two(uint16_t value, uint16_t power_of_two) {
    return 0;
}

/**
 * <p>Multiplies two 16-bit integers. The arguments are bit vectors that are interpreted as unsigned integers. The lower
 * 16 bits of the full product are placed in the ALU's <code>result</code> field, and the upper 16 bits of the full
 * product are placed in the ALU's <code>supplemental_result</code> field.</p>
 *
 * <p>This function sets the ALU's <code>divide_by_zero</code> flag to 0 but it does not alter the ALU's
 * <code>unsigned_overflow</code> and <code>signed_overflow</code> flags.</p>
 *
 * @param multiplicand the number to be multiplied
 * @param multiplier the number that the first is to be multiplied by
 * @return the product in the ALU's <code>result</code> and <code>supplemental_result</code> fields
 */
alu_result_t unsigned_multiply(uint16_t multiplicand, uint16_t multiplier) {
    alu_result_t product = {};      // empty initializer to suppress uninitialized variable warning in the starter code
    return product;
}

/**
 * <p>Divides two 16-bit integers. The arguments are bit vectors that are interpreted as unsigned integers.</p>
 *
 * <p>The divisor <i>must</i> be zero or a power of two.</p>
 *
 * <p>If the divisor is non-zero, the quotient is placed in the ALU's <code>result</code> field, the modulus (or
 * remainder) is placed in the ALU's <code>supplemental_result</code> field, and the <code>divide_by_zero</code> flag
 * is set to 0.</p>
 *
 * <p>If the divisor is zero, the ALU's <code>divide_by_zero</code> flag is set to 1 and no guarantees are made about
 * the contents of the <code>result</code> and <code>supplemental_result</code> fields.</p>
 *
 * <p>Regardless, the ALU's <code>unsigned_overflow</code> and <code>signed_overflow</code> flags are not altered.</p>
 *
 * @param dividend the number to be divided
 * @param divisor the number that divides the first
 * @return the ALU's <code>divide_by_zero</code> flag set appropriately, and the quotient in the ALU's <code>result</code> field and the remainder in the <code>supplemental_result</code> field when these are mathematically defined
 */
alu_result_t unsigned_divide(uint16_t dividend, uint16_t divisor) {
    alu_result_t quotient = {};     // empty initializer to suppress uninitialized variable warning in the starter code
    return quotient;
}

/*
 * SIGNED_MULTIPLY AND SIGNED_DIVIDE ARE FOR BONUS CREDIT.
 * YOU ARE NOT REQUIRED AT ATTEMPT THEM.
 */

/**
 * <p>Multiplies two 16-bit integers. The arguments are bit vectors that are interpreted as signed integers. The lower
 * 16 bits of the full product are placed in the ALU's <code>result</code> field, and the upper 16 bits of the full
 * product are placed in the ALU's <code>supplemental_result</code> field.</p>
 *
 * <p>This function sets the ALU's <code>divide_by_zero</code> flag to 0 but it does not alter the ALU's
 * <code>unsigned_overflow</code> and <code>signed_overflow</code> flags.</p>
 *
 * @param multiplicand the number to be multiplied
 * @param multiplier the number that the first is to be multiplied by
 * @return the product in the ALU's <code>result</code> and <code>supplemental_result</code> fields
 */
alu_result_t signed_multiply(uint16_t multiplicand, uint16_t multiplier) {
    alu_result_t product = {};      // empty initializer to suppress uninitialized variable warning in the starter code
    return product;
}

/**
 * <p>Divides two 16-bit integers. The arguments are bit vectors that are interpreted as signed integers.</p>
 *
 * <p>The divisor <i>must</i> be zero or a power of two.</p>
 *
 * <p>If the divisor is non-zero, the quotient is placed in the ALU's <code>result</code> field, the modulus (or
 * remainder) is placed in the ALU's <code>supplemental_result</code> field, and the <code>divide_by_zero</code> flag
 * is set to 0.</p>
 *
 * <p>If the divisor is zero, the ALU's <code>divide_by_zero</code> flag is set to 1 and no guarantees are made about
 * the contents of the <code>result</code> and <code>supplemental_result</code> fields.</p>
 *
 * <p>Regardless, the ALU's <code>unsigned_overflow</code> and <code>signed_overflow</code> flags are not altered.</p>
 *
 * @param dividend the number to be divided
 * @param divisor the number that divides the first
 * @return the ALU's <code>divide_by_zero</code> flag set appropriately, and the quotient in the ALU's <code>result</code> field and the remainder in the <code>supplemental_result</code> field when these are mathematically defined
 */
alu_result_t signed_divide(uint16_t dividend, uint16_t divisor) {
    alu_result_t quotient = {};     // empty initializer to suppress uninitialized variable warning in the starter code
    return quotient;
}
