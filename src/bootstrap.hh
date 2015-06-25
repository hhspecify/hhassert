<?hh //strict

/**
 * This file is part of hhassert.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhassert
{
    type Configurator = (function(ContextBuilder):void);
    type ThrowsCallback = (function():void);
    type MatcherCallback = (function(...):mixed);
    type MatcherRegistry = Map<string, MatcherCallback>;
}

namespace hhassert\matcher
{
    type ThrowsCallback = (function():void);
}
