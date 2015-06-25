<?hh //strict

namespace hhassert\matcher;

use hhassert\Matcher;
use hhassert\AssertionFailedException;

class EqualMatcher implements Matcher
{

    private mixed $expected;

    public function __construct(
        private mixed $actual
    )
    {
        $this->expected = null;
    }

    public static function of(mixed $actual) : EqualMatcher
    {
        return new self($actual);
    }

    /**
     * <code>
     * $matcher = new EqualMatcher("foo");
     * $matcher->match("bar") //return false;
     * </code>
     */
    public function match<To>(To $other) : void
    {
        $this->expected = $other;

        if ($this->actual === $this->expected) {
            return;
        }

        $this->throwFailedException();
    }

    private function throwFailedException() : void
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
