// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once
#include <folly/dynamic.h>
#include "AnimatedNode.h"
#include "AnimationDriver.h"

namespace react {
namespace uwp {
class DecayAnimationDriver : public AnimationDriver {
 public:
  DecayAnimationDriver(
      int64_t id,
      int64_t animatedValueTag,
      const Callback &endCallback,
      const folly::dynamic &config,
      const std::shared_ptr<NativeAnimatedNodeManager> &manager);

  std::tuple<winrt::CompositionAnimation, winrt::CompositionScopedBatch>
  MakeAnimation(const folly::dynamic &config) override;

  double ToValue() override;

 private:
  double m_velocity{0};
  double m_deceleration{0};

  static constexpr std::string_view s_velocityName{"velocity"};
  static constexpr std::string_view s_decelerationName{"deceleration"};

  static constexpr std::wstring_view s_velocityParameterName{L"velocity"};
  static constexpr std::wstring_view s_decelerationParameterName{
      L"deceleration"};
  static constexpr std::wstring_view s_durationName{L"duration"};
};
} // namespace uwp
} // namespace react
