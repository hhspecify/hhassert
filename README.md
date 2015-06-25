hhassert
==============================================

**hhassert** is simple assertion library for [Hack](http://hacklang.org/).
You can use easily as assert module of nodejs.

[![Build Status](https://travis-ci.org/hhspecify/hhassert.svg?branch=master)](https://travis-ci.org/hhspecify/hhassert)

Basic Usage
----------------------------------------------

It will specify the **hhassert\Assert** in the use keyword.

```hack
use hhassert\Assert;

Assert::ok(1 === 1);      //Passed
Assert::ok("a" === "b");  //Failed

Assert::equal("a", "a");  //Passed
Assert::equal(1, 1);      //Passed
Assert::equal(1.0, 2.0);  //Failed

Assert::notEqual("a", "b"); //Passed
Assert::notEqual("a", "a"); //Failed

Assert::throws(() ==> {
    throw new InvalidArgumentException("exception!!");
}, InvalidArgumentException::class);
```

Run the test
----------------------------------------------

composer install
composer test
