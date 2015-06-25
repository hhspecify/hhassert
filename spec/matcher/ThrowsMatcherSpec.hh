<?hh //partial

use hhassert\AssertionFailedException;
use hhassert\matcher\ThrowsMatcher;
use \InvalidArgumentException;

describe(ThrowsMatcher::class, function() {
    describe('match', function() {
        context('when matched', function() {
            beforeEach(function() {
                $this->matcher = new ThrowsMatcher(() ==> {
                    throw new InvalidArgumentException("faild!!");
                });
            });
            it('not thrown assertion exception', function() {
                expect(() ==> {
                    $this->matcher->match(InvalidArgumentException::class);
                })->not()->toThrow(AssertionFailedException::class);
            });
        });
    });
});
