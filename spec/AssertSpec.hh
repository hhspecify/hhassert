<?hh //partial

use hhassert\Assert;
use hhassert\AssertionFailedException;
use hhassert\ContextBuilder;
use \Exception;
use \InvalidArgumentException;

describe(Assert::class, function() {
    describe('ok', function() {
        context('when not ok', function() {
            it('throw exception', function() {
                expect(() ==> {
                    Assert::ok(false);
                })->toThrow(AssertionFailedException::class);
            });
        });
    });
    describe('equal', function() {
        context('when not same value', function() {
            it('throw exception', function() {
                expect(() ==> {
                    Assert::equal("1", "2");
                })->toThrow(AssertionFailedException::class);
            });
        });
    });
    describe('notEqual', function() {
        context('when same value', function() {
            it('throw exception', function() {
                expect(() ==> {
                    Assert::notEqual("1", "1");
                })->toThrow(AssertionFailedException::class);
            });
        });
    });
    describe('throws', function() {
        context('when not throw exception', function() {
            it('throw exception', function() {
                expect(() ==> {
                    Assert::throws(() ==> new Exception("failed"), InvalidArgumentException::class);
                })->toThrow(AssertionFailedException::class);
            });
        });
    });
    describe('configure', function() {
        context('when register custom matcher', function() {
            beforeEach(function() {
                Assert::configure((ContextBuilder $builder) ==> {

                    $builder->registerMatcher('test', (...) ==> {
                        throw new AssertionFailedException("custom matcher");
                    });

                });
            });
            it('delegate to custom matcher', function() {
                expect(() ==> {
                    Assert::test();
                })->toThrow(AssertionFailedException::class);
            });
        });
    });
});
