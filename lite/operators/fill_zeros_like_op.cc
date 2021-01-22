// Copyright (c) 2019 PaddlePaddle Authors. All Rights Reserved.
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

#include "lite/operators/fill_zeros_like_op.h"
#include "lite/core/op_registry.h"

namespace paddle {
namespace lite {
namespace operators {

bool FillZerosLikeOp::InferShapeImpl() const {
  param_.Out->Resize(param_.X->dims());
  return true;
}

bool FillZerosLikeOp::AttachImpl(const cpp::OpDesc& opdesc,
                                 lite::Scope* scope) {
  param_.X = scope->FindVar(opdesc.Input("X").front())->GetMutable<Tensor>();
  auto out_name = opdesc.Output("Out").front();
  param_.Out = GetMutableVar<lite::Tensor>(scope, out_name);
  param_.value = 0.f;
  return true;
}

}  // namespace operators
}  // namespace lite
}  // namespace paddle

REGISTER_LITE_OP(fill_zeros_like, paddle::lite::operators::FillZerosLikeOp);
