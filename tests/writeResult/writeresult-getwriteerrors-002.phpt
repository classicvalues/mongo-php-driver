--TEST--
MongoDB\Driver\WriteResult::getWriteErrors() with unordered execution
--SKIPIF--
<?php require __DIR__ . "/../utils/basic-skipif.inc"; ?>
<?php NEEDS('STANDALONE'); CLEANUP(STANDALONE); ?>
--FILE--
<?php
require_once __DIR__ . "/../utils/basic.inc";

$manager = new MongoDB\Driver\Manager(STANDALONE);

$bulk = new MongoDB\Driver\BulkWrite(['ordered' => false]);
$bulk->insert(['_id' => 1]);
$bulk->insert(['_id' => 2]);
$bulk->insert(['_id' => 2]);
$bulk->insert(['_id' => 3]);
$bulk->insert(['_id' => 4]);
$bulk->insert(['_id' => 4]);

try {
    $result = $manager->executeBulkWrite(NS, $bulk);
} catch (MongoDB\Driver\Exception\BulkWriteException $e) {
    var_dump($e->getWriteResult()->getWriteErrors());
}

?>
===DONE===
<?php exit(0); ?>
--EXPECTF--
array(2) {
  [0]=>
  object(MongoDB\Driver\WriteError)#%d (%d) {
    ["message"]=>
    string(%d) "E11000 duplicate key error %s: phongo.writeResult_writeresult_getwriteerrors_002%sdup key: { : 2 }"
    ["code"]=>
    int(11000)
    ["index"]=>
    int(2)
    ["info"]=>
    NULL
  }
  [1]=>
  object(MongoDB\Driver\WriteError)#%d (%d) {
    ["message"]=>
    string(%d) "E11000 duplicate key error %s: phongo.writeResult_writeresult_getwriteerrors_002%sdup key: { : 4 }"
    ["code"]=>
    int(11000)
    ["index"]=>
    int(5)
    ["info"]=>
    NULL
  }
}
===DONE===
