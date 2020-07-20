//
// Created by ELIO on 2020/7/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "json.h"

static int main_ret = 0;
static int test_count = 0;
static int test_pass = 0;

#define EXPECT_EQ_BASE(equality, expect, actual, format) \
    do{\
        test_count++;\
        if(equality){\
            test_pass++;\
        }\
        else{\
            fprintf(stderr,"%s:%d: expect: " format "actual: "format"\n",__FILE__,__LINE__,expect,actual);\
            main_ret=1;\
        }\
    }while(0)

#define EXPECT_EQ_INT(expect, actual) EXPECT_EQ_BASE((expect)==(actual),expect,actual,"%d")

static void test_parse_null() {
    json_value v;
    v.type = JSON_FALSE;
    EXPECT_EQ_INT(JSON_PARSE_OK, json_parse(&v, "null"));
    EXPECT_EQ_INT(JSON_NULL, json_get_type(&v));
}

static void test_parse_expect_value(){
    json_value v;
    v.type=JSON_FALSE;

    EXPECT_EQ_INT(JSON_PARSE_EXPECT_VALUE,json_parse(&v,""));
    EXPECT_EQ_INT(JSON_NULL,json_get_type(&v));


}