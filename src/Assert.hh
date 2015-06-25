<?hh //strict

namespace hhassert;

use hhassert\matcher\EqualMatcher;


class Assert
{

    protected static ?Context $context;

    public static function configure(Configurator $configurator) : void
    {
        self::$context = ContextBuilder::create()
            ->applyTo($configurator)
            ->build();
    }

    public static function ok<Ta>(Ta $actual) : void
    {
        try {
            EqualMatcher::of($actual)->match(true);
        } catch (AssertionFailedException $exception) {
            self::context()->reportFailedReason($exception);
        }
    }

    public static function equal<Ta, Te>(Ta $actual, Te $expected) : void
    {
        try {
            EqualMatcher::of($actual)->match($expected);
        } catch (AssertionFailedException $exception) {
            self::context()->reportFailedReason($exception);
        }
    }

    public static function context() : Context
    {
        if (self::$context === null) {
            self::$context = ContextBuilder::create()->build();
        }
        return self::$context;
    }

}
