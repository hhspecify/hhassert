<?hh //strict

namespace hhassert
{
    type Configurator = (function(ContextBuilder):void);
    type ThrowsCallback = (function():void);
}

namespace hhassert\matcher
{
    type ThrowsCallback = (function():void);
}
