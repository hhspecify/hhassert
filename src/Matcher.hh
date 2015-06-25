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

interface Matcher
{
    public function match<To>(To $other) : void;
}
