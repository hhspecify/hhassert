<?hh //strict

/**
 * This file is part of hhassert.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhassert\matcher;

use hhassert\Matcher;
use hhassert\AssertionFailedException;

class NotEqualMatcher<Ta> implements Matcher
{

    private mixed $expected;

    public function __construct(
        private Ta $actual
    )
    {
        $this->expected = null;
    }

    public static function of(Ta $actual) : NotEqualMatcher<Ta>
    {
        return new self($actual);
    }

    public function match<To>(To $other) : void
    {
        $this->expected = $other;

        if ($this->actual !== $this->expected) {
            return;
        }

        $this->throwFailedException();
    }

    private function throwFailedException() : void
    {
        $actual = Value::of($this->actual);
        $expected = Value::of($this->expected);

$failedMessage = <<<MSG


AssertionError: $actual !== $expected

    expected: $expected
         got: $actual


MSG;

        throw new AssertionFailedException($failedMessage);
    }

}
