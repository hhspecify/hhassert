<?hh //strict

namespace hhassert\matcher;

use hhassert\Matcher;

class EqualMatcher<Ta> implements Matcher
{

    public function __construct(
        private Ta $actual
    )
    {
    }

    /**
     * <code>
     * $matcher = new EqualMatcher("foo");
     * $matcher->match("bar") //return false;
     * </code>
     */
    public function match<To>(To $other) : bool
    {
        return $this->actual === $other;
    }

}
