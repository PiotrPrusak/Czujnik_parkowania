#include "bitmap.h"
const unsigned char logo [] = {
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F,
0x3F, 0x1F, 0x0F, 0x07, 0x07, 0x07, 0x07, 0x03, 0xC3, 0xE1, 0xE1, 0xB1, 0xF1, 0xF9, 0xF9, 0xFD,
0xFC, 0xFC, 0xFC, 0xFC, 0xFD, 0xFD, 0x7D, 0xDD, 0x37, 0xFF, 0xFD, 0xFF, 0xFF, 0xFE, 0xFE, 0xFD,
0xF9, 0x61, 0x41, 0x17, 0x23, 0x47, 0xDF, 0xAF, 0xDF, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0xFF, 0xBF, 0xBF, 0xFF, 0xFF, 0xDF, 0xFF, 0xDF, 0xD7, 0xDF, 0xDF,
0xEF, 0xCD, 0xE2, 0xE0, 0xC0, 0xC0, 0xC8, 0xC8, 0xC8, 0x48, 0x4C, 0x4F, 0x0F, 0x0F, 0x01, 0x0F,
0x0F, 0x0F, 0x9F, 0x9F, 0x9F, 0x55, 0x4F, 0x9F, 0x7F, 0xFF, 0xFF, 0xC3, 0xFB, 0xFB, 0x73, 0xF3,
0xB7, 0xBF, 0x9F, 0xBF, 0x1F, 0x1F, 0x9F, 0x8F, 0x8F, 0x8F, 0x8C, 0x8F, 0x8F, 0xCF, 0x8E, 0x8C,
0x8B, 0x97, 0x8F, 0x8F, 0x9F, 0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x2F, 0x07,
0xD3, 0xD3, 0xD1, 0xD5, 0xD4, 0xE4, 0xE4, 0x54, 0xD5, 0xD7, 0xD7, 0xD7, 0xD7, 0xD7, 0xD7, 0xD7,
0x07, 0x87, 0xD7, 0xC7, 0xEB, 0x6B, 0xEF, 0xAD, 0x05, 0x06, 0x94, 0x4B, 0x3A, 0x00, 0xC9, 0xE0,
0x64, 0x26, 0x84, 0xC1, 0xD3, 0xBE, 0x3E, 0xFF, 0xFF, 0xFF, 0xBF, 0xBF, 0xFE, 0xFF, 0xDF, 0xDF,
0xFF, 0x6F, 0x6F, 0x6F, 0x7F, 0x77, 0x77, 0x77, 0x7B, 0x7B, 0x3B, 0x3B, 0x3F, 0x3F, 0x3D, 0x3D,
0x3D, 0x3D, 0xFF, 0x7E, 0xBE, 0xDE, 0xDE, 0xFE, 0x7F, 0x1F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xBF,
0x09, 0x0F, 0x0C, 0x07, 0x0F, 0x07, 0x0B, 0x0B, 0x1F, 0x1B, 0x0F, 0x0B, 0x0B, 0x0B, 0xEB, 0x4B,
0x03, 0x03, 0x07, 0x01, 0x06, 0x17, 0x05, 0x07, 0x3D, 0x3D, 0x3B, 0x3B, 0x1B, 0x08, 0x07, 0x00,
0x00, 0x04, 0x80, 0x38, 0xFE, 0xFB, 0x03, 0xFB, 0x6F, 0x3F, 0x5F, 0x7E, 0xFB, 0x07, 0x00, 0x00,
0x01, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0xC0, 0xC0, 0x40, 0xC0, 0x40, 0x40, 0x00, 0x20,
0x20, 0x20, 0x20, 0x30, 0x10, 0x00, 0xF9, 0xFF, 0xEF, 0x08, 0x1A, 0x13, 0xFE, 0x40, 0xB0, 0xFF,
0xFF, 0xFF, 0xFF, 0xEE, 0xCC, 0xC1, 0xCE, 0xDF, 0xDF, 0xDE, 0xDE, 0xDE, 0x9E, 0x9E, 0x3E, 0x3E,
0x3E, 0x3E, 0x3F, 0x3F, 0xBF, 0xBF, 0xBC, 0xB0, 0x8C, 0x9E, 0xB6, 0xB3, 0x3B, 0x3B, 0x1F, 0x1F,
0x1B, 0x0B, 0x00, 0x00, 0x00, 0x9E, 0xEF, 0xE7, 0xE4, 0x02, 0xD0, 0x0C, 0xF6, 0xE7, 0xC6, 0x8C,
0xFF, 0xCE, 0xEC, 0xE4, 0xE5, 0xE4, 0xF7, 0xF6, 0xF3, 0xF2, 0xF0, 0xF8, 0xF8, 0xFA, 0xFA, 0xF8,
0xFC, 0xFC, 0xF8, 0xF9, 0xF8, 0xF0, 0xF0, 0xF0, 0xF8, 0xFD, 0xFF, 0xFF, 0xFE, 0xF8, 0xD3, 0xF6,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF9, 0xF3, 0xF7, 0xFF,
0xF8, 0xFD, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
};

