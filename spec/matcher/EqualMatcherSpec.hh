<?hh //partial

use hhassert\AssertionFailedException;
use hhassert\matcher\EqualMatcher;

describe(EqualMatcher::class, function() {
    describe('match', function() {
        context('when matched', function() {
            beforeEach(function() {
                $this->matcher = new EqualMatcher("foo");
            });
            it('not thrown assertion exception', function() {
                expect(() ==> $this->matcher->match("foo"))
                    ->not()->toThrow(AssertionFailedException::class);
            });
        });
    });
});
