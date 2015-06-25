<?hh //strict

namespace hhassert;

use hhassert\matcher\EqualMatcher;


class Assert
{

    protected static ?FailedSubscriber $subscriber;

    public static function ok<Ta>(Ta $value) : void
    {
        if ($value !== true) {
            throw new AssertionFailedException("Not ok");
        }
    }

    public static function equal<Ta, Te>(Ta $actual, Te $expected) : void
    {
        try {
            EqualMatcher::of($actual)->match($expected);
        } catch (AssertionFailedException $exception) {
            $exception->sendTo(self::failedSubscriber());
        }
    }

    private static function failedSubscriber() : FailedSubscriber
    {
        return self::$subscriber !== null ? self::$subscriber : new FailedExceptionThrower();
    }

}
