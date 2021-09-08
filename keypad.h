/**
 * @file keypad.h
 * @author Luigi Verolla <<mailto:luverolla@outlook.com>>
 *
 * @copyright This project is released under the [Apache 2.0 License](http://www.apache.org/licenses/LICENSE-2.0.html)
 *
 * This contains method and data structures for the keypad driver
 *
 * This driver is meant to work with all keypad that adopts the system in which:
 *  - rows are set as output and columns as input
 *  - rows are enabled one at time
 *  - columns read values are related to current enabled row
 *
 * Number of rows and columns, as well as character matrix,
 * are set through a configuration object that is passed as argument of each methods
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "hal.h"

/**
 * Empty char constant. This tells that user has pressed no key on keypad
 */
#define KEYPAD_NOCHAR       '\0'

/**
 * Keypad configuration object
 *
 * @param *rows Array of GPIO lines that will be used as rows (output lines)
 * @param *cols Array of GPIO lines that will be used as columns (input lines)
 * @param **chars Characters matrix ordered as keys on keypad
 */
typedef struct
{
  ioline_t *rows;
  ioline_t *cols;
  uint8_t **chars;
} Keypad;

/**
 * Initialize keypad with given configuration
 *
 * @param *obj Pointer to configuration object
 */
void kpInit(Keypad* obj);

/**
 * Enable the k-th row of keypad
 *
 * Disables all other rows
 * Indeces count starts from zero.
 * Returns immediately if index goes over rows array's size
 *
 * @param *obj Pointer to configuration object
 */
void kpEnableRow(Keypad* obj, uint32_t k);

/**
 * Read key pressed by user, as char.
 *
 * If key is pressed, stores position in pointers passed as arguments.
 * If no key is pressed, then returns #KEYPAD_NOCHAR, and pointers are null
 *
 * @param *obj Pointer to configuration object
 * @param *m Pointer to row position
 * @param *n Pointer to column position
 *
 * @returns char related to pressed key, or #KEYPAD_NOCHAR
 */
uint8_t kpRead(Keypad* obj, uint32_t* m, uint32_t* n);

/**
 * Read key pressed by user, as char.
 *
 * If no key is pressed, then returns #KEYPAD_NOCHAR
 *
 * @param *obj Pointer to configuration object
 *
 * @returns char related to pressed key, or #KEYPAD_NOCHAR
 */
uint8_t kpRead(Keypad* obj);

#endif /* KEYPAD_H_ */
