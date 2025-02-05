#
# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

add_executable(hdfs_tool_tests
                hdfs-allow-snapshot-mock.cc
                hdfs-delete-snapshot-mock.cc
                hdfs-cat-mock.cc
                hdfs-tool-test-fixtures.cc
                hdfs-tool-tests.cc
                main.cc)
target_include_directories(hdfs_tool_tests PRIVATE
                            ../tools
                            ../../tools
                            ../../tools/hdfs-allow-snapshot
                            ../../tools/hdfs-delete-snapshot
                            ../../tools/hdfs-cat)
target_link_libraries(hdfs_tool_tests PRIVATE
                       gmock_main
                       hdfs_allowSnapshot_lib
                       hdfs_deleteSnapshot_lib
                       hdfs_cat_lib)
add_test(hdfs_tool_tests hdfs_tool_tests)
