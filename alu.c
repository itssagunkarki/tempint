/**************************************************************************//**
 *
 * @file alu.c
 *
 * @author Sagun Karki
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
    // Since it is a 16-bit integer, the most significant bit is the sign bit
    return (value >> 15) & 1;
}

/**
 * Determines whether two values are equal. Two values are considered equal if their bit vectors are identical.
 * @param value1 the first value for the comparison
 * @param value2 the second value for the comparison
 * @return 1 if the two arguments are equal; 0 otherwise
 */
bool equal(uint16_t value1, uint16_t value2) {
    // if both values are equal, then the XOR of the two values will be 0
    return !(value1 ^ value2);
}

/**
 * Determines whether two values are not equal. Two values are considered equal if their bit vectors are identical.
 * @param value1 the first value for the comparison
 * @param value2 the second value for the comparison
 * @return 0 if the two arguments are equal; 1 otherwise
 */
bool not_equal(uint16_t value1, uint16_t value2) {
    return !equal(value1, value2);
}

/**
 * Computes the logical inverse of the argument.
 * @param value the value to be inverted; 0 is considered <code>false</code>, and non-zero values are considered <code>true</code>
 * @return 1 if the argument is 0; 0 otherwise
 */
bool logical_not(uint32_t value) {
    return !value;
}

/**
 * Computes the logical conjunction of the arguments.
 * @param value1 the first operand for the conjunction; 0 is considered <code>false</code>, and non-zero values are considered <code>true</code>
 * @param value2 the second operand for the conjunction; 0 is considered <code>false</code>, and non-zero values are considered <code>true</code>
 * @return 1 if both arguments are <code>true</code>; 0 otherwise.
 */
bool logical_and(uint32_t value1, uint32_t value2) {
    return value1 && value2;
}

/**
 * Computes the logical disjunction of the arguments.
 * @param value1 the first operand for the disjunction; 0 is considered <code>false</code>, and non-zero values are considered <code>true</code>
 * @param value2 the second operand for the disjunction; 0 is considered <code>false</code>, and non-zero values are considered <code>true</code>
 * @return 1 if either (or both) argument is <code>true</code>; 0 otherwise.
 */
bool logical_or(uint32_t value1, uint32_t value2) {
    return value1 || value2;
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
    // Calculate the sum using bitwise XOR of a, b, and c_in
    bits.sum = bits.a ^ bits.b ^ bits.c_in;

    // Calculate the carry-out using bitwise OR of AND combinations of a, b, and c_in
    bits.c_out = (bits.a & bits.b) | (bits.b & bits.c_in) | (bits.a & bits.c_in);

    // Return the updated structure
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

    for (int i = 0; i < 32; i++) {
        one_bit_adder_t adder;
        adder.a = (value1 >> i) & 0x1;
        adder.b = (value2 >> i) & 0x1;
        adder.c_in = carry;

        // Perform one-bit addition
        adder = one_bit_full_addition(adder);

        // Update the sum and carry for the next iteration
        sum |= (adder.sum << i);
        carry = adder.c_out;
    }

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
    alu_result_t sum = {}; // Initialize sum with all fields set to 0

    // Calculate the sum using ripple carry addition
    uint32_t result = ripple_carry_addition((uint32_t)augend, (uint32_t)addend, 0);

    // Check for overflow when interpreted as unsigned integers
    sum.unsigned_overflow = ((result >> 16) != 0); // Check if the upper 16 bits are not all 0

    // Check for overflow when interpreted as signed integers
    int16_t signed_augend = (int16_t)augend;
    int16_t signed_addend = (int16_t)addend;
    int16_t signed_result = (int16_t)result;
    sum.signed_overflow = ((signed_augend > 0 && signed_addend > 0 && signed_result < 0) ||
                           (signed_augend < 0 && signed_addend < 0 && signed_result > 0));

    // Set the result field
    sum.result = (uint16_t)result;

    // Set divide_by_zero flag to 0
    sum.divide_by_zero = 0;

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
    alu_result_t difference = {};   // Initialize the result structure

    // Calculate the two's complement of the subtrahend
    // uint16_t twos_complement_subtrahend = ~subtrahend + 1;
    uint16_t twos_complement_subtrahend = add(~subtrahend, 1).result;

    // Perform addition of the minuend and the two's complement of the subtrahend
    difference = add(menuend, twos_complement_subtrahend);

    // Check for overflow when interpreted as unsigned integers
    difference.unsigned_overflow = (difference.result >> 16) != 0; // Check if the upper 16 bits are not all 0

    // Check for overflow when interpreted as signed integers
    difference.signed_overflow = (difference.result >> 15) != (menuend >> 15) && (difference.result >> 15) != (twos_complement_subtrahend >> 15);

    return difference;
}

