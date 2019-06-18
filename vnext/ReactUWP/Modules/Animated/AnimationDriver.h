#pragma once

#include "pch.h"
#include "ValueAnimatedNode.h"
#include <folly/dynamic.h>

namespace react {
  namespace uwp {

    typedef std::function<void(std::vector<folly::dynamic>)> Callback;

    class ValueAnimatedNode;
    class AnimationDriver
    {
    public:
      AnimationDriver(int64_t id, std::shared_ptr<ValueAnimatedNode> animatedValue, Callback endCallback);

      inline constexpr int64_t Id() { return m_id; };

    protected:
      int64_t m_id{ 0 };
      std::shared_ptr<ValueAnimatedNode> m_animatedValue{};
      Callback m_endCallback{};
      int64_t m_iterations{ 0 };

      winrt::CompositionAnimation m_animation{ nullptr };
      //auto revoker for scopedBatch.Completed is broken.
      winrt::event_token m_scopedBatchCompletedToken{};
    };
  }
}
