<?hh //strict

namespace hhassert;

interface Matcher
{
    public function match<To>(To $other) : bool;
}
