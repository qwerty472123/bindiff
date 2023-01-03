// Copyright 2011-2023 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef MATCH_BASIC_BLOCK_PRIME_H_
#define MATCH_BASIC_BLOCK_PRIME_H_

#include "third_party/absl/strings/str_cat.h"
#include "third_party/zynamics/bindiff/match/flow_graph.h"

namespace security::bindiff {

// Matches basic blocks based on instruction prime product. Only used on basic
// blocks with a minimum number of specified instructions.
class MatchingStepPrimeBasicBlock : public MatchingStepFlowGraph {
 public:
  explicit MatchingStepPrimeBasicBlock(int min_instructions)
      : MatchingStepFlowGraph(
            absl::StrCat("basicBlock: prime matching (", min_instructions,
                         " instructions minimum)"),
            absl::StrCat("Basic Block: Primes (", min_instructions,
                         " Instructions Minimum)")),
        min_instructions_(min_instructions) {}

  bool FindFixedPoints(FlowGraph* primary, FlowGraph* secondary,
                       const VertexSet& vertices1, const VertexSet& vertices2,
                       FixedPoint* fixed_point, MatchingContext* context,
                       MatchingStepsFlowGraph* matching_steps) override;

 private:
  void GetUnmatchedBasicBlocksByPrime(const FlowGraph* flow_graph,
                                      const VertexSet& vertices,
                                      VertexIntMap* basic_blocks_map);

  int min_instructions_;
};

}  // namespace security::bindiff

#endif  // MATCH_BASIC_BLOCK_PRIME_H_
