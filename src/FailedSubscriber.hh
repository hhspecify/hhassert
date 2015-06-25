<?hh //strict

namespace hhassert;

interface FailedSubscriber
{
    public function receive(AssertionFailedException $failedReason) : void;
}
