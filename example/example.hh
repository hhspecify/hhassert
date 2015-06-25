<?hh //partial

require_once __DIR__ . "/../vendor/autoload.php";

use hhassert\Assert;
use hhassert\FailedExceptionThrower;
use hhassert\ContextBuilder;

Assert::configure((ContextBuilder $builder) ==> {
    $builder->failedReporter(new FailedExceptionThrower());
});

Assert::equal("a", "a");
