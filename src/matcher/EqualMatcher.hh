<?hh //strict

namespace hhassert\matcher;

use hhassert\Matcher;
use hhassert\AssertionFailedException;

class EqualMatcher<Ta> implements Matcher
{

    private mixed $expected;

    public function __construct(
        private Ta $actual
    )
    {
        $this->expected = null;
    }

    public static function of(Ta $actual) : EqualMatcher<Ta>
    {
        return new self($actual);
    }

    /**
     * <code>
     * $matcher = new EqualMatcher("foo");
     * $matcher->match("bar");
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
