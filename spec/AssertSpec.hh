<?hh //partial

use hhassert\Assert;
use hhassert\AssertionFailedException;

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
});
