/**************************************************************************//**
 * @file     main.c
 * @brief    Unit test example using Unity
 * @version  V1.0.0
 * @date     04. June 2024
 ******************************************************************************/
/*
 * Copyright (c) 2017-2023 ARM Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "RTE_Components.h"
#include  CMSIS_device_header
#include "cmsis_os2.h"
#ifdef RTE_Compiler_EventRecorder
#include "EventRecorder.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include "unity.h"

/* Application function to test */
static int my_sum(int a, int b) {
  return a + b;
}

/*============= UNIT TESTS ============== */

/* Called in RUN_TEST before executing test function */
void setUp(void) {
  // set stuff up here
}

/* Called in RUN_TEST after executing test function */
void tearDown(void) {
  // clean stuff up here
}

/* Testing summation of positive integers */
static void test_my_sum_pos(void) {
  const int sum = my_sum(1, 1);
  TEST_ASSERT_EQUAL_INT(2, sum);
}

/* Testing summation of negative integers */
static void test_my_sum_neg(void) {
  const int sum = my_sum(-1, -1);
  TEST_ASSERT_EQUAL_INT(-2, sum);
}

/* Testing summation of zeros */
static void test_my_sum_zero(void) {
  const int sum = my_sum(0, 0);
  TEST_ASSERT_EQUAL_INT(0, sum);
}

/* Failing test with incorrect summation value */
static void test_my_sum_fail(void) {
  const int sum = my_sum(1, -1);
  TEST_ASSERT_EQUAL_INT(2, sum);
}

/*---------------------------------------------------------------------------
 * Application main thread
 *---------------------------------------------------------------------------*/

static void app_main (void *argument) {
  (void)argument;

  printf("---[ UNITY BEGIN ]---\n");
  UNITY_BEGIN();
  RUN_TEST(test_my_sum_pos);
  RUN_TEST(test_my_sum_neg);
  RUN_TEST(test_my_sum_fail);
  RUN_TEST(test_my_sum_zero);
  const int result = UNITY_END();
  printf("---[ UNITY END ]---\n");

  osThreadExit();
}

/*---------------------------------------------------------------------------
 * Application initialization
 *---------------------------------------------------------------------------*/
static void app_initialize (void) {
  osThreadNew(app_main, NULL, NULL);
}


/*---------------------------------------------------------------------------
 * C main
 *---------------------------------------------------------------------------*/
int main (void) {

#if defined(RTE_Compiler_EventRecorder) && \
    (defined(__MICROLIB) || \
    !(defined(RTE_CMSIS_RTOS2_RTX5) || defined(RTE_CMSIS_RTOS2_FreeRTOS)))
  EventRecorderInitialize(EventRecordAll, 1U);
#endif

  osKernelInitialize();                 // Initialize CMSIS-RTOS2
  app_initialize();                     // Initialize application
  osKernelStart();                      // Start thread execution

  for (;;) {}
}


