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

class AssertContext implements Context
{

    public function __construct(
        private FailedSubscriber $reporter,
        private MatcherRegistry $registry
    )
    {
    }

    public function delegate(string $key, array<mixed> $args) : void
    {
        $matcher = $this->registry->at($key);
        call_user_func_array($matcher, $args);
    }

    public function reportFailedReason(AssertionFailedException $exception) : void
    {
        $exception->sendTo($this->reporter);
    }

}
