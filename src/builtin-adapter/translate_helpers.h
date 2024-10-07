// Copyright 2024 The AI Edge Model Explorer Authors.
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
// =============================================================================

#ifndef TENSORFLOW_COMPILER_MLIR_LITE_EXPERIMENTAL_GOOGLE_TOOLING_TRANSLATE_HELPERS_H_
#define TENSORFLOW_COMPILER_MLIR_LITE_EXPERIMENTAL_GOOGLE_TOOLING_TRANSLATE_HELPERS_H_

#include "absl/status/statusor.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/IR/Value.h"
#include "formats/schema_structs.h"
#include "visualize_config.h"

namespace tooling {
namespace visualization_client {

// Converts a tf dialect function op to a subgraph.
absl::StatusOr<Subgraph> TfFunctionToSubgraph(const VisualizeConfig& config,
                                              mlir::func::FuncOp& fop);

// Converts a tfl dialect function op to a subgraph.
absl::StatusOr<Subgraph> TfliteFunctionToSubgraph(const VisualizeConfig& config,
                                                  mlir::func::FuncOp& fop);

// Converts a stablehlo dialect function op to a subgraph.
absl::StatusOr<Subgraph> StablehloFunctionToSubgraph(
    const VisualizeConfig& config, mlir::func::FuncOp& fop);

// Converts a tf dialect MLIR module to a JSON graph.
absl::StatusOr<Graph> TfMlirToGraph(const VisualizeConfig& config,
                                    mlir::Operation* module);

// Converts a tfl dialect MLIR module to a JSON graph.
absl::StatusOr<Graph> TfliteMlirToGraph(const VisualizeConfig& config,
                                        mlir::Operation* module);

// Converts a JAX-converted tf & stablehlo MLIR module to a JSON graph.
absl::StatusOr<Graph> JaxConvertedMlirToGraph(const VisualizeConfig& config,
                                              mlir::Operation* module);

}  // namespace visualization_client
}  // namespace tooling

#endif  // TENSORFLOW_COMPILER_MLIR_LITE_EXPERIMENTAL_GOOGLE_TOOLING_TRANSLATE_HELPERS_H_
