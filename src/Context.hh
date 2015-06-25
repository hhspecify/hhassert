<?hh //strict

namespace hhassert;

interface Context
{
    public function delegate(string $key, array<mixed> $args) : void;
    public function reportFailedReason(AssertionFailedException $exception) : void;
}
