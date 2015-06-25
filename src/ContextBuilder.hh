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

class ContextBuilder
{

    public function __construct(
        private FailedSubscriber $reporter,
        private MatcherRegistry $matchers
    )
    {
    }

    public static function create() : ContextBuilder
    {
        return new ContextBuilder(
            new FailedExceptionThrower(),
            Map {}
        );
    }

    public function applyTo(Configurator $configurator) : this
    {
        $configurator($this);
        return $this;
    }

    public function registerMatcher(string $key, MatcherCallback $matcher) : this
    {
        $this->matchers->set($key, $matcher);
        return $this;
    }

    public function failedReporter(FailedSubscriber $reporter) : this
    {
        $this->reporter = $reporter;
        return $this;
    }

    public function build() : Context
    {
        return new AssertContext($this->reporter, $this->matchers);
    }

}
