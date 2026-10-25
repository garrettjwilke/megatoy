#pragma once

#include "ym2612/chip.hpp"
#include <cstdint>
#include <memory>

namespace ym2612 {

/**
 * ymfm's YM2612-family cores.
 *
 * ymfm's headers are template-heavy, so the chip instance lives behind a
 * pimpl and is compiled in exactly one translation unit.
 */
class YmfmChip final : public Chip {
public:
  explicit YmfmChip(uint32_t clock);
  ~YmfmChip() override;

  YmfmChip(const YmfmChip &) = delete;
  YmfmChip &operator=(const YmfmChip &) = delete;

  uint32_t native_sample_rate() const override;

  ChipType chip_type() const override;
  void set_chip_type(ChipType type) override;

  void reset() override;

  void write(uint8_t offset, uint8_t data) override;

  uint8_t read(uint8_t offset) override;

  void render(int32_t *left, int32_t *right, uint32_t frames) override;

private:
  struct Impl;
  std::unique_ptr<Impl> impl_;
};

} // namespace ym2612
