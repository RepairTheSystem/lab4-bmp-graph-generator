#ifndef DIGITSDRAWER_H
#define DIGITSDRAWER_H

#include <cstring> // [comment] Неуверен, насколько корректно так резко переходить на c-шные строки
#include <stdexcept> // [comment] когда во всей проге они c++-шные
#include <string>

/* Class for drawing single digits. Uses functors for drawing pixels,
 * because of this it can be used for any images classes,
 * that provide a function for drawing pixel in pos (x, y)
 */
class DigitsDrawer {
   public:
    // throws exception if the specified number is not a digit
    template <typename T_draw_pixel>
    static void draw_digit(size_t x, size_t y, int digit, T_draw_pixel draw_pixel) {
        switch (digit) {
            case 0:
                draw_zero(x, y, draw_pixel);
                break;
            case 1:
                draw_one(x, y, draw_pixel);
                break;
            case 2:
                draw_two(x, y, draw_pixel);
                break;
            case 3:
                draw_three(x, y, draw_pixel);
                break;
            case 4:
                draw_four(x, y, draw_pixel);
                break;
            case 5:
                draw_five(x, y, draw_pixel);
                break;
            case 6:
                draw_six(x, y, draw_pixel);
                break;
            case 7:
                draw_seven(x, y, draw_pixel);
                break;
            case 8:
                draw_eight(x, y, draw_pixel);
                break;
            case 9:
                draw_nine(x, y, draw_pixel);
                break;
            default:
                throw std::runtime_error("digit should be in segment [0..9], but provided " +
                                         std::to_string(digit));
        }
    }

   private:
    // functions for drawing every digit. The style of digits is similar to electronic watch

    template <typename T_draw_pixel>
    static void draw_zero(size_t x, size_t y, T_draw_pixel draw_pixel) noexcept {
        for (int i = 0; i < 6; i++) { // [??comment] хардкод размеров
            draw_pixel(x, y + i);
            draw_pixel(x + 10, y + i);
        }
        for (int i = 0; i < 11; i++) {
            draw_pixel(x + i, y);
            draw_pixel(x + i, y + 5);
        }
    }

    template <typename T_draw_pixel>
    static void draw_one(size_t x, size_t y, T_draw_pixel draw_pixel) noexcept {
        for (int i = 0; i < 11; i++) {
            draw_pixel(x + i, y + 2);
        }
    }

    template <typename T_draw_pixel>
    static void draw_two(size_t x, size_t y, T_draw_pixel draw_pixel) noexcept {
        for (int i = 0; i < 6; i++) {
            draw_pixel(x, y + i);
            draw_pixel(x + 5, y + i);
            draw_pixel(x + 10, y + i);
        }
        for (int i = 0; i < 5; i++) {
            draw_pixel(x + i, y);
            draw_pixel(x + i + 5, y + 5);
        }
    }

    template <typename T_draw_pixel>
    static void draw_three(size_t x, size_t y, T_draw_pixel draw_pixel) noexcept {
        for (int i = 0; i < 6; i++) {
            draw_pixel(x, y + i);
            draw_pixel(x + 5, y + i);
            draw_pixel(x + 10, y + i);
        }
        for (int i = 0; i < 5; i++) {
            draw_pixel(x + i + 5, y + 5);
            draw_pixel(x + i, y + 5);
        }
    }

    template <typename T_draw_pixel>
    static void draw_four(size_t x, size_t y, T_draw_pixel draw_pixel) noexcept {
        for (int i = 0; i < 6; i++) {
            draw_pixel(x + 5, y + i);
        }
        draw_pixel(x + 10, y + 5);
        draw_pixel(x + 10, y);
        for (int i = 0; i < 5; i++) {
            draw_pixel(x + i + 5, y);
            draw_pixel(x + i, y + 5);
            draw_pixel(x + i + 5, y + 5);
        }
    }

    template <typename T_draw_pixel>
    static void draw_five(size_t x, size_t y, T_draw_pixel draw_pixel) noexcept {
        for (int i = 0; i < 6; i++) {
            draw_pixel(x, y + i);
            draw_pixel(x + 5, y + i);
            draw_pixel(x + 10, y + i);
        }
        for (int i = 0; i < 5; i++) {
            draw_pixel(x + i + 5, y);
            draw_pixel(x + i, y + 5);
        }
    }

    template <typename T_draw_pixel>
    static void draw_six(size_t x, size_t y, T_draw_pixel draw_pixel) noexcept {
        for (int i = 0; i < 6; i++) {
            draw_pixel(x, y + i);
            draw_pixel(x + 5, y + i);
            draw_pixel(x + 10, y + i);
        }
        for (int i = 0; i < 5; i++) {
            draw_pixel(x + i + 5, y);
            draw_pixel(x + i, y + 5);
            draw_pixel(x + i, y);
        }
    }

    template <typename T_draw_pixel>
    static void draw_seven(size_t x, size_t y, T_draw_pixel draw_pixel) noexcept {
        for (int i = 0; i < 11; i++) {
            draw_pixel(x + i, y + 5);
        }
        for (int i = 0; i < 6; i++) {
            draw_pixel(x + 10, y + i);
        }
    }

    template <typename T_draw_pixel>
    static void draw_eight(size_t x, size_t y, T_draw_pixel draw_pixel) noexcept {
        for (int i = 0; i < 6; i++) {
            draw_pixel(x, y + i);
            draw_pixel(x + 5, y + i);
            draw_pixel(x + 10, y + i);
        }
        for (int i = 0; i < 5; i++) {
            draw_pixel(x + i + 5, y);
            draw_pixel(x + i, y + 5);
            draw_pixel(x + i + 5, y + 5);
            draw_pixel(x + i, y);
        }
    }

    template <typename T_draw_pixel>
    static void draw_nine(size_t x, size_t y, T_draw_pixel draw_pixel) noexcept {
        for (int i = 0; i < 6; i++) {
            draw_pixel(x, y + i);
            draw_pixel(x + 5, y + i);
            draw_pixel(x + 10, y + i);
        }
        for (int i = 0; i < 5; i++) {
            draw_pixel(x + i + 5, y);
            draw_pixel(x + i, y + 5);
            draw_pixel(x + i + 5, y + 5);
        }
    }
};

#endif  // DIGITSDRAWER_H
