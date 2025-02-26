--TEST--
MongoDB\Driver\Session debug output (snapshot=true)
--SKIPIF--
<?php require __DIR__ . "/../utils/basic-skipif.inc"; ?>
<?php skip_if_not_libmongoc_crypto(); ?>
<?php skip_if_not_live(); ?>
<?php skip_if_server_version('<', '3.6'); ?>
--FILE--
<?php
require_once __DIR__ . "/../utils/basic.inc";

$manager = create_test_manager();
$session = $manager->startSession(['snapshot' => true]);

var_dump($session);

?>
===DONE===
<?php exit(0); ?>
--EXPECTF--
object(MongoDB\Driver\Session)#%d (%d) {
  ["logicalSessionId"]=>
  array(1) {
    ["id"]=>
    object(MongoDB\BSON\Binary)#%d (%d) {
      ["data"]=>
      string(16) "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
      ["type"]=>
      int(4)
    }
  }
  ["clusterTime"]=>
  NULL
  ["causalConsistency"]=>
  bool(false)
  ["snapshot"]=>
  bool(true)
  ["operationTime"]=>
  NULL
  ["server"]=>
  NULL
  ["inTransaction"]=>
  bool(false)
  ["transactionState"]=>
  string(4) "none"
  ["transactionOptions"]=>
  NULL
}
===DONE===
