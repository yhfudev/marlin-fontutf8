/**
 * @file    lcdprint.h
 * @brief   LCD print api
 * @author  Yunhui Fu (yhfudev@gmail.com)
 * @version 1.0
 * @date    2016-08-19
 * @copyright GPL/BSD
 */
#ifndef _LCDPRINT_H
#define _LCDPRINT_H

#include "Marlin.h"

#include "fontutils.h"

#if DISABLED(DOGLCD)
#define _UxGT(a) a
#else
#include "u8g_fontutf8.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

int lcd_glyph_height(void);

int lcd_print_uchar (wchar_t c, pixel_len_t max_length);

/**
 * @brief Draw a UTF-8 string
 *
 * @param utf8_str : the UTF-8 string
 * @param max_length : the pixel length of the string allowed (or number of slots in HD44780)
 *
 * @return the avanced pixels
 *
 * Draw a UTF-8 string
 */
int lcd_printstr (const char * utf8_str, pixel_len_t max_length);

/**
 * @brief Draw a ROM UTF-8 string
 *
 * @param utf8_str_P : the ROM UTF-8 string
 * @param max_length : the pixel length of the string allowed (or number of slots in HD44780)
 *
 * @return the avanced pixels
 *
 * Draw a ROM UTF-8 string
 */
int lcd_printstr_P (const char * utf8_str_P, pixel_len_t max_length);

void lcd_moveto (int col, int row);

#ifdef __cplusplus
}
#endif

// char lcd_print(char c);
// char lcd_print(const char* str);
// char lcd_printPGM(const char* str);
#define lcd_printPGM(str) lcd_printstr_P(str, PIXEL_LEN_NOLIMIT)

inline int lcd_print(const char* str) {
    return lcd_printstr  (str, PIXEL_LEN_NOLIMIT);
}

inline int lcd_print_wchar(wchar_t c) {
    return lcd_print_uchar (c, PIXEL_LEN_NOLIMIT);
}

#endif // _LCDPRINT_H
