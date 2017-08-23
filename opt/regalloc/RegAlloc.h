/**
 * Copyright (c) 2017-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#pragma once

#include <cstdio>

#include "PassManager.h"

class RegAllocPass : public Pass {
 public:
  RegAllocPass() : Pass("RegAllocPass") {}
  virtual void configure_pass(const PassConfig& pc) override {
    pc.get("live_range_splitting", false, m_use_splitting);
    pc.get("spill_param_properly", false, m_spill_param_properly);
    pc.get("select_spill_later", false, m_select_spill_later);
  }
  virtual void run_pass(DexStoresVector&, ConfigFiles&, PassManager&) override;

 private:
  bool m_use_splitting = false;
  bool m_spill_param_properly = false;
  bool m_select_spill_later = false;
};
