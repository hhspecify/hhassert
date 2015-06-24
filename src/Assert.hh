<?hh //strict

namespace hhassert;

class Assert
{

    public static function ok<Ta>(Ta $value) : void
    {
        if ($value === true) {
        }
    }

    public static function equal<Ta, Te>(Ta $actual, Te $expected) : void
    {
        if ($actual === $expected) {
        }
    }

}
