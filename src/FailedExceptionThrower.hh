<?hh //strict

namespace hhassert;

class FailedExceptionThrower implements FailedSubscriber
{

    public function receive(AssertionFailedException $failedReason) : void
    {
        throw $failedReason;
    }

}
