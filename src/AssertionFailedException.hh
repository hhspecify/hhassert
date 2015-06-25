<?hh //strict

namespace hhassert;

use \Exception;

final class AssertionFailedException extends Exception
{

    public function __construct(string $message, int $code = 0, ?Exception $previous = null)
    {
        parent::__construct($message, $code, $previous);
    }

    public function sendTo(FailedSubscriber $subscriber) : void
    {
        $subscriber->receive($this);
    }

}
