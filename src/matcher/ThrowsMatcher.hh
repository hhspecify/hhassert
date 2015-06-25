<?hh //strict

namespace hhassert\matcher;

use hhassert\Matcher;
use hhassert\AssertionFailedException;
use \Exception;


class ThrowsMatcher implements Matcher
{

    private ?Exception $actual;
    private string $expected;

    public function __construct(
        private ThrowsCallback $callback
    )
    {
        $this->expected = Exception::class;
    }

    public static function of(ThrowsCallback $callback) : ThrowsMatcher
    {
        return new self($callback);
    }

    public function match<To>(To $other) : void
    {
        $this->expected = (string) $other;

        try {
            $callback = $this->callback;
            $callback();
        } catch (\Exception $exception) {
            $this->actual = $exception;
        }

        if ($this->actual instanceof $this->expected) {
            return;
        }

        $this->throwFailedException();
    }

    private function throwFailedException() : void
    {
        $actual = Value::of($this->actual);
        $expected = Value::of($this->expected);

$failedMessage = <<<MSG


AssertionError: $actual instanceof $expected

    expected: $expected
         got: $actual


MSG;

        throw new AssertionFailedException($failedMessage);
    }

}
