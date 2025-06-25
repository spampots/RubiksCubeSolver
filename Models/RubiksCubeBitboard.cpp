#include "RubiksCubeBitboard.h"
#include "cassert"

RubiksCubeBitboard::RubiksCubeBitboard()
{
    for (int i = 0; i < NUM_STICKERS; i++)
    {
        setSticker(i, i / 9);
    }
}

int RubiksCubeBitboard::stickerIndex(Face face, unsigned row, unsigned col) const
{
    return 9 * static_cast<int>(face) + 3 * row + col;
}

void RubiksCubeBitboard::setSticker(int idx, uint8_t color)
{
    int bitIndex = idx * BITS_PER_STICKER;
    int boardIndex = bitIndex / 64;
    int offSet = bitIndex % 64;

    boards[boardIndex] &= ~(0b111ULL << offSet);

    boards[boardIndex] |= (static_cast<uint64_t>(color) & 0b111ULL) << offSet;
}

uint8_t RubiksCubeBitboard::getSticker(int idx) const
{
    int bitIndex = idx * BITS_PER_STICKER;
    int boardIndex = bitIndex / 64;
    int offset = bitIndex % 64;

    return (boards[boardIndex] >> offset) & 0b111ULL;
}

RubiksCube::Color RubiksCubeBitboard::getColor(Face face, unsigned row, unsigned col) const
{
    int idx = stickerIndex(face, row, col);
    return static_cast<Color>(getSticker(idx));
}

bool RubiksCubeBitboard::isSolved() const
{
    for (int f = 0; f < 6; ++f)
    {
        Color faceColor = getColor(static_cast<Face>(f), 0, 0);
        for (int i = 0; i < 9; ++i)
        {
            int row = i / 3;
            int col = i % 3;
            if (getColor(static_cast<Face>(f), row, col) != faceColor)
                return false;
        }
    }
    return true;
}

bool RubiksCubeBitboard::operator==(const RubiksCubeBitboard &other) const
{
    return boards == other.boards;
}

RubiksCubeBitboard &RubiksCubeBitboard::operator=(const RubiksCubeBitboard &other)
{
    if (this != &other)
    {
        boards = other.boards;
    }
    return *this;
}

void RubiksCubeBitboard::rotateFace(Face face)
{
    uint8_t old[9];
    for (int i = 0; i < 9; ++i) {
        int row = i / 3;
        int col = i % 3;
        old[i] = getSticker(stickerIndex(face, row, col));
    }

    // Mapping of index positions after rotation
    static const int clockwiseMap[9]     = {6, 3, 0, 7, 4, 1, 8, 5, 2};
    const int* map = clockwiseMap;

    // Apply mapping
    for (int i = 0; i < 9; ++i) {
        int row = i / 3;
        int col = i % 3;
        setSticker(stickerIndex(face, row, col), old[map[i]]);
    }
}

RubiksCube &RubiksCubeBitboard::u()
{
    rotateFace(Face::Up);
    // rotateSideStickers(Face::Up, true);
    return *this;
}
RubiksCube &RubiksCubeBitboard::u2()
{
    u();
    u();
    return *this;
}
RubiksCube &RubiksCubeBitboard::uP()
{
    u();
    u();
    u();
    return *this;
}

RubiksCube &RubiksCubeBitboard::d()
{
    rotateFace(Face::Down);
    // rotateSideStickers(Face::Down, true);
    return *this;
}
RubiksCube &RubiksCubeBitboard::d2()
{
    d();
    d();
    return *this;
}
RubiksCube &RubiksCubeBitboard::dP()
{
    d();
    d();
    d();
    return *this;
}

RubiksCube &RubiksCubeBitboard::l()
{
    rotateFace(Face::Left);
    // rotateSideStickers(Face::Left, true);
    return *this;
}
RubiksCube &RubiksCubeBitboard::l2()
{
    l();
    l();
    return *this;
}
RubiksCube &RubiksCubeBitboard::lP()
{
    l();
    l();
    l();
    return *this;
}

RubiksCube &RubiksCubeBitboard::r()
{
    rotateFace(Face::Right);
    // rotateSideStickers(Face::Right, true);
    return *this;
}
RubiksCube &RubiksCubeBitboard::r2()
{
    r();
    r();
    return *this;
}
RubiksCube &RubiksCubeBitboard::rP()
{
    r();
    r();
    r();
    return *this;
}

RubiksCube &RubiksCubeBitboard::f()
{
    rotateFace(Face::Front);
    // rotateSideStickers(Face::Front, true);
    return *this;
}
RubiksCube &RubiksCubeBitboard::f2()
{
    f();
    f();
    return *this;
}
RubiksCube &RubiksCubeBitboard::fP()
{
    f();
    f();
    f();
    return *this;
}

RubiksCube &RubiksCubeBitboard::b()
{
    rotateFace(Face::Back);
    // rotateSideStickers(Face::Back, true);
    return *this;
}
RubiksCube &RubiksCubeBitboard::b2()
{
    b();
    b();
    return *this;
}
RubiksCube &RubiksCubeBitboard::bP()
{
    b();
    b();
    b();
    return *this;
}
