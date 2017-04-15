#ifndef chord_H_
#define chord_H_
 
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include <avr/pgmspace.h>
 
#define chord_NUM_CELLS 7716
#define chord_SAMPLERATE 16384
 
const int8_t __attribute__((section(".progmem.data"))) chord_DATA [] = {-2, -4,
-4, -5, -5, -6, -6, -7, -7, -8, -8, -8, -8, -8, -8, -9, -9, -9, -9, -8, -8, -8,
-8, -7, -7, -7, -6, -6, -5, -5, -4, -4, -3, -3, -2, -2, -1, -1, 0, 0, 0, 1, 1,
2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 8, 9, 9, 10, 10, 11, 12, 12, 13, 13, 14, 15,
15, 15, 16, 16, 17, 17, 17, 17, 18, 18, 18, 18, 18, 18, 17, 17, 17, 16, 16, 15,
15, 14, 13, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 0, 0, -1, -1, -2, -2,
-3, -4, -5, -5, -6, -7, -8, -9, -10, -11, -11, -12, -13, -14, -14, -15, -15,
-16, -16, -16, -16, -16, -16, -16, -16, -16, -16, -15, -15, -15, -14, -14, -13,
-13, -12, -12, -11, -10, -10, -9, -9, -8, -7, -7, -6, -6, -5, -4, -4, -3, -3,
-2, -2, -1, 0, 0, 0, 0, 1, 1, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 9, 9, 9, 9, 9,
11, 11, 12, 14, 17, 21, 25, 29, 32, 35, 38, 40, 42, 43, 42, 41, 40, 38, 35, 32,
28, 24, 20, 16, 12, 9, 5, 1, -1, -4, -8, -10, -13, -15, -17, -19, -20, -20, -20,
-20, -18, -17, -15, -12, -10, -7, -5, -4, -3, -2, -3, -3, -4, -6, -7, -9, -10,
-11, -11, -12, -12, -12, -12, -13, -13, -14, -14, -14, -15, -15, -16, -16, -17,
-17, -17, -17, -18, -18, -18, -17, -17, -17, -16, -16, -15, -15, -15, -15, -14,
-14, -14, -14, -13, -13, -12, -11, -11, -10, -9, -9, -9, -8, -8, -7, -6, -4, -2,
0, 4, 9, 14, 20, 26, 31, 36, 39, 42, 44, 46, 46, 45, 44, 43, 40, 37, 34, 31, 27,
22, 18, 13, 8, 2, -3, -8, -14, -20, -26, -31, -35, -39, -42, -43, -44, -43, -41,
-38, -34, -29, -23, -17, -10, -3, 3, 10, 17, 23, 29, 35, 40, 46, 51, 57, 62, 67,
70, 74, 76, 77, 76, 75, 71, 67, 61, 53, 45, 35, 25, 14, 3, -8, -20, -31, -41,
-51, -60, -69, -76, -83, -88, -92, -96, -98, -99, -99, -97, -95, -91, -86, -80,
-73, -65, -57, -49, -41, -33, -25, -18, -11, -4, 1, 7, 14, 20, 27, 34, 40, 46,
51, 55, 58, 60, 61, 61, 60, 58, 56, 53, 50, 46, 42, 38, 33, 29, 24, 19, 14, 8,
3, 0, -5, -9, -13, -17, -20, -23, -25, -26, -27, -27, -27, -25, -23, -20, -16,
-13, -9, -6, -3, -1, 0, 1, 2, 2, 3, 4, 6, 8, 11, 14, 18, 22, 26, 30, 33, 36, 38,
40, 41, 42, 43, 43, 43, 42, 41, 40, 38, 35, 33, 30, 27, 23, 19, 15, 11, 6, 1,
-2, -7, -12, -17, -22, -26, -31, -35, -38, -42, -44, -47, -49, -51, -52, -53,
-53, -53, -52, -50, -47, -43, -38, -32, -26, -19, -11, -4, 1, 7, 12, 17, 20, 23,
25, 26, 27, 26, 26, 24, 22, 19, 16, 12, 8, 3, -1, -6, -12, -17, -22, -27, -31,
-35, -37, -39, -40, -40, -39, -38, -35, -31, -27, -22, -17, -12, -6, -1, 3, 8,
13, 17, 22, 26, 30, 35, 40, 45, 49, 53, 57, 60, 62, 63, 63, 61, 59, 55, 50, 45,
38, 32, 26, 19, 12, 6, 0, -4, -9, -13, -17, -20, -23, -24, -26, -27, -27, -27,
-26, -25, -23, -20, -17, -13, -9, -4, 0, 3, 7, 11, 13, 15, 16, 17, 17, 17, 16,
16, 15, 15, 14, 13, 12, 10, 7, 4, 0, -3, -7, -12, -16, -20, -23, -26, -28, -30,
-32, -33, -34, -34, -35, -35, -34, -34, -33, -33, -32, -30, -29, -27, -25, -23,
-21, -18, -14, -11, -7, -4, 0, 3, 6, 8, 10, 11, 12, 11, 11, 10, 10, 9, 10, 11,
12, 13, 15, 17, 18, 19, 20, 20, 19, 19, 18, 16, 14, 12, 10, 8, 5, 3, 1, 0, -2,
-4, -6, -8, -9, -11, -12, -13, -14, -15, -16, -16, -17, -17, -17, -17, -15, -13,
-11, -8, -4, 0, 4, 8, 12, 17, 21, 25, 29, 34, 38, 43, 48, 54, 59, 64, 68, 72,
74, 76, 76, 76, 74, 70, 66, 61, 54, 47, 39, 30, 21, 11, 0, -10, -21, -32, -43,
-55, -65, -75, -85, -93, -100, -106, -110, -112, -112, -111, -107, -103, -96,
-89, -80, -70, -61, -51, -41, -31, -21, -12, -3, 4, 13, 21, 30, 39, 47, 55, 62,
68, 73, 77, 79, 80, 79, 77, 73, 68, 62, 56, 49, 42, 34, 26, 19, 12, 4, -2, -8,
-15, -21, -26, -31, -36, -40, -44, -47, -49, -50, -51, -51, -50, -48, -45, -42,
-38, -34, -29, -25, -20, -16, -12, -8, -4, 0, 3, 7, 11, 15, 19, 23, 27, 31, 34,
37, 39, 41, 42, 44, 45, 45, 46, 46, 46, 46, 46, 45, 44, 43, 42, 40, 38, 36, 34,
31, 28, 25, 22, 19, 16, 13, 9, 6, 3, 0, -2, -5, -8, -11, -14, -18, -22, -26,
-31, -37, -42, -47, -51, -55, -57, -58, -58, -56, -54, -50, -46, -42, -38, -34,
-30, -26, -23, -20, -17, -14, -12, -9, -7, -5, -3, -1, 0, 1, 2, 3, 4, 4, 4, 3,
3, 1, 0, 0, -2, -3, -4, -4, -4, -4, -2, -1, 0, 2, 5, 7, 8, 10, 11, 13, 14, 15,
17, 19, 22, 25, 27, 30, 33, 35, 36, 36, 36, 35, 33, 31, 28, 25, 22, 17, 13, 8,
3, -2, -8, -13, -19, -25, -30, -35, -40, -43, -46, -48, -49, -49, -47, -45, -42,
-38, -32, -26, -19, -11, -3, 5, 13, 21, 29, 37, 44, 50, 55, 60, 64, 68, 72, 75,
78, 79, 80, 80, 79, 76, 72, 67, 60, 52, 42, 32, 22, 11, 0, -10, -21, -31, -40,
-49, -56, -63, -68, -73, -76, -79, -81, -83, -83, -83, -82, -80, -77, -74, -69,
-64, -58, -52, -45, -38, -30, -23, -15, -9, -3, 2, 7, 11, 14, 18, 21, 24, 27,
31, 34, 37, 39, 42, 43, 44, 45, 44, 44, 42, 40, 38, 35, 32, 29, 26, 23, 19, 15,
11, 8, 4, 0, -3, -7, -11, -15, -18, -21, -24, -26, -28, -28, -29, -29, -28, -27,
-26, -24, -22, -21, -19, -17, -16, -14, -13, -11, -8, -5, -2, 2, 6, 12, 18, 24,
29, 35, 40, 44, 47, 50, 52, 53, 54, 54, 53, 52, 50, 48, 45, 42, 38, 33, 28, 23,
17, 11, 4, -2, -9, -16, -24, -31, -37, -44, -49, -54, -57, -60, -61, -61, -60,
-57, -55, -51, -48, -44, -39, -35, -30, -25, -20, -14, -8, -1, 5, 12, 18, 25,
30, 35, 39, 41, 43, 43, 43, 41, 39, 35, 31, 26, 21, 15, 8, 1, -4, -11, -17, -23,
-29, -34, -38, -42, -45, -48, -49, -50, -50, -48, -46, -43, -39, -34, -29, -23,
-17, -11, -5, 0, 5, 10, 14, 18, 22, 26, 30, 35, 39, 43, 47, 51, 53, 55, 55, 55,
53, 50, 47, 43, 38, 34, 29, 25, 20, 16, 12, 9, 6, 3, 0, -1, -3, -5, -7, -8, -9,
-10, -10, -11, -10, -10, -9, -7, -5, -3, -1, 1, 3, 5, 6, 7, 7, 6, 4, 2, 0, -2,
-5, -7, -9, -10, -11, -12, -12, -13, -13, -13, -13, -13, -12, -12, -12, -12,
-11, -11, -10, -10, -9, -9, -9, -8, -8, -8, -8, -8, -7, -7, -7, -7, -8, -8, -8,
-8, -8, -9, -9, -9, -8, -8, -7, -7, -6, -5, -5, -5, -5, -5, -4, -4, -3, -3, -1,
0, 3, 6, 9, 12, 14, 17, 19, 20, 21, 21, 20, 19, 17, 16, 13, 11, 9, 6, 4, 1, -1,
-3, -6, -8, -11, -14, -17, -19, -22, -24, -26, -27, -27, -27, -25, -23, -19,
-15, -10, -4, 1, 8, 14, 20, 26, 31, 36, 40, 45, 49, 53, 57, 61, 65, 69, 72, 75,
76, 76, 75, 73, 69, 64, 57, 50, 41, 32, 22, 11, 0, -11, -22, -33, -44, -55, -64,
-73, -81, -88, -93, -98, -101, -103, -103, -102, -100, -96, -91, -86, -78, -70,
-62, -52, -42, -32, -22, -13, -4, 4, 12, 20, 27, 34, 40, 47, 52, 58, 62, 65, 68,
69, 69, 68, 66, 62, 58, 53, 48, 42, 36, 30, 24, 17, 11, 5, 0, -6, -11, -16, -21,
-25, -29, -33, -36, -39, -41, -43, -45, -45, -46, -45, -44, -42, -39, -35, -31,
-27, -23, -20, -16, -13, -10, -8, -6, -3, -1, 1, 5, 9, 14, 19, 25, 30, 35, 40,
45, 49, 53, 55, 58, 59, 61, 61, 61, 61, 60, 58, 57, 54, 52, 49, 45, 41, 37, 33,
27, 22, 16, 10, 3, -2, -9, -15, -22, -27, -33, -38, -42, -46, -50, -53, -56,
-58, -60, -62, -62, -62, -61, -59, -56, -52, -48, -42, -36, -30, -23, -17, -12,
-6, -2, 2, 5, 8, 11, 13, 15, 16, 17, 17, 17, 16, 15, 13, 11, 8, 6, 2, 0, -3, -7,
-10, -13, -15, -17, -18, -18, -18, -16, -15, -12, -9, -6, -2, 0, 4, 7, 10, 12,
14, 16, 19, 21, 23, 26, 29, 31, 34, 36, 38, 39, 39, 38, 37, 35, 32, 28, 24, 18,
13, 7, 1, -4, -10, -15, -20, -25, -28, -31, -33, -35, -36, -36, -35, -34, -32,
-29, -26, -22, -17, -12, -6, 0, 6, 12, 19, 26, 32, 38, 42, 46, 50, 52, 53, 54,
55, 55, 54, 53, 51, 49, 46, 42, 37, 32, 25, 18, 11, 4, -3, -10, -18, -25, -31,
-37, -42, -46, -50, -53, -56, -58, -60, -61, -62, -62, -61, -61, -59, -58, -55,
-53, -49, -45, -41, -36, -31, -25, -20, -14, -9, -5, -1, 1, 3, 5, 7, 9, 11, 13,
15, 18, 22, 25, 29, 32, 35, 38, 40, 41, 42, 42, 42, 41, 40, 38, 36, 34, 31, 28,
25, 21, 18, 14, 10, 7, 3, 0, -4, -8, -11, -14, -18, -21, -24, -26, -28, -29,
-30, -30, -29, -27, -25, -22, -19, -16, -13, -9, -5, -1, 2, 7, 12, 17, 23, 29,
35, 41, 46, 51, 55, 58, 60, 61, 61, 60, 59, 56, 53, 49, 44, 38, 32, 25, 17, 9,
1, -7, -15, -24, -33, -41, -48, -55, -61, -67, -71, -74, -75, -76, -75, -72,
-69, -64, -59, -53, -47, -40, -34, -28, -22, -16, -10, -4, 1, 8, 14, 20, 27, 33,
38, 43, 46, 49, 50, 50, 49, 46, 43, 39, 33, 27, 21, 15, 8, 2, -3, -9, -15, -20,
-25, -29, -33, -36, -39, -42, -43, -44, -44, -44, -42, -40, -37, -33, -29, -24,
-19, -13, -8, -2, 2, 7, 12, 16, 20, 24, 27, 30, 34, 37, 40, 42, 45, 47, 48, 48,
48, 48, 47, 46, 44, 42, 40, 37, 35, 33, 30, 28, 25, 22, 20, 17, 14, 12, 9, 7, 4,
2, 0, -2, -4, -6, -8, -10, -11, -13, -14, -15, -16, -17, -19, -20, -22, -24,
-26, -29, -32, -34, -36, -38, -39, -39, -38, -37, -34, -31, -27, -23, -19, -15,
-11, -8, -5, -2, 0, 2, 4, 6, 7, 8, 9, 10, 10, 10, 10, 10, 9, 8, 6, 4, 2, 0, -2,
-5, -8, -11, -13, -15, -17, -18, -19, -18, -18, -16, -15, -13, -12, -10, -9, -8,
-6, -5, -3, -1, 1, 4, 8, 11, 15, 19, 22, 24, 26, 27, 28, 28, 27, 26, 24, 22, 20,
17, 14, 11, 8, 4, 0, -3, -7, -11, -15, -18, -21, -23, -24, -25, -25, -24, -22,
-19, -16, -12, -6, -1, 4, 11, 17, 23, 29, 35, 40, 44, 48, 51, 54, 57, 59, 61,
63, 64, 64, 64, 62, 60, 56, 51, 45, 37, 29, 20, 10, 0, -10, -20, -30, -40, -49,
-58, -66, -73, -78, -83, -87, -90, -91, -92, -92, -90, -88, -85, -81, -76, -71,
-64, -57, -49, -40, -31, -22, -12, -3, 4, 12, 20, 26, 32, 37, 41, 45, 49, 52,
54, 57, 59, 60, 61, 61, 61, 60, 58, 55, 52, 49, 44, 40, 35, 29, 24, 19, 13, 8,
3, -1, -6, -11, -16, -20, -24, -28, -32, -35, -38, -40, -42, -43, -43, -43, -42,
-41, -39, -36, -34, -31, -28, -26, -23, -20, -17, -14, -11, -7, -2, 2, 8, 15,
22, 29, 36, 43, 49, 55, 60, 64, 67, 69, 71, 72, 72, 71, 70, 68, 66, 63, 59, 54,
49, 43, 36, 29, 21, 13, 4, -4, -13, -22, -31, -39, -47, -54, -60, -65, -69, -72,
-74, -75, -75, -74, -72, -70, -67, -64, -61, -56, -52, -46, -40, -34, -27, -20,
-12, -5, 1, 8, 14, 19, 24, 27, 30, 32, 33, 33, 33, 32, 30, 27, 24, 20, 16, 12,
8, 3, 0, -3, -7, -10, -12, -14, -16, -17, -18, -18, -18, -16, -14, -12, -9, -6,
-2, 1, 4, 8, 10, 13, 15, 17, 19, 21, 23, 24, 27, 29, 31, 32, 34, 34, 34, 33, 31,
28, 24, 20, 16, 11, 6, 1, -2, -7, -10, -13, -16, -18, -20, -21, -22, -22, -22,
-21, -20, -18, -17, -15, -12, -9, -5, -1, 2, 7, 12, 17, 22, 26, 30, 33, 35, 36,
36, 36, 34, 32, 29, 27, 24, 21, 18, 15, 12, 10, 6, 3, 0, -3, -6, -10, -13, -16,
-20, -22, -25, -28, -30, -32, -34, -35, -36, -38, -38, -39, -39, -39, -39, -39,
-39, -38, -37, -36, -35, -33, -32, -30, -27, -25, -22, -20, -17, -14, -11, -9,
-7, -4, -1, 0, 3, 6, 10, 14, 18, 23, 27, 31, 35, 39, 42, 44, 45, 46, 46, 46, 45,
43, 41, 38, 35, 32, 28, 24, 20, 16, 11, 7, 2, -2, -6, -11, -16, -21, -25, -29,
-33, -35, -37, -38, -37, -36, -33, -30, -26, -21, -16, -11, -6, -1, 3, 8, 13,
18, 23, 28, 33, 38, 43, 49, 53, 57, 60, 62, 63, 63, 62, 59, 56, 51, 45, 38, 30,
22, 13, 4, -4, -13, -22, -31, -39, -47, -54, -60, -66, -70, -73, -76, -77, -76,
-75, -73, -69, -65, -59, -53, -46, -39, -32, -25, -17, -10, -4, 2, 7, 13, 18,
24, 29, 33, 38, 42, 45, 48, 49, 50, 49, 47, 45, 41, 37, 33, 28, 23, 17, 12, 7,
2, -2, -7, -11, -16, -20, -23, -27, -30, -32, -34, -36, -37, -37, -37, -36, -35,
-33, -30, -27, -23, -19, -14, -9, -4, 0, 4, 8, 11, 14, 16, 19, 21, 23, 25, 27,
30, 33, 36, 38, 41, 44, 46, 47, 49, 49, 50, 49, 49, 48, 46, 44, 42, 40, 37, 34,
31, 28, 25, 22, 18, 14, 10, 6, 1, -2, -7, -13, -18, -23, -28, -33, -37, -41,
-45, -48, -50, -53, -55, -56, -57, -58, -58, -58, -57, -54, -51, -47, -42, -36,
-29, -23, -15, -9, -2, 3, 8, 13, 17, 21, 24, 26, 28, 30, 30, 31, 30, 29, 28, 26,
23, 20, 17, 13, 8, 4, 0, -5, -9, -14, -17, -20, -23, -24, -25, -25, -24, -22,
-20, -18, -16, -13, -11, -9, -7, -6, -4, -2, 0, 2, 5, 8, 11, 14, 17, 20, 22, 24,
25, 25, 25, 24, 23, 21, 19, 16, 12, 9, 5, 1, -2, -5, -9, -11, -14, -16, -17,
-18, -18, -17, -16, -14, -12, -9, -6, -2, 1, 6, 11, 16, 22, 28, 33, 38, 43, 47,
51, 53, 55, 56, 57, 56, 56, 54, 52, 50, 47, 43, 38, 32, 26, 19, 11, 3, -5, -13,
-22, -30, -38, -45, -52, -58, -63, -68, -71, -74, -76, -77, -77, -77, -76, -74,
-72, -69, -66, -61, -57, -51, -45, -39, -32, -25, -17, -10, -2, 4, 10, 16, 21,
25, 28, 31, 34, 36, 37, 39, 42, 44, 46, 48, 51, 52, 54, 54, 54, 53, 51, 48, 45,
42, 37, 33, 28, 23, 18, 13, 8, 3, -2, -7, -12, -17, -22, -26, -31, -35, -38,
-42, -45, -47, -49, -50, -51, -51, -50, -49, -47, -44, -40, -36, -32, -27, -22,
-16, -11, -4, 1, 8, 16, 24, 32, 40, 48, 55, 62, 68, 73, 78, 81, 83, 84, 85, 84,
82, 80, 76, 71, 65, 59, 51, 43, 34, 24, 14, 4, -6, -16, -27, -37, -46, -55, -63,
-70, -75, -80, -83, -84, -85, -84, -82, -79, -75, -70, -66, -61, -55, -50, -44,
-39, -33, -26, -20, -13, -5, 1, 8, 14, 20, 26, 30, 33, 35, 36, 36, 36, 34, 32,
29, 26, 22, 18, 14, 10, 7, 4, 1, -1, -3, -6, -7, -9, -10, -12, -12, -13, -13,
-12, -11, -10, -8, -5, -2, 0, 3, 6, 9, 11, 13, 15, 16, 17, 18, 19, 20, 21, 22,
23, 24, 24, 24, 23, 22, 21, 19, 17, 14, 12, 10, 7, 5, 3, 1, 0, -1, -3, -4, -4,
-5, -5, -6, -5, -5, -5, -4, -3, -2, 0, 0, 2, 4, 6, 9, 11, 13, 14, 16, 17, 17,
16, 15, 13, 10, 7, 4, 1, -1, -3, -5, -6, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7,
-7, -8, -8, -9, -10, -11, -12, -13, -14, -15, -16, -17, -19, -20, -21, -22, -24,
-25, -27, -29, -31, -32, -33, -34, -35, -35, -34, -33, -31, -28, -25, -21, -18,
-14, -10, -6, -1, 2, 6, 10, 15, 19, 24, 29, 34, 39, 43, 46, 49, 51, 52, 53, 52,
51, 49, 46, 43, 40, 35, 31, 26, 21, 16, 10, 4, -1, -6, -12, -17, -22, -27, -30,
-33, -35, -36, -36, -35, -33, -30, -27, -22, -17, -12, -6, 0, 4, 9, 14, 19, 23,
27, 31, 35, 39, 43, 47, 50, 53, 55, 56, 56, 54, 51, 47, 42, 36, 30, 22, 14, 5,
-2, -11, -19, -27, -35, -42, -48, -54, -59, -63, -66, -68, -69, -70, -69, -68,
-66, -63, -59, -55, -50, -44, -38, -31, -24, -17, -10, -3, 2, 8, 14, 18, 22, 26,
29, 31, 33, 35, 37, 38, 39, 39, 39, 38, 37, 35, 33, 30, 27, 24, 20, 17, 13, 9,
5, 1, -3, -7, -11, -14, -18, -21, -23, -26, -28, -30, -31, -32, -33, -33, -32,
-31, -30, -28, -25, -22, -19, -15, -12, -8, -5, -2, 0, 3, 5, 8, 11, 14, 17, 21,
26, 31, 36, 41, 46, 50, 54, 57, 60, 62, 63, 63, 63, 62, 60, 58, 56, 53, 49, 45,
41, 37, 32, 26, 20, 14, 7, 0, -7, -15, -23, -31, -39, -46, -53, -60, -65, -70,
-73, -75, -76, -77, -76, -75, -73, -71, -68, -64, -59, -54, -48, -41, -34, -26,
-18, -10, -1, 6, 13, 20, 26, 32, 36, 40, 43, 45, 46, 46, 45, 44, 41, 38, 35, 30,
25, 20, 15, 9, 4, -1, -6, -10, -14, -17, -20, -22, -23, -24, -24, -24, -23, -21,
-19, -16, -14, -11, -8, -6, -4, -2, 0, 1, 3, 5, 7, 9, 11, 14, 16, 18, 19, 21,
21, 21, 20, 19, 17, 14, 11, 8, 5, 3, 0, -1, -4, -5, -6, -7, -7, -7, -7, -6, -4,
-3, -1, 0, 2, 4, 7, 10, 13, 17, 20, 24, 28, 32, 36, 40, 42, 44, 46, 46, 45, 43,
41, 38, 34, 30, 25, 21, 17, 12, 7, 2, -2, -7, -12, -17, -23, -28, -33, -38, -42,
-46, -50, -53, -55, -57, -59, -60, -60, -60, -59, -58, -57, -55, -53, -50, -47,
-44, -41, -37, -32, -28, -23, -18, -14, -9, -4, 0, 4, 8, 12, 15, 18, 21, 24, 26,
29, 32, 36, 39, 43, 46, 50, 52, 55, 56, 57, 56, 56, 54, 52, 49, 45, 41, 37, 32,
27, 22, 16, 10, 5, 0, -6, -12, -18, -24, -29, -35, -40, -44, -49, -52, -55, -57,
-59, -59, -57, -55, -52, -47, -42, -36, -30, -23, -16, -9, -2, 4, 11, 18, 26,
33, 41, 49, 56, 63, 69, 74, 79, 82, 85, 86, 86, 84, 82, 78, 73, 66, 59, 51, 42,
32, 22, 11, 0, -9, -20, -30, -39, -48, -56, -63, -70, -75, -79, -82, -83, -84,
-83, -81, -78, -73, -69, -63, -57, -51, -45, -39, -33, -27, -22, -16, -10, -4,
1, 6, 12, 17, 22, 26, 29, 31, 32, 33, 32, 31, 29, 27, 25, 22, 19, 17, 14, 12,
10, 8, 6, 4, 2, 1, 0, -1, -2, -4, -4, -5, -5, -6, -5, -5, -4, -2, 0, 0, 3, 5, 7,
9, 10, 11, 12, 13, 13, 13, 12, 12, 12, 12, 12, 12, 13, 14, 15, 16, 17, 17, 18,
18, 18, 18, 17, 16, 16, 15, 14, 13, 12, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 0, -1,
-2, -3, -4, -5, -7, -8, -9, -11, -12, -13, -15, -16, -17, -19, -20, -21, -21,
-21, -21, -20, -18, -16, -13, -10, -6, -3, 0, 2, 5, 7, 9, 10, 10, 11, 11, 10, 9,
8, 7, 5, 3, 1, -1, -4, -7, -10, -14, -18, -22, -26, -30, -34, -37, -40, -42,
-43, -43, -42, -40, -38, -34, -30, -26, -21, -16, -12, -7, -3, 1, 5, 10, 14, 19,
24, 29, 34, 39, 43, 47, 50, 52, 53, 53, 53, 51, 49, 46, 42, 38, 33, 28, 22, 16,
10, 5, 0, -5, -10, -14, -18, -21, -24, -25, -27, -27, -27, -26, -24, -21, -18,
-15, -11, -6, -1, 3, 8, 13, 17, 21, 25, 28, 31, 33, 35, 37, 38, 39, 39, 39, 38,
36, 34, 30, 26, 20, 15, 8, 2, -4, -10, -17, -23, -29, -34, -39, -43, -47, -50,
-52, -54, -55, -55, -55, -54, -53, -51, -49, -46, -42, -39, -34, -30, -25, -19,
-13, -8, -2, 3, 8, 12, 16, 19, 21, 23, 24, 25, 25, 26, 26, 27, 28, 29, 30, 31,
32, 32, 32, 31, 30, 29, 27, 24, 21, 18, 14, 11, 7, 3, 0, -3, -7, -10, -14, -17,
-20, -22, -25, -27, -29, -31, -32, -33, -33, -33, -33, -32, -30, -28, -26, -23,
-19, -16, -12, -8, -3, 0, 5, 10, 15, 20, 26, 32, 38, 44, 50, 56, 61, 65, 69, 72,
73, 74, 74, 73, 72, 69, 66, 62, 58, 53, 47, 40, 33, 25, 16, 7, -1, -11, -21,
-31, -40, -50, -59, -67, -74, -80, -85, -88, -91, -92, -92, -90, -88, -84, -80,
-75, -70, -64, -58, -51, -44, -37, -29, -21, -13, -4, 4, 12, 20, 28, 35, 40, 45,
49, 52, 54, 54, 53, 52, 49, 46, 42, 37, 32, 27, 22, 17, 12, 7, 3, 0, -4, -8,
-11, -13, -15, -17, -18, -19, -20, -19, -19, -17, -15, -13, -11, -8, -6, -3, -1,
0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 12, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 4,
4, 4, 4, 5, 5, 6, 7, 8, 9, 10, 11, 12, 14, 15, 16, 18, 19, 21, 23, 24, 26, 27,
29, 30, 30, 30, 29, 27, 24, 21, 16, 12, 7, 3, -1, -5, -8, -11, -14, -16, -18,
-20, -21, -23, -25, -26, -28, -30, -31, -33, -34, -35, -36, -37, -37, -38, -38,
-38, -38, -38, -37, -36, -35, -34, -33, -32, -31, -29, -28, -27, -25, -23, -21,
-18, -15, -12, -8, -5, 0, 3, 7, 12, 16, 20, 24, 28, 32, 36, 40, 44, 47, 51, 54,
56, 58, 59, 59, 59, 58, 56, 53, 50, 46, 41, 36, 30, 24, 18, 12, 5, -1, -8, -14,
-21, -28, -34, -40, -45, -50, -53, -56, -58, -59, -59, -57, -54, -51, -46, -40,
-34, -27, -20, -13, -6, 1, 8, 14, 21, 28, 34, 41, 47, 53, 59, 65, 70, 74, 76,
78, 78, 77, 74, 70, 65, 59, 51, 43, 34, 25, 15, 6, -3, -12, -21, -29, -37, -44,
-51, -57, -62, -66, -69, -72, -73, -74, -73, -72, -70, -66, -62, -58, -52, -47,
-41, -34, -28, -23, -17, -12, -7, -3, 0, 4, 8, 11, 15, 17, 20, 22, 23, 24, 25,
25, 25, 25, 24, 23, 22, 21, 19, 18, 17, 15, 13, 12, 10, 8, 7, 5, 3, 1, 0, 0, -2,
-3, -3, -4, -4, -5, -4, -4, -4, -3, -2, -1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 2, 3,
5, 7, 10, 13, 16, 20, 23, 25, 28, 30, 31, 32, 32, 32, 31, 31, 29, 28, 26, 24,
22, 19, 17, 14, 12, 9, 5, 2, -1, -5, -10, -14, -19, -23, -28, -32, -35, -38,
-40, -42, -43, -43, -42, -41, -40, -38, -36, -34, -31, -28, -25, -21, -16, -11,
-6, -1, 4, 9, 14, 19, 22, 26, 28, 30, 31, 31, 31, 30, 28, 26, 23, 20, 16, 12, 7,
2, -3, -8, -14, -19, -24, -28, -32, -36, -39, -40, -41, -42, -41, -40, -38, -35,
-31, -27, -23, -18, -14, -10, -5, -1, 2, 7, 11, 15, 19, 24, 28, 32, 36, 40, 43,
45, 46, 47, 47, 46, 44, 41, 38, 34, 30, 26, 21, 17, 12, 8, 4, 1, -1, -4, -6, -8,
-10, -11, -11, -11, -11, -11, -10, -9, -7, -5, -2, 0, 3, 7, 11, 14, 18, 21, 23,
25, 26, 26, 25, 24, 23, 21, 18, 15, 12, 9, 6, 2, 0, -4, -8, -12, -16, -20, -23,
-27, -30, -33, -36, -38, -40, -41, -42, -42, -42, -42, -41, -40, -38, -37, -34,
-32, -30, -27, -24, -21, -18, -14, -11, -7, -4, 0, 2, 5, 8, 11, 13, 14, 15, 16,
17, 17, 18, 20, 21, 23, 25, 27, 30, 32, 34, 35, 36, 36, 36, 35, 33, 31, 28, 25,
21, 18, 14, 10, 6, 2, -2, -6, -10, -14, -18, -22, -25, -29, -32, -35, -38, -40,
-41, -42, -43, -42, -40, -38, -35, -30, -25, -20, -14, -7, -1, 5, 11, 18, 24,
30, 37, 43, 49, 55, 61, 67, 71, 75, 79, 81, 82, 82, 82, 80, 77, 73, 68, 61, 54,
46, 37, 28, 17, 7, -3, -14, -25, -36, -46, -55, -64, -72, -79, -85, -90, -93,
-96, -97, -97, -96, -93, -89, -85, -79, -73, -66, -59, -52, -45, -37, -30, -22,
-14, -6, 0, 8, 16, 23, 30, 36, 42, 46, 49, 51, 52, 52, 51, 50, 47, 44, 41, 37,
34, 30, 26, 22, 19, 15, 12, 8, 5, 2, 0, -3, -6, -9, -11, -13, -15, -16, -17,
-17, -16, -15, -14, -12, -11, -9, -7, -6, -5, -5, -4, -4, -4, -4, -4, -3, -3,
-2, -1, 0, 1, 2, 4, 6, 7, 9, 10, 11, 13, 14, 15, 17, 18, 19, 20, 21, 22, 22, 23,
23, 24, 24, 25, 25, 25, 25, 24, 24, 23, 23, 22, 20, 19, 17, 14, 12, 9, 6, 2, 0,
-4, -8, -12, -16, -19, -22, -24, -26, -27, -27, -27, -26, -25, -24, -23, -21,
-20, -19, -18, -17, -16, -16, -16, -16, -16, -16, -16, -17, -17, -18, -18, -19,
-20, -21, -22, -23, -24, -26, -27, -28, -29, -29, -29, -28, -27, -25, -22, -18,
-14, -9, -3, 1, 7, 12, 17, 22, 26, 30, 34, 38, 41, 45, 48, 51, 54, 56, 58, 59,
59, 59, 58, 55, 52, 48, 43, 38, 32, 26, 19, 12, 5, -1, -8, -15, -22, -28, -33,
-38, -43, -46, -49, -50, -51, -51, -50, -48, -46, -42, -38, -33, -27, -21, -14,
-8, -1, 5, 12, 18, 24, 29, 35, 40, 45, 49, 53, 57, 59, 61, 62, 62, 61, 59, 55,
50, 44, 38, 31, 23, 16, 8, 0, -6, -13, -20, -27, -33, -38, -43, -48, -52, -55,
-58, -60, -61, -62, -62, -61, -60, -58, -55, -52, -48, -43, -39, -33, -28, -23,
-18, -14, -10, -6, -3, -1, 1, 3, 4, 6, 8, 10, 12, 15, 17, 19, 22, 24, 25, 26,
27, 28, 28, 28, 28, 27, 26, 24, 22, 21, 19, 16, 14, 12, 10, 8, 6, 4, 2, 0, -1,
-3, -5, -7, -8, -9, -10, -11, -11, -11, -11, -11, -10, -9, -8, -7, -5, -4, -2,
0, 3, 6, 10, 14, 19, 23, 28, 32, 36, 40, 43, 45, 47, 48, 48, 47, 46, 45, 43, 41,
38, 34, 30, 26, 21, 16, 11, 4, -1, -8, -15, -22, -30, -37, -43, -49, -54, -58,
-61, -63, -64, -64, -63, -61, -58, -55, -51, -47, -42, -37, -32, -27, -21, -15,
-10, -3, 2, 8, 15, 21, 26, 31, 35, 38, 40, 42, 42, 41, 40, 37, 34, 30, 26, 20,
15, 9, 4, -1, -6, -12, -16, -20, -24, -28, -30, -32, -34, -35, -35, -35, -34,
-33, -31, -29, -26, -23, -19, -15, -11, -7, -3, 0, 3, 7, 10, 13, 16, 19, 22, 25,
27, 29, 31, 33, 34, 34, 34, 33, 32, 30, 28, 26, 24, 22, 20, 18, 16, 14, 13, 11,
10, 9, 8, 7, 6, 5, 5, 4, 4, 4, 4, 4, 5, 6, 7, 8, 10, 11, 13, 14, 15, 16, 15, 14,
12, 9, 6, 2, 0, -4, -8, -12, -15, -17, -19, -21, -22, -23, -24, -25, -26, -27,
-28, -28, -29, -29, -29, -29, -29, -29, -28, -27, -26, -25, -24, -23, -21, -20,
-18, -17, -15, -14, -13, -11, -10, -9, -8, -7, -6, -4, -3, -1, 0, 1, 3, 5, 8,
10, 12, 14, 16, 19, 21, 24, 27, 30, 33, 35, 37, 39, 40, 40, 40, 39, 37, 35, 32,
28, 25, 21, 16, 12, 7, 1, -3, -8, -14, -19, -24, -29, -34, -38, -42, -45, -48,
-50, -51, -51, -49, -47, -44, -40, -35, -29, -22, -15, -8, 0, 7, 14, 21, 28, 35,
41, 47, 53, 59, 64, 69, 74, 78, 81, 83, 84, 84, 83, 80, 76, 71, 64, 56, 48, 38,
28, 17, 6, -4, -15, -25, -35, -45, -53, -61, -69, -75, -80, -85, -89, -91, -93,
-93, -93, -91, -88, -84, -79, -73, -67, -60, -52, -45, -37, -30, -23, -15, -9,
-2, 4, 10, 16, 22, 27, 32, 36, 39, 42, 44, 46, 46, 46, 46, 45, 44, 43, 41, 39,
37, 35, 32, 30, 27, 24, 21, 18, 14, 11, 7, 4, 0, -2, -5, -7, -10, -12, -13, -15,
-15, -16, -16, -16, -16, -16, -16, -16, -16, -16, -16, -17, -17, -16, -16, -15,
-13, -11, -8, -4, -1, 2, 7, 11, 15, 18, 22, 25, 28, 30, 32, 34, 35, 36, 37, 37,
37, 37, 37, 37, 36, 35, 33, 32, 29, 27, 24, 21, 17, 13, 8, 4, 0, -5, -9, -14,
-17, -21, -24, -26, -29, -31, -32, -33, -34, -35, -35, -34, -33, -31, -29, -26,
-23, -19, -16, -12, -9, -7, -4, -3, -1, 0, 0, 0, 0, -1, -2, -3, -5, -7, -10,
-12, -15, -18, -21, -24, -26, -29, -31, -32, -33, -33, -32, -31, -28, -25, -21,
-17, -12, -6, -1, 4, 10, 15, 20, 24, 28, 32, 36, 39, 42, 45, 48, 50, 52, 54, 55,
55, 55, 54, 51, 48, 44, 39, 34, 28, 22, 15, 9, 2, -3, -9, -15, -20, -25, -29,
-32, -35, -37, -38, -39, -39, -39, -38, -37, -35, -32, -28, -25, -20, -15, -10,
-4, 1, 6, 12, 17, 23, 27, 31, 34, 37, 39, 41, 42, 42, 42, 41, 40, 38, 35, 32,
28, 24, 20, 15, 10, 5, 0, -3, -8, -13, -18, -22, -26, -29, -33, -36, -38, -40,
-42, -43, -44, -44, -44, -44, -43, -42, -41, -39, -37, -34, -31, -28, -25, -22,
-19, -16, -13, -11, -9, -8, -6, -5, -3, -2, 0, 2, 5, 9, 13, 17, 21, 24, 28, 31,
33, 35, 36, 37, 37, 36, 35, 34, 32, 30, 28, 25, 23, 20, 17, 14, 11, 7, 4, 0, -3,
-6, -10, -14, -17, -20, -22, -24, -25, -25, -25, -24, -23, -20, -18, -14, -11,
-7, -3, 0, 4, 8, 13, 18, 22, 27, 32, 37, 41, 45, 49, 52, 54, 55, 56, 55, 54, 52,
50, 46, 42, 37, 31, 25, 18, 11, 3, -4, -13, -21, -29, -37, -45, -51, -57, -63,
-67, -70, -72, -73, -73, -72, -70, -68, -64, -59, -54, -48, -42, -36, -29, -23,
-16, -10, -4, 2, 8, 14, 20, 26, 31, 36, 40, 43, 45, 46, 46, 45, 43, 40, 36, 32,
28, 23, 18, 13, 8, 3, 0, -4, -8, -11, -14, -17, -19, -21, -23, -25, -26, -27,
-27, -27, -27, -26, -24, -22, -20, -17, -14, -11, -7, -4, -1, 0, 3, 5, 6, 8, 9,
11, 12, 14, 16, 18, 19, 21, 22, 24, 25, 26, 27, 27, 28, 28, 28, 28, 28, 28, 27,
27, 26, 25, 25, 23, 22, 21, 20, 19, 17, 16, 15, 13, 12, 11, 10, 8, 7, 6, 4, 3,
1, 0, -3, -6, -9, -13, -16, -20, -23, -27, -29, -31, -33, -33, -33, -33, -32,
-30, -29, -27, -25, -24, -22, -20, -19, -17, -16, -15, -13, -12, -11, -10, -9,
-8, -7, -7, -6, -6, -6, -6, -7, -7, -8, -9, -10, -11, -12, -12, -13, -12, -11,
-10, -8, -5, -2, 0, 4, 7, 11, 14, 17, 20, 23, 26, 29, 32, 34, 36, 38, 40, 42,
42, 43, 42, 41, 39, 37, 33, 30, 25, 20, 15, 9, 3, -3, -9, -15, -21, -27, -32,
-37, -41, -44, -47, -48, -49, -49, -48, -46, -43, -40, -35, -30, -24, -18, -11,
-3, 3, 11, 18, 25, 32, 38, 44, 49, 54, 59, 63, 67, 70, 73, 75, 76, 76, 75, 72,
68, 63, 57, 50, 42, 33, 23, 14, 4, -4, -14, -23, -31, -39, -47, -54, -60, -65,
-70, -74, -78, -81, -82, -83, -84, -83, -81, -79, -75, -71, -66, -60, -54, -48,
-41, -34, -27, -21, -15, -9, -4, 0, 5, 9, 13, 17, 21, 24, 28, 31, 35, 37, 40,
42, 44, 46, 47, 47, 47, 47, 46, 45, 43, 41, 39, 36, 33, 29, 25, 22, 18, 14, 10,
6, 2, -1, -5, -8, -12, -15, -18, -20, -23, -25, -27, -28, -29, -29, -30, -30,
-30, -29, -28, -27, -25, -22, -19, -15, -11, -6, -1, 4, 10, 15, 21, 26, 30, 34,
38, 41, 43, 45, 46, 47, 48, 47, 47, 46, 44, 42, 40, 37, 33, 29, 25, 20, 14, 8,
2, -4, -10, -16, -22, -27, -32, -36, -38, -41, -42, -43, -43, -42, -42, -41,
-39, -38, -36, -34, -31, -28, -25, -21, -17, -12, -8, -3, 0, 3, 6, 9, 11, 12,
12, 12, 11, 9, 7, 4, 1, -1, -5, -9, -12, -16, -19, -22, -25, -27, -28, -29, -29,
-29, -27, -26, -23, -20, -17, -13, -9, -4, 0, 5, 10, 15, 19, 24, 28, 32, 35, 38,
40, 43, 44, 46, 47, 48, 49, 48, 47, 46, 44, 41, 37, 33, 29, 24, 19, 14, 9, 5, 0,
-3, -7, -10, -13, -16, -18, -20, -21, -22, -23, -24, -24, -24, -23, -22, -21,
-19, -17, -14, -11, -8, -4, 0, 3, 7, 10, 14, 16, 18, 20, 20, 20, 20, 19, 18, 16,
15, 13, 12, 11, 10, 9, 8, 6, 5, 3, 1, 0, -2, -5, -7, -9, -12, -14, -16, -18,
-20, -21, -23, -24, -25, -26, -27, -27, -28, -28, -29, -29, -29, -29, -29, -29,
-28, -27, -26, -25, -24, -22, -21, -19, -17, -15, -12, -10, -7, -4, 0, 2, 7, 11,
16, 20, 25, 29, 33, 36, 38, 40, 41, 42, 42, 41, 40, 38, 36, 34, 31, 28, 24, 20,
16, 12, 7, 2, -2, -7, -11, -16, -20, -24, -27, -30, -31, -32, -32, -31, -29,
-26, -23, -19, -14, -9, -4, 0, 5, 10, 14, 19, 24, 28, 33, 37, 41, 45, 49, 52,
55, 57, 58, 58, 57, 55, 52, 48, 43, 37, 31, 23, 15, 6, -1, -10, -19, -27, -35,
-43, -50, -56, -61, -65, -69, -72, -74, -75, -75, -74, -72, -69, -66, -61, -56,
-50, -44, -37, -30, -23, -16, -9, -3, 2, 8, 14, 19, 24, 28, 33, 36, 39, 41, 43,
44, 43, 42, 41, 39, 36, 33, 30, 27, 23, 20, 16, 13, 10, 7, 4, 1, -1, -4, -7, -9,
-12, -14, -17, -19, -20, -22, -23, -23, -23, -23, -22, -21, -19, -17, -15, -14,
-12, -10, -9, -8, -7, -6, -4, -3, -1, 0, 2, 5, 9, 12, 16, 20, 24, 28, 31, 34,
37, 39, 41, 42, 43, 43, 44, 43, 43, 42, 40, 39, 37, 35, 33, 30, 27, 24, 21, 18,
14, 10, 6, 1, -2, -7, -11, -16, -20, -24, -28, -31, -34, -37, -40, -42, -43,
-44, -45, -45, -45, -44, -42, -40, -37, -34, -30, -26, -22, -19, -15, -11, -8,
-5, -2, 0, 1, 3, 4, 5, 6, 6, 6, 5, 4, 3, 2, 0, -1, -4, -6, -8, -10, -12, -13,
-14, -14, -14, -12, -11, -8, -6, -2, 1, 5, 9, 12, 16, 19, 22, 25, 27, 30, 32,
33, 35, 37, 38, 39, 40, 41, 40, 39, 37, 35, 31, 27, 22, 17, 11, 5, 0, -6, -12,
-18, -24, -28, -33, -36, -39, -41, -42, -42, -42, -41, -40, -38, -35, -31, -27,
-22, -17, -12, -6, 0, 6, 13, 19, 26, 32, 38, 43, 47, 51, 55, 57, 59, 60, 61, 61,
60, 58, 55, 52, 48, 43, 37, 31, 24, 17, 10, 3, -3, -10, -17, -23, -30, -35, -41,
-46, -51, -55, -58, -61, -64, -66, -67, -68, -68, -67, -66, -65, -62, -59, -56,
-52, -48, -43, -38, -33, -28, -23, -18, -14, -10, -6, -2, 0, 4, 8, 12, 16, 20,
25, 30, 35, 39, 43, 47, 50, 53, 55, 56, 57, 56, 56, 54, 52, 49, 46, 42, 38, 34,
30, 25, 20, 16, 11, 5, 0, -4, -10, -15, -20, -25, -29, -33, -37, -39, -41, -42,
-42, -42, -41, -39, -37, -34, -31, -27, -23, -19, -14, -9, -3, 2, 8, 14, 20, 26,
31, 36, 41, 45, 48, 51, 53, 54, 54, 54, 53, 52, 49, 46, 42, 38, 33, 27, 21, 14,
7, 0, -6, -13, -20, -26, -32, -37, -42, -45, -48, -49, -50, -50, -50, -48, -46,
-44, -41, -39, -35, -32, -29, -25, -21, -17, -13, -8, -4, 0, 4, 8, 12, 15, 17,
18, 19, 19, 18, 16, 14, 11, 8, 4, 0, -2, -6, -9, -12, -15, -17, -19, -20, -21,
-21, -21, -20, -19, -18, -16, -14, -12, -9, -7, -4, 0, 3, 6, 10, 14, 18, 22, 25,
28, 30, 32, 34, 35, 35, 35, 35, 34, 34, 33, 32, 30, 29, 27, 25, 23, 21, 19, 16,
14, 12, 10, 7, 6, 4, 2, 0, -1, -2, -3, -5, -6, -7, -8, -8, -9, -9, -10, -10,
-10, -9, -8, -7, -7, -5, -4, -3, -2, -2, -1, -2, -2, -3, -4, -5, -7, -8, -8, -9,
-9, -8, -7, -6, -4, -3, -1, 0, 0, 1, 2, 2, 2, 2, 1, 1, 0, 0, -1, -2, -3, -4, -6,
-7, -9, -10, -12, -14, -16, -18, -21, -23, -25, -27, -29, -30, -31, -31, -31,
-30, -29, -26, -24, -21, -18, -14, -10, -6, -3, 0, 5, 9, 13, 17, 21, 25, 29, 33,
36, 38, 40, 42, 43, 43, 42, 41, 40, 37, 35, 31, 27, 23, 18, 13, 8, 2, -2, -7,
-12, -16, -20, -23, -26, -28, -29, -29, -29, -28, -26, -24, -21, -17, -12, -7,
-2, 2, 7, 12, 17, 22, 27, 31, 35, 38, 42, 45, 48, 50, 52, 54, 55, 55, 54, 52,
48, 44, 39, 32, 25, 18, 10, 1, -6, -15, -23, -30, -37, -44, -50, -55, -59, -63,
-66, -68, -70, -70, -71, -70, -69, -66, -63, -60, -55, -50, -44, -38, -32, -25,
-18, -12, -5, 0, 5, 10, 15, 19, 22, 25, 28, 30, 32, 34, 36, 37, 38, 38, 38, 38,
37, 37, 35, 34, 32, 30, 28, 26, 24, 21, 18, 15, 12, 8, 5, 1, -1, -5, -8, -11,
-14, -17, -20, -22, -24, -26, -27, -28, -28, -29, -29, -28, -28, -27, -26, -25,
-23, -22, -20, -17, -14, -10, -6, -2, 2, 8, 13, 19, 25, 30, 35, 40, 44, 47, 50,
52, 54, 55, 55, 55, 54, 53, 51, 49, 46, 43, 39, 35, 31, 26, 21, 15, 9, 3, -3,
-10, -16, -23, -29, -34, -39, -44, -47, -50, -52, -53, -54, -54, -54, -53, -52,
-50, -49, -46, -44, -40, -37, -33, -28, -23, -18, -14, -9, -4, 0, 3, 6, 8, 11,
12, 13, 14, 14, 13, 12, 10, 9, 6, 4, 2, 0, -2, -4, -5, -7, -8, -8, -8, -8, -7,
-6, -4, -2, 0, 2, 6, 9, 12, 15, 18, 21, 23, 25, 27, 28, 29, 30, 31, 32, 32, 33,
32, 32, 31, 30, 27, 25, 21, 18, 13, 9, 4, 0, -4, -9, -13, -17, -20, -23, -25,
-27, -28, -29, -29, -29, -28, -27, -25, -23, -21, -18, -15, -11, -8, -4, 0, 4,
9, 14, 19, 24, 28, 32, 36, 39, 41, 42, 43, 43, 42, 41, 39, 37, 34, 31, 28, 25,
22, 18, 14, 10, 6, 2, -1, -5, -9, -13, -17, -21, -25, -29, -32, -35, -38, -41,
-43, -45, -46, -47, -48, -49, -49, -49, -48, -48, -47, -45, -44, -42, -40, -37,
-35, -32, -29, -25, -22, -18, -15, -11, -7, -3, 1, 6, 10, 16, 21, 27, 32, 37,
42, 47, 51, 54, 57, 58, 59, 59, 59, 57, 55, 53, 50, 46, 42, 38, 33, 28, 23, 17,
11, 5, 0, -6, -12, -18, -23, -29, -33, -37, -40, -42, -43, -43, -42, -41, -39,
-36, -32, -28, -24, -20, -15, -11, -6, -1, 3, 8, 13, 18, 23, 28, 33, 37, 41, 44,
47, 49, 51, 51, 51, 50, 48, 45, 41, 37, 32, 26, 20, 14, 7, 1, -5, -11, -17, -23,
-28, -33, -37, -40, -43, -45, -47, -48, -48, -47, -46, -45, -42, -40, -37, -33,
-29, -26, -22, -18, -14, -11, -7, -4, 0, 2, 5, 8, 10, 12, 14, 15, 15, 15, 14,
13, 11, 9, 7, 5, 2, 0, -1, -3, -4, -5, -7, -7, -8, -8, -8, -8, -8, -8, -8, -7,
-7, -6, -5, -4, -2, -1, 0, 2, 4, 7, 9, 11, 13, 15, 16, 17, 17, 17, 17, 16, 16,
16, 15, 16, 16, 16, 17, 18, 19, 19, 20, 20, 21, 21, 21, 20, 20, 19, 18, 17, 16,
15, 14, 12, 11, 9, 7, 6, 4, 2, 1, 0, -2, -4, -6, -8, -9, -11, -13, -15, -16,
-18, -19, -21, -22, -23, -24, -24, -25, -25, -24, -24, -23, -21, -19, -17, -14,
-11, -8, -5, -2, 0, 2, 4, 7, 8, 10, 11, 12, 12, 12, 12, 11, 10, 8, 7, 5, 3, 0,
-2, -5, -8, -11, -14, -17, -20, -22, -24, -26, -27, -27, -27, -26, -24, -22,
-19, -16, -12, -9, -5, -2, 1, 4, 8, 11, 14, 16, 19, 22, 24, 27, 29, 31, 32, 33,
34, 34, 33, 32, 30, 27, 24, 21, 17, 13, 9, 5, 0, -3, -6, -10, -12, -15, -17,
-18, -19, -19, -19, -19, -18, -16, -15, -12, -10, -7, -3, 0, 3, 7, 11, 15, 19,
22, 26, 29, 31, 33, 35, 37, 38, 39, 39, 39, 38, 37, 35, 32, 29, 24, 20, 15, 9,
4, -1, -7, -13, -18, -23, -28, -33, -37, -40, -44, -46, -49, -51, -52, -53, -53,
-53, -52, -51, -49, -47, -44, -41, -37, -33, -29, -24, -20, -15, -10, -6, -2, 1,
4, 7, 10, 12, 14, 16, 18, 20, 22, 24, 27, 29, 31, 33, 34, 36, 36, 37, 37, 37,
36, 35, 33, 32, 29, 26, 24, 20, 17, 13, 10, 6, 2, -1, -5, -9, -12, -16, -20,
-23, -26, -29, -32, -34, -36, -37, -37, -37, -37, -35, -33, -31, -28, -25, -21,
-17, -13, -8, -3, 2, 7, 13, 18, 24, 29, 35, 39, 44, 47, 50, 53, 55, 56, 56, 56,
55, 54, 52, 49, 46, 42, 38, 33, 28, 22, 16, 9, 3, -3, -10, -16, -22, -28, -33,
-38, -42, -45, -47, -49, -50, -50, -50, -49, -48, -46, -44, -42, -40, -37, -34,
-31, -28, -24, -20, -16, -12, -8, -4, 0, 3, 6, 9, 11, 12, 13, 13, 13, 12, 11,
10, 8, 7, 5, 4, 2, 1, 0, 0, -1, -1, -1, -1, 0, 0, 0, 1, 2, 3, 5, 6, 8, 10, 12,
13, 15, 17, 18, 19, 20, 21, 21, 21, 21, 21, 20, 19, 18, 17, 15, 14, 12, 10, 8,
6, 3, 1, 0, -2, -4, -6, -8, -9, -11, -11, -12, -13, -13, -13, -13, -12, -12,
-11, -10, -9, -7, -6, -4, -2, 0, 1, 3, 6, 8, 11, 13, 15, 18, 19, 21, 22, 22, 22,
22, 21, 19, 18, 16, 14, 13, 11, 10, 8, 7, 6, 5, 4, 2, 1, 0, -2, -3, -6, -8, -10,
-12, -14, -16, -18, -20, -22, -24, -25, -27, -28, -29, -31, -32, -33, -34, -35,
-35, -36, -36, -36, -36, -35, -34, -33, -31, -28, -25, -21, -18, -14, -9, -5, 0,
3, 8, 13, 17, 22, 27, 32, 36, 40, 43, 46, 49, 50, 51, 52, 51, 50, 49, 47, 44,
41, 37, 33, 28, 23, 18, 12, 6, 1, -4, -9, -14, -19, -23, -27, -30, -33, -34,
-35, -36, -35, -34, -32, -30, -27, -24, -20, -16, -12, -8, -4, -1, 2, 6, 10, 14,
17, 21, 24, 27, 30, 33, 35, 37, 38, 38, 38, 37, 35, 32, 29, 25, 21, 17, 12, 7,
2, -2, -6, -11, -15, -19, -22, -25, -28, -30, -32, -34, -35, -36, -36, -36, -36,
-35, -33, -31, -29, -26, -23, -20, -17, -14, -11, -8, -6, -3, -1, 0, 2, 3, 5, 6,
7, 8, 9, 9, 10, 10, 10, 10, 9, 9, 8, 8, 7, 7, 6, 6, 5, 4, 4, 3, 3, 2, 2, 1, 1,
};
 
 #endif /* chord_H_ */
