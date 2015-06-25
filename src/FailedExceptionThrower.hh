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

class FailedExceptionThrower implements FailedSubscriber
{

    public function receive(AssertionFailedException $failedReason) : void
    {
        throw $failedReason;
    }

}
