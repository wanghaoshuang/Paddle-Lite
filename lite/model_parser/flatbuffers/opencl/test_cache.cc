// Copyright (c) 2020 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <gflags/gflags.h>
#include <gtest/gtest.h>
#include "lite/model_parser/flatbuffers/opencl/cache.h"

namespace paddle {
namespace lite {
namespace fbs {
namespace opencl {

TEST(OpenCLCache, cache) {
  const std::map<std::string, std::vector<std::vector<int8_t>>> map{
      {"a", {{1, 2}, {3, 4}}}, {"b", {{5, 6}, {7, 8}}},
  };
  Cache cache_0{map};
  paddle::lite::model_parser::Buffer buffer;
  cache_0.CopyDataToBuffer(&buffer);

  Cache cache_1{buffer};
  CHECK(map == cache_1.GetBinaryMap());
}

}  // namespace opencl
}  // namespace fbs
}  // namespace lite
}  // namespace paddle
