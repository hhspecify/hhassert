<?hh //strict

namespace hhassert;

class AssertContext implements Context
{

    public function __construct(
        private FailedSubscriber $reporter,
        private MatcherRegistry $registry
    )
    {
    }

    public function delegate(string $key, array<mixed> $args) : mixed
    {
        $matcher = $this->registry->at($key);
        return call_user_func_array($matcher, $args);
    }

    public function reportFailedReason(AssertionFailedException $exception) : void
    {
        $exception->sendTo($this->reporter);
    }

}
