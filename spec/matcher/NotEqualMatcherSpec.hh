<?hh //partial

use hhassert\AssertionFailedException;
use hhassert\matcher\NotEqualMatcher;

describe(NotEqualMatcher::class, function() {
    describe('match', function() {
        context('when matched', function() {
            beforeEach(function() {
                $this->matcher = new NotEqualMatcher("foo");
            });
            it('not thrown assertion exception', function() {
                expect(() ==> $this->matcher->match("bar"))
                    ->not()->toThrow(AssertionFailedException::class);
            });
        });
    });
});