/**
 * Determines whether the first value is strictly less than the second.
 * @param value1 the value on the left side of the inequality comparison
 * @param value2 the value on the right side of the inequality comparison
 * @return 1 if the first argument is strictly less than the second; 0 otherwise
 */
bool less_than(uint16_t value1, uint16_t value2) {
    return is_negative(subtract(value1, value2).result);
}

/**
 * Determines whether the first value is at most the second; that is, whether the first value is less than or equal to
 * the second.
 * @param value1 the value on the left side of the inequality comparison
 * @param value2 the value on the right side of the inequality comparison
 * @return 1 if the first argument is at most the second; 0 otherwise
 */
bool at_most(uint16_t value1, uint16_t value2) {
    return !less_than(value2, value1);
}

/**
 * Determines whether the first value is at least the second; that is, whether the first value is greater than or equal
 * to the second.
 * @param value1 the value on the left side of the inequality comparison
 * @param value2 the value on the right side of the inequality comparison
 * @return 1 if the first argument is at least the second; 0 otherwise
 */
bool at_least(uint16_t value1, uint16_t value2) {
    return !less_than(value1, value2);
}

/**
 * Determines whether the first value is strictly greater than the second.
 * @param value1 the value on the left side of the inequality comparison
 * @param value2 the value on the right side of the inequality comparison
 * @return 1 if the first argument is strictly greater than the second; 0 otherwise
 */
bool greater_than(uint16_t value1, uint16_t value2) {
    // inverse of value1 <= value2 is value1 > value2
    return less_than(value2, value1);
}

/**
 * Multiplies two 16-bit integers, producing a 32-bit integer. The second argument <i>must</i> be zero or a power of
 * two.
 * @param value the number to be multiplied
 * @param power_of_two the number that the first is to be multiplied by
 * @return the full product of the two arguments
 */
uint32_t multiply_by_power_of_two(uint16_t value, uint16_t power_of_two) {
    // Multiply the value by the power of two is equivalent to left shifting the value by the log base 2 of the power of two
    return value << lg(power_of_two);
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
    alu_result_t product = {};  // Initialize the result structure
    uint32_t result = 0;        // Initialize the result to 0
    int i = 0;                  // Initialize the bit index

    // Iterate through each bit of the multiplier
    while (multiplier) {
        // Check if the least significant bit of the multiplier is set
        if (multiplier & 1) {
            // Calculate the intermediate product by multiplying the multiplicand by 2^i
            uint32_t intermediate_product = multiplicand << i;
            // Add the intermediate product to the result
            result += intermediate_product;
        }
        
        // Right-shift the multiplier to move to the next bit
        multiplier >>= 1;
        // Increment the bit index
        i++;
    }

    // Store the lower 16 bits of the result in the product's result field
    product.result = result & 0xFFFF;
    // Store the upper 16 bits of the result in the product's supplemental_result field
    product.supplemental_result = result >> 16;
    // Set the divide_by_zero flag to 0
    product.divide_by_zero = 0;

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
        
    // Check if the divisor is zero using bitwise operations
    quotient.divide_by_zero = (add(~divisor, 1).result >> 15) & 1;
    
    // Determine the quotient and remainder using fast division by power of two
    // quotient.result = dividend >> lg(divisor);  // Quotient
    quotient.supplemental_result = dividend & (subtract(divisor, 1).result);  // Remainder
    
    // Set the divide_by_zero flag to 0
    quotient.divide_by_zero = 0;
    
    return quotient;  // Return the result
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
