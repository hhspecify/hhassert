<?hh //strict

namespace hhassert;

class AssertContext implements Context
{

    public function __construct(
        private FailedSubscriber $reporter
    )
    {
    }

    public function reportFailedReason(AssertionFailedException $exception) : void
    {
        $exception->sendTo($this->reporter);
    }

}
