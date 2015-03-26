#include <stdio.h>
#include <stdlib.h>

#include "list.h"

static void TEST_ASSERT_EQUALS_LIST_SIZE(const char* const test_name, list_size_type expected, list_size_type actual)
{
    if (expected == actual)
    {
        printf("%s ... SUCCESS\n", test_name);
    }
    else
    {
        printf("%s: %zu != %zu ... FAILED\n", test_name, expected, actual);
    }
}

static void TEST_ASSERT_EQUALS_LIST_VALUE(const char* const test_name, list_value_type expected, list_value_type actual)
{
    if (expected == actual)
    {
        printf("%s ... SUCCESS\n", test_name);
    }
    else
    {
        printf("%s: %d != %d ... FAILED\n", test_name, expected, actual);
    }
}

static void TEST_ASSERT_EQUALS_LIST_BOOL(const char* const test_name, list_bool_type expected, list_bool_type actual)
{
    if (expected == actual)
    {
        printf("%s ... SUCCESS\n", test_name);
    }
    else
    {
        printf("%s: %d != %d ... FAILED\n", test_name, expected, actual);
    }
}

/**
 * Test run for list implementation.
 *
 * \author	executor
 * \return	EXIT_SUCCESS
 */
int main()
{
    printf("LIST TEST\n");

    list l =
    { 0 };
    list_init(&l);
    TEST_ASSERT_EQUALS_LIST_SIZE("size", 0, list_size(&l));

    TEST_ASSERT_EQUALS_LIST_BOOL("empty", list_TRUE, list_empty(&l));
    TEST_ASSERT_EQUALS_LIST_VALUE("at(0)", list_NO_VALUE, list_at(&l, 0));

    for (list_size_type i = 0; i < 5; ++i)
    {
        list_push_back(&l, i);
        TEST_ASSERT_EQUALS_LIST_VALUE("at(i)", i, list_at(&l, i));
    }
    list_print(&l, "l=");
    TEST_ASSERT_EQUALS_LIST_SIZE("size", 5, list_size(&l));

    TEST_ASSERT_EQUALS_LIST_BOOL("remove(-1)", list_FALSE, list_remove(&l, -1));
    TEST_ASSERT_EQUALS_LIST_SIZE("size", 5, list_size(&l));

    TEST_ASSERT_EQUALS_LIST_BOOL("remove(0)", list_TRUE, list_remove(&l, 0));
    TEST_ASSERT_EQUALS_LIST_VALUE("at(0)", 1, list_at(&l, 0));
    TEST_ASSERT_EQUALS_LIST_SIZE("size", 4, list_size(&l));

    TEST_ASSERT_EQUALS_LIST_BOOL("remove(2)", list_TRUE, list_remove(&l, 2));
    TEST_ASSERT_EQUALS_LIST_VALUE("at(2)", 4, list_at(&l, 2));

    TEST_ASSERT_EQUALS_LIST_BOOL("remove(4)", list_TRUE, list_remove(&l, 4));
    TEST_ASSERT_EQUALS_LIST_VALUE("at(1)", 3, list_at(&l, 1));

    TEST_ASSERT_EQUALS_LIST_BOOL("remove(99)", list_FALSE, list_remove(&l, 44));
    TEST_ASSERT_EQUALS_LIST_BOOL("remove(3)", list_TRUE, list_remove(&l, 3));
    TEST_ASSERT_EQUALS_LIST_BOOL("remove(1)", list_TRUE, list_remove(&l, 1));
    TEST_ASSERT_EQUALS_LIST_BOOL("remove(99)", list_FALSE, list_remove(&l, 99));
    TEST_ASSERT_EQUALS_LIST_BOOL("empty", list_TRUE, list_empty(&l));

    for (list_size_type i = 0; i < 3; ++i)
    {
        list_push_back(&l, i);
        TEST_ASSERT_EQUALS_LIST_VALUE("at(i)", i, list_at(&l, i));
    }
    list_print(&l, "l=");
    list_clear(&l);
    TEST_ASSERT_EQUALS_LIST_SIZE("size", 0, list_size(&l));
    TEST_ASSERT_EQUALS_LIST_BOOL("empty", list_TRUE, list_empty(&l));

    list_push_back(&l, 1);
    TEST_ASSERT_EQUALS_LIST_SIZE("size", 1, list_size(&l));
    TEST_ASSERT_EQUALS_LIST_BOOL("empty", list_FALSE, list_empty(&l));

    return EXIT_SUCCESS;
}
