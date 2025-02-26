/*
 * Copyright 2014-present MongoDB, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <php.h>
#include <Zend/zend_interfaces.h>
#include <ext/standard/php_var.h>
#include <zend_smart_str.h>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "phongo_compat.h"
#include "php_phongo.h"

zend_class_entry* php_phongo_maxkey_ce;

/* {{{ proto MongoDB\BSON\MaxKey MongoDB\BSON\MaxKey::__set_state(array $properties)
*/
static PHP_METHOD(MaxKey, __set_state)
{
	zend_error_handling error_handling;
	zval*               array;

	zend_replace_error_handling(EH_THROW, phongo_exception_from_phongo_domain(PHONGO_ERROR_INVALID_ARGUMENT), &error_handling);
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "a", &array) == FAILURE) {
		zend_restore_error_handling(&error_handling);
		return;
	}
	zend_restore_error_handling(&error_handling);

	object_init_ex(return_value, php_phongo_maxkey_ce);
} /* }}} */

/* {{{ proto array MongoDB\BSON\MaxKey::jsonSerialize()
*/
static PHP_METHOD(MaxKey, jsonSerialize)
{
	zend_error_handling error_handling;

	zend_replace_error_handling(EH_THROW, phongo_exception_from_phongo_domain(PHONGO_ERROR_INVALID_ARGUMENT), &error_handling);
	if (zend_parse_parameters_none() == FAILURE) {
		zend_restore_error_handling(&error_handling);
		return;
	}
	zend_restore_error_handling(&error_handling);

	array_init_size(return_value, 1);
	ADD_ASSOC_LONG_EX(return_value, "$maxKey", 1);
} /* }}} */

/* {{{ proto string MongoDB\BSON\MaxKey::serialize()
*/
static PHP_METHOD(MaxKey, serialize)
{
	zend_error_handling error_handling;

	zend_replace_error_handling(EH_THROW, phongo_exception_from_phongo_domain(PHONGO_ERROR_INVALID_ARGUMENT), &error_handling);
	if (zend_parse_parameters_none() == FAILURE) {
		zend_restore_error_handling(&error_handling);
		return;
	}
	zend_restore_error_handling(&error_handling);

	RETURN_STRING("");
} /* }}} */

/* {{{ proto void MongoDB\BSON\MaxKey::unserialize(string $serialized)
*/
static PHP_METHOD(MaxKey, unserialize)
{
	zend_error_handling error_handling;
	char*               serialized;
	size_t              serialized_len;

	zend_replace_error_handling(EH_THROW, phongo_exception_from_phongo_domain(PHONGO_ERROR_INVALID_ARGUMENT), &error_handling);
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &serialized, &serialized_len) == FAILURE) {
		zend_restore_error_handling(&error_handling);
		return;
	}
	zend_restore_error_handling(&error_handling);
} /* }}} */

/* {{{ proto array MongoDB\Driver\MaxKey::__serialize()
*/
static PHP_METHOD(MaxKey, __serialize)
{
	PHONGO_PARSE_PARAMETERS_NONE();

	array_init_size(return_value, 0);
} /* }}} */

/* {{{ proto void MongoDB\Driver\MaxKey::__unserialize(array $data)
*/
static PHP_METHOD(MaxKey, __unserialize)
{
	zval* data;

	PHONGO_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_ARRAY(data)
	PHONGO_PARSE_PARAMETERS_END();
} /* }}} */

/* {{{ MongoDB\BSON\MaxKey function entries */
/* clang-format off */
ZEND_BEGIN_ARG_INFO_EX(ai_MaxKey___set_state, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, properties, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(ai_MaxKey___unserialize, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_TENTATIVE_RETURN_TYPE_INFO_EX(ai_MaxKey_jsonSerialize, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(ai_MaxKey_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, serialized)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(ai_MaxKey_void, 0, 0, 0)
ZEND_END_ARG_INFO()

static zend_function_entry php_phongo_maxkey_me[] = {
	PHP_ME(MaxKey, __serialize, ai_MaxKey_void, ZEND_ACC_PUBLIC | ZEND_ACC_FINAL)
	PHP_ME(MaxKey, __set_state, ai_MaxKey___set_state, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_ME(MaxKey, __unserialize, ai_MaxKey___unserialize, ZEND_ACC_PUBLIC | ZEND_ACC_FINAL)
	PHP_ME(MaxKey, jsonSerialize, ai_MaxKey_jsonSerialize, ZEND_ACC_PUBLIC | ZEND_ACC_FINAL)
	PHP_ME(MaxKey, serialize, ai_MaxKey_void, ZEND_ACC_PUBLIC | ZEND_ACC_FINAL)
	PHP_ME(MaxKey, unserialize, ai_MaxKey_unserialize, ZEND_ACC_PUBLIC | ZEND_ACC_FINAL)
	PHP_FE_END
};
/* clang-format on */
/* }}} */

/* {{{ MongoDB\BSON\MaxKey object handlers */
static zend_object_handlers php_phongo_handler_maxkey;

static void php_phongo_maxkey_free_object(zend_object* object) /* {{{ */
{
	php_phongo_maxkey_t* intern = Z_OBJ_MAXKEY(object);

	zend_object_std_dtor(&intern->std);
} /* }}} */

static zend_object* php_phongo_maxkey_create_object(zend_class_entry* class_type) /* {{{ */
{
	php_phongo_maxkey_t* intern = NULL;

	intern = PHONGO_ALLOC_OBJECT_T(php_phongo_maxkey_t, class_type);
	zend_object_std_init(&intern->std, class_type);
	object_properties_init(&intern->std, class_type);

	intern->std.handlers = &php_phongo_handler_maxkey;

	return &intern->std;
} /* }}} */
/* }}} */

void php_phongo_maxkey_init_ce(INIT_FUNC_ARGS) /* {{{ */
{
	zend_class_entry ce;

	INIT_NS_CLASS_ENTRY(ce, "MongoDB\\BSON", "MaxKey", php_phongo_maxkey_me);
	php_phongo_maxkey_ce                = zend_register_internal_class(&ce);
	php_phongo_maxkey_ce->create_object = php_phongo_maxkey_create_object;
	PHONGO_CE_FINAL(php_phongo_maxkey_ce);

	zend_class_implements(php_phongo_maxkey_ce, 1, php_phongo_maxkey_interface_ce);
	zend_class_implements(php_phongo_maxkey_ce, 1, php_phongo_json_serializable_ce);
	zend_class_implements(php_phongo_maxkey_ce, 1, php_phongo_type_ce);
	zend_class_implements(php_phongo_maxkey_ce, 1, zend_ce_serializable);

	memcpy(&php_phongo_handler_maxkey, phongo_get_std_object_handlers(), sizeof(zend_object_handlers));
	/* Re-assign default handler previously removed in php_phongo.c */
	php_phongo_handler_maxkey.clone_obj = zend_objects_clone_obj;
	php_phongo_handler_maxkey.free_obj  = php_phongo_maxkey_free_object;
	php_phongo_handler_maxkey.offset    = XtOffsetOf(php_phongo_maxkey_t, std);
} /* }}} */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
