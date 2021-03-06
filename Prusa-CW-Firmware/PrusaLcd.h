//! @file
//! @date Apr 12, 2019
//! @author Marek Bel

#ifndef PRUSALCD_H
#define PRUSALCD_H

//#include <LiquidCrystal.h>
#include "LiquidCrystal_Prusa.h"

class PrusaLcd : public LiquidCrystal_Prusa
{
public:
    using LiquidCrystal_Prusa::LiquidCrystal_Prusa;

    enum class Terminator : uint_least8_t
    {
        none,
        back,
        right,
    };

    //! Print n characters from null terminated string c
    //! if there are not enough characters, prints ' ' for remaining n.
    //!
    //! @par c null terminated string to print
    //! @par n number of characters to print or clear
    //! @par last_symbol if non-zero print it in the end of line
    void printClear(const char *c, uint_least8_t n, Terminator terminator)
    {
        if (terminator != Terminator::none) --n;
        for (uint_least8_t i = 0; i < n; ++i)
        {
            if (*c)
            {
                print(*c);
                ++c;
            }
            else
            {
                print(' ');
            }
        }
        if (terminator == Terminator::back) print(char(0));
        if (terminator == Terminator::right) print(char(1));
    }

};


#endif /* PRUSALCD_H */
