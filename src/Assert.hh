<?hh //strict

/**
 * This file is part of hhassert.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhassert;

use hhassert\matcher\EqualMatcher;
use hhassert\matcher\NotEqualMatcher;
use hhassert\matcher\ThrowsMatcher;

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

    public static function notEqual<Ta, Te>(Ta $actual, Te $expected) : void
    {
        try {
            NotEqualMatcher::of($actual)->match($expected);
        } catch (AssertionFailedException $exception) {
            self::context()->reportFailedReason($exception);
        }
    }

    public static function throws(ThrowsCallback $callback, string $exceptionType) : void
    {
        try {
            ThrowsMatcher::of($callback)->match($exceptionType);
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

    public static function __callStatic(string $key, array<mixed> $args) : void
    {
        if (method_exists(self::class, $key)) {
            call_user_func_array([ self::class, $key ], $args);
            return;
        }

        try {
            self::context()->delegate($key, $args);
        } catch (AssertionFailedException $exception) {
            self::context()->reportFailedReason($exception);
        }
    }

}
