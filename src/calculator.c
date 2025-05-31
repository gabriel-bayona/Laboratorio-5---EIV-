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

/** @file calculator.c
 * @brief Implementación de una calculadora simple que soporta operaciones básicas.
 * @author Bayona Franco Gabriel <
 *
/* === Headers files inclusions ==================================================================================== */

#include "calculator.h"

#include <stdlib.h>
#include <string.h>
/* === Macros definitions ========================================================================================== */

#ifndef OPERATIONS_MAX
#define OPERATIONS_MAX 16
#endif

/* === Private data type declarations ============================================================================== */

/** @brief Estructura para una operacion de la calculadora */
typedef struct operation_s * operation_t;

/** @brief Tipo de función para las operaciones de la calculadora */
struct operation_s {
    char operator;
    operation_func_t function;
    operation_t next;
};

/** @brief Estructura para la calculadora */
struct calculator_s {
    operation_t operations;
};

/* === Private function declarations =============================================================================== */

/** @brief Busca una operación en la calculadora por su operador
 *  @param calculator Puntero a la calculadora
 *  @param operator Carácter que representa el operador de la operación
 *  @return Puntero a la operación encontrada o NULL si no se encuentra
 */
static operation_t FindOperation(calculator_t calculator, char operator);

/* === Private variable definitions ================================================================================ */

/* === Public variable definitions ================================================================================= */

/* === Private function definitions ================================================================================ */

/**
 * @brief Busca una operación en la calculadora por su operador
 * @param calculator Puntero a la calculadora
 * @param operator Carácter que representa el operador de la operación
 * @return Puntero a la operación encontrada o NULL si no se encuentra
 */
static operation_t FindOperation(calculator_t calculator, char operator) {
    operation_t current = calculator->operations;
    while (current != NULL) {
        if (current->operator == operator) {
            return current;
        }

        current = current->next;
    }

    return NULL;
}
/* === Public function implementation ============================================================================== */

/*********************************************************************************************************************
 * @brief Crea una nueva calculadora
 * @return Puntero a la nueva calculadora o NULL si no se pudo crear
 *********************************************************************************************************************/
calculator_t CalculatorCreate(void) {
    calculator_t self = malloc(sizeof(struct calculator_s));
    if (self) {
        self->operations = NULL;
    }
    return self;
}

/*********************************************************************************************************************
 * @brief Agrega una operación a la calculadora
 * @param calculator Puntero a la calculadora
 * @param operator Carácter que representa el operador de la operación
 * @param function Función que implementa la operación
 * @return true si se agregó correctamente, false en caso contrario
 *********************************************************************************************************************/

bool CalculatorAddOperation(calculator_t calculator, char operator, operation_func_t function) {
    if (!calculator || !function || FindOperation(calculator, operator)) {
        return false;
    }

    operation_t operation = malloc(sizeof(struct operation_s));
    if (operation) {
        operation->operator = operator;
        operation->function = function;
        operation->next = calculator->operations;
        calculator->operations = operation;
        return true;
    }
    return false;
}

/*********************************************************************************************************************
 * @brief Calcula el resultado de una expresión matemática
 * @param calculator Puntero a la calculadora
 * @param expression Cadena de caracteres que representa la expresión matemática
 * @return Resultado de la operación o 0 si no se pudo calcular
 *********************************************************************************************************************/
int CalculatorCalculate(calculator_t calculator, const char * expression) {
    int a = 0, b = 0;
    char operator = 0;
    int result = 0;

    if (!calculator || !expression) {
        return 0;
    }

    for (size_t i = 0; i < strlen(expression); i++) {
        if ((expression[i] < '0') || (expression[i] > '9')) {
            operator = expression[i];
            a = atoi(expression);
            b = atoi(expression + i + 1);
            break;
        }
    }

    operation_t operation = FindOperation(calculator, operator);

    if (operation) {
        result = operation->function(a, b);
    }
    return result;
}

/*********************************************************************************************************************
 * @brief Funciones de operaciones matemáticas
 * @param a Primer operando
 * @param b Segundo operando
 * @return Resultado de la operación
 *********************************************************************************************************************/
int OperationAdd(int a, int b) {
    return a + b;
}

/*********************************************************************************************************************
 * @brief Funciones de operaciones matemáticas
 * @param a Primer operando
 * @param b Segundo operando
 * @return Resultado de la operación
 *********************************************************************************************************************/
int OperationSubtract(int a, int b) {
    return a - b;
}

/*********************************************************************************************************************
 * @brief Funciones de operaciones matemáticas
 * @param a Primer operando
 * @param b Segundo operando
 * @return Resultado de la operación
 *********************************************************************************************************************/
int operationDivide(int a, int b) {
    return b != 0 ? a / b : 0;
}

/*********************************************************************************************************************
 * @brief Funciones de operaciones matemáticas
 * @param a Primer operando
 * @param b Segundo operando
 * @return Resultado de la operación
 *********************************************************************************************************************/
int operationMultiply(int a, int b) {
    return a * b;
}
/* === End of documentation ======================================================================================== */