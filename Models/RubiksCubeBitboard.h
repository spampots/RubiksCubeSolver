#pragma once

#include "Rubiks.h"
#include <cstdint>
#include <array>
#include <functional> // for std::hash

class RubiksCubeBitboard : public RubiksCube {
public:
    static constexpr int NUM_STICKERS = 54;
    static constexpr int BITS_PER_STICKER = 3;
    static constexpr int NUM_BOARDS = (NUM_STICKERS * BITS_PER_STICKER + 63) / 64;

    RubiksCubeBitboard();

    // Color getter
    Color getColor(Face face, unsigned row, unsigned col) const override;

    // State check
    bool isSolved() const override;

    // Move operations (standard cube notation)
    RubiksCube& u() override;
    RubiksCube& u2() override;
    RubiksCube& uP() override;

    RubiksCube& d() override;
    RubiksCube& d2() override;
    RubiksCube& dP() override;

    RubiksCube& l() override;
    RubiksCube& l2() override;
    RubiksCube& lP() override;

    RubiksCube& r() override;
    RubiksCube& r2() override;
    RubiksCube& rP() override;

    RubiksCube& f() override;
    RubiksCube& f2() override;
    RubiksCube& fP() override;

    RubiksCube& b() override;
    RubiksCube& b2() override;
    RubiksCube& bP() override;

    // Comparison operator
    bool operator==(const RubiksCubeBitboard& other) const;

    // Assignment operator
    RubiksCubeBitboard& operator=(const RubiksCubeBitboard& other);

    // Hash function (for unordered_map/set)
    struct Hash {
        std::size_t operator()(const RubiksCubeBitboard& cube) const {
            uint64_t sum = 0;
            for (auto b : cube.boards) sum += b;
            return std::hash<uint64_t>{}(sum);
        }
    };

private:
    // Stores 162 bits for 54 stickers * 3 bits each
    std::array<uint64_t, NUM_BOARDS> boards;

    // Internal helpers
    int stickerIndex(Face face, unsigned row, unsigned col) const;
    void setSticker(int idx, uint8_t color);
    uint8_t getSticker(int idx) const;

    // Rotation helpers
    void rotateFace(Face face);
};
