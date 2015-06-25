<?hh //strict

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
