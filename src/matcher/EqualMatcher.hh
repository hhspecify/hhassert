<?hh //strict

namespace hhassert\matcher;

use hhassert\Matcher;
use hhassert\ExceptionThrower;
use hhassert\AssertionFailedException;

class EqualMatcher implements Matcher, ExceptionThrower
{

    private mixed $expected;

    public function __construct(
        private mixed $actual
    )
    {
        $this->expected = null;
    }

    /**
     * <code>
     * $matcher = new EqualMatcher("foo");
     * $matcher->match("bar") //return false;
     * </code>
     */
    public function match<To>(To $other) : bool
    {
        $this->expected = $other;
        return $this->actual === $this->expected;
    }

    public function throwFailedException() : void
    {
        $actual = Value::of($this->actual);
        $expected = Value::of($this->expected);

$failedMessage = <<<MSG


AssertionError: $actual === $expected

    expected: $expected
         got: $actual


MSG;

        throw new AssertionFailedException($failedMessage);
    }

}
