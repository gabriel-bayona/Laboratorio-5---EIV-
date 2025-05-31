/*********************************************************************************************************************
Copyright (c) 2025, Bayona Franco Gabriel <gabrielbayona19@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*********************************************************************************************************************/
/** @file calculator.h
 * @brief Declaración de una calculadora simple que soporta operaciones básicas.
 * @author Bayona, Franco Gabriel <
 *
 *
 * */

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

/* === Headers files inclusions ==================================================================================== */

#include <stdbool.h>
#include <stdint.h>

/* === Header for C++ compatibility ================================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =================================================================================== */

/* === Public data type declarations =============================================================================== */

/** Tipo de datos para el objeto calculadora */
typedef struct calculator_s * calculator_t;

/** Tipo de datos para las funciones de operación */
typedef int (*operation_func_t)(int, int);

/* === Public variable declarations ================================================================================ */

/* === Public function declarations ================================================================================ */

/*********************************************************************************************************************
 * @brief Crea una nueva calculadora
 * @return Puntero a la nueva calculadora o NULL si no se pudo crear
 *********************************************************************************************************************/
calculator_t CalculatorCreate(void);

/*********************************************************************************************************************
 * @brief Agrega una operación a la calculadora
 * @param calculator Puntero a la calculadora
 * @param operator Carácter que representa el operador de la operación
 * @param function Función que implementa la operación
 * @return true si se agregó correctamente, false en caso contrario
 *********************************************************************************************************************/
bool CalculatorAddOperation(calculator_t calculator, char operator, operation_func_t operation);

/*********************************************************************************************************************
 * @brief Calcula el resultado de una expresión matemática
 * @param calculator Puntero a la calculadora
 * @param expression Cadena de caracteres que representa la expresión matemática
 * @return Resultado de la operación o 0 si no se pudo calcular (por ejemplo, division por cero)
 *********************************************************************************************************************/
int CalculatorCalculate(calculator_t calculator, const char * expression);

/*********************************************************************************************************************
 * @brief Funcion para calcular la suma de dos números
 * @param a Primer sumando
 * @param b Segundo sumando
 * @return Resultado de la suma
 *********************************************************************************************************************/
int OperationAdd(int a, int b);

/*********************************************************************************************************************
 * @brief Funciones para calcular la resta de dos números
 * @param a Minuendo
 * @param b Sustraendo
 * @return Resultado de la resta
 *********************************************************************************************************************/
int OperationSubtract(int a, int b);

/*********************************************************************************************************************
 * @brief Funciones para calcular el producto de dos números
 * @param a Primer factor
 * @param b Segundo factor
 * @return Resultado de la multiplicación
 *********************************************************************************************************************/
int operationMultiply(int a, int b);

/*********************************************************************************************************************
 * @brief Funciones para calcular la división de dos números
 * Nota: Si el divisor es 0, se retorna 0 para evitar división por cero.
 * @param a Dividendo
 * @param b Divisor
 * @return Resultado de la operación
 *********************************************************************************************************************/
int operationDivide(int a, int b);
/* === End of conditional blocks =================================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* CALCULATOR_H_ */
