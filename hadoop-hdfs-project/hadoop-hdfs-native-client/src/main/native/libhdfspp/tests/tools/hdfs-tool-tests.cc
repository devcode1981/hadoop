/*
  Licensed to the Apache Software Foundation (ASF) under one
  or more contributor license agreements.  See the NOTICE file
  distributed with this work for additional information
  regarding copyright ownership.  The ASF licenses this file
  to you under the Apache License, Version 2.0 (the
  "License"); you may not use this file except in compliance
  with the License.  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing,
  software distributed under the License is distributed on an
  "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
  KIND, either express or implied.  See the License for the
  specific language governing permissions and limitations
  under the License.
*/

#include <gtest/gtest.h>

#include "hdfs-allow-snapshot-mock.h"
#include "hdfs-cat-mock.h"
#include "hdfs-delete-snapshot-mock.h"
#include "hdfs-tool-test-fixtures.h"
#include "hdfs-tool-tests.h"

/**
 * This file combines the test fixtures defined in {@file
 * hdfs-tool-test-fixtures.h} and the test cases defined in {@file
 * hdfs-tool-test.h} to yield the test suite.
 */

/**
 * This file combines the test fixtures defined in {@file
 * hdfs-tool-test-fixtures.h} and the test cases defined in {@file
 * hdfs-tool-test.h} to yield the test structure.
 */

INSTANTIATE_TEST_SUITE_P(
    HdfsAllowSnapshot, HdfsToolBasicTest,
    testing::Values(PassAPath<hdfs::tools::test::AllowSnapshotMock>,
                    CallHelp<hdfs::tools::test::AllowSnapshotMock>));

INSTANTIATE_TEST_SUITE_P(HdfsCat, HdfsToolBasicTest,
                         testing::Values(PassAPath<hdfs::tools::test::CatMock>,
                                         CallHelp<hdfs::tools::test::CatMock>));

INSTANTIATE_TEST_SUITE_P(
    HdfsDeleteSnapshot, HdfsToolBasicTest,
    testing::Values(CallHelp<hdfs::tools::test::DeleteSnapshotMock>,
                    Pass2Paths<hdfs::tools::test::DeleteSnapshotMock>));

INSTANTIATE_TEST_SUITE_P(
    HdfsAllowSnapshot, HdfsToolNegativeTestThrows,
    testing::Values(Pass2Paths<hdfs::tools::test::AllowSnapshotMock>));

INSTANTIATE_TEST_SUITE_P(
    HdfsCat, HdfsToolNegativeTestThrows,
    testing::Values(Pass2Paths<hdfs::tools::test::CatMock>));

INSTANTIATE_TEST_SUITE_P(
    HdfsDeleteSnapshot, HdfsToolNegativeTestNoThrow,
    testing::Values(PassAPath<hdfs::tools::test::DeleteSnapshotMock>));
