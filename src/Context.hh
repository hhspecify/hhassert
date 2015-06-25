<?hh //strict

namespace hhassert;

interface Context
{
    public function reportFailedReason(AssertionFailedException $exception) : void;
}
