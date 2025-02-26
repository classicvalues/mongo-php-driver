--TEST--
MongoDB\BSON\Javascript serialization (__serialize and __unserialize)
--SKIPIF--
<?php require __DIR__ . "/../utils/basic-skipif.inc"; ?>
<?php skip_if_php_version('<', '7.4.0'); ?>
--FILE--
<?php

$tests = [
    ['function foo(bar) { return bar; }', null],
    ['function foo(bar) { return bar; }', []],
    ['function foo() { return foo; }', ['foo' => 42]],
    ['function foo() { return id; }', ['id' => new MongoDB\BSON\ObjectId('53e2a1c40640fd72175d4603')]],
];

foreach ($tests as $test) {
    list($code, $scope) = $test;

    var_dump($js = new MongoDB\BSON\Javascript($code, $scope));
    var_dump($s = serialize($js));
    var_dump(unserialize($s));
    echo "\n";
}

?>
===DONE===
<?php exit(0); ?>
--EXPECTF--
object(MongoDB\BSON\Javascript)#%d (%d) {
  ["code"]=>
  string(33) "function foo(bar) { return bar; }"
  ["scope"]=>
  NULL
}
string(101) "O:23:"MongoDB\BSON\Javascript":2:{s:4:"code";s:33:"function foo(bar) { return bar; }";s:5:"scope";N;}"
object(MongoDB\BSON\Javascript)#%d (%d) {
  ["code"]=>
  string(33) "function foo(bar) { return bar; }"
  ["scope"]=>
  NULL
}

object(MongoDB\BSON\Javascript)#%d (%d) {
  ["code"]=>
  string(33) "function foo(bar) { return bar; }"
  ["scope"]=>
  object(stdClass)#%d (%d) {
  }
}
string(118) "O:23:"MongoDB\BSON\Javascript":2:{s:4:"code";s:33:"function foo(bar) { return bar; }";s:5:"scope";O:8:"stdClass":0:{}}"
object(MongoDB\BSON\Javascript)#%d (%d) {
  ["code"]=>
  string(33) "function foo(bar) { return bar; }"
  ["scope"]=>
  object(stdClass)#%d (%d) {
  }
}

object(MongoDB\BSON\Javascript)#%d (%d) {
  ["code"]=>
  string(30) "function foo() { return foo; }"
  ["scope"]=>
  object(stdClass)#%d (%d) {
    ["foo"]=>
    int(42)
  }
}
string(130) "O:23:"MongoDB\BSON\Javascript":2:{s:4:"code";s:30:"function foo() { return foo; }";s:5:"scope";O:8:"stdClass":1:{s:3:"foo";i:42;}}"
object(MongoDB\BSON\Javascript)#%d (%d) {
  ["code"]=>
  string(30) "function foo() { return foo; }"
  ["scope"]=>
  object(stdClass)#%d (%d) {
    ["foo"]=>
    int(42)
  }
}

object(MongoDB\BSON\Javascript)#%d (%d) {
  ["code"]=>
  string(29) "function foo() { return id; }"
  ["scope"]=>
  object(stdClass)#%d (%d) {
    ["id"]=>
    object(MongoDB\BSON\ObjectId)#%d (%d) {
      ["oid"]=>
      string(24) "53e2a1c40640fd72175d4603"
    }
  }
}
string(198) "O:23:"MongoDB\BSON\Javascript":2:{s:4:"code";s:29:"function foo() { return id; }";s:5:"scope";O:8:"stdClass":1:{s:2:"id";O:21:"MongoDB\BSON\ObjectId":1:{s:3:"oid";s:24:"53e2a1c40640fd72175d4603";}}}"
object(MongoDB\BSON\Javascript)#%d (%d) {
  ["code"]=>
  string(29) "function foo() { return id; }"
  ["scope"]=>
  object(stdClass)#%d (%d) {
    ["id"]=>
    object(MongoDB\BSON\ObjectId)#%d (%d) {
      ["oid"]=>
      string(24) "53e2a1c40640fd72175d4603"
    }
  }
}

===DONE===
