<?hh //strict

/**
 * This file is part of hhassert.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

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
