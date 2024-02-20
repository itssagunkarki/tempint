/*                       *
 * DO NOT EDIT THIS FILE *
 *                       */

/**************************************************************************//**
 *
 * @file authoritative_default.c
 *
 * @author Christopher A. Bohn
 *
 * @brief Default implementation of arithmetic authoritative results, written
 *      in C. Does not detect signed/unsigned overflow.
 *
 ******************************************************************************/

/*
 * IntegerLab (c) 2018-23 Christopher A. Bohn
 *
 * Starter code licensed under the Apache License, Version 2.0
 * (http://www.apache.org/licenses/LICENSE-2.0).
 */

#include "authoritative_results.h"

#if defined DEFAULT_IMPLEMENTATION

void evaluate_addition(uint16_t operand1, uint16_t operand2, struct authoritative_result *result) {
    result->result = operand1 + operand2;
    result->z_flag = !result->result;
    result->s_flag = ((int16_t)(result->result) < 0);
}

void evaluate_subtraction(uint16_t operand1, uint16_t operand2, struct authoritative_result *result) {
    result->result = operand1 - operand2;
    result->z_flag = !result->result;
    result->s_flag = ((int16_t)(result->result) < 0);
}

void evaluate_unsigned_multiplication(uint16_t operand1, uint16_t operand2, struct authoritative_result *result) {
    result->result = operand1 * operand2;
    result->z_flag = !result->result;
    result->s_flag = ((int16_t)(result->result) < 0);
}

void evaluate_unsigned_division(uint16_t operand1, uint16_t operand2, struct authoritative_result *result) {
    result->result = operand1 / operand2;
    result->supplemental_result = operand1 % operand2;
    result->z_flag = !result->result;
    result->s_flag = ((int16_t)(result->result) < 0);
}

void evaluate_signed_multiplication(uint16_t operand1, uint16_t operand2, struct authoritative_result *result) {
    result->result = (uint16_t)((int16_t)operand1 * (int16_t)operand2);
    result->z_flag = !result->result;
    result->s_flag = ((int16_t)(result->result) < 0);
}

void evaluate_signed_division(uint16_t operand1, uint16_t operand2, struct authoritative_result *result) {
    result->result = (uint16_t)((int16_t)operand1 / (int16_t)operand2);
    result->supplemental_result = (uint16_t)((int16_t)operand1 % (int16_t)operand2);
    result->z_flag = !result->result;
    result->s_flag = ((int16_t)(result->result) < 0);
}

#endif //DEFAULT_IMPLEMENTATION