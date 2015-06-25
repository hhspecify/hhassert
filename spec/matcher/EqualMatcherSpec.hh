<?hh //partial

use hhassert\matcher\EqualMatcher;

describe(EqualMatcher::class, function() {
    describe('match', function() {
        context('when matched', function() {
            beforeEach(function() {
                $this->matcher = new EqualMatcher("foo");
            });
            it('returns true', function() {
                expect($this->matcher->match("foo"))->toBeTrue();
            });
        });
    });
});
