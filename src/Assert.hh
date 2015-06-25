<?hh //strict

namespace hhassert;

use hhassert\matcher\EqualMatcher;


class Assert
{

    public static function ok<Ta>(Ta $value) : void
    {
        if ($value !== true) {
            throw new AssertionFailedException("Not ok");
        }
    }

    public static function equal<Ta, Te>(Ta $actual, Te $expected) : void
    {
        $matcher = new EqualMatcher($actual);

        if ($matcher->match($expected)) {
            return;
        }

        $matcher->throwFailedException();
    }

}
