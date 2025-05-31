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

/* === Headers files inclusions ==================================================================================== */

#include "calculator.h"
#include <stdio.h>

/* === Macros definitions ========================================================================================== */

/* === Private data type declarations ============================================================================== */

/* === Private function declarations =============================================================================== */

/* === Private variable definitions ================================================================================ */

/* === Public variable definitions ================================================================================= */

/* === Private function definitions ================================================================================ */

/* === Public function implementation ============================================================================== */

int main(void) {
    static const char addition[] = "2+3";
    static const char subtraction[] = "5-3";
    static const char multiplication[] = "5*2";
    static const char division[] = "10/2";

    calculator_t calculadora = CalculatorCreate();
    CalculatorAddOperation(calculadora, '+', OperationAdd);
    CalculatorAddOperation(calculadora, '-', OperationSubtract);
    CalculatorAddOperation(calculadora, '*', operationMultiply);
    CalculatorAddOperation(calculadora, '/', operationDivide);

    printf("Calculator\r\n");
    printf("==========\r\n");
    printf("%s = %i\r\n", addition, CalculatorCalculate(calculadora, addition));
    printf("%s = %i\r\n", subtraction, CalculatorCalculate(calculadora, subtraction));
    printf("%s = %i\r\n", multiplication, CalculatorCalculate(calculadora, multiplication));
    printf("%s = %i\r\n", division, CalculatorCalculate(calculadora, division));

    return 0;
}

/* === End of documentation ======================================================================================== */
