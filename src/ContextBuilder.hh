<?hh //strict

namespace hhassert;

class ContextBuilder
{

    public function __construct(
        private FailedSubscriber $reporter
    )
    {
    }

    public static function create() : ContextBuilder
    {
        return new ContextBuilder(
            new FailedExceptionThrower()
        );
    }

    public function applyTo(Configurator $configurator) : this
    {
        $configurator($this);
        return $this;
    }

    public function build() : Context
    {
        return new AssertContext($this->reporter);
    }

}
