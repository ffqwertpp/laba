#pragma once

export module pawn;
import std;

class Pawn {
    private:
        bool color = true;
        int x = 0;
        int y = 0;
        bool canMoveForward = true;
        bool firstMove = true;
    public:
        Pawn() = default;
        Pawn(int x, int y, bool color, bool firstMove, bool canMoveForward) : x(x), y(y), color(color), firstMove(firstMove), canMoveForward(canMoveForward) {}

        int getX() const {
            return x;
        }

        int getY() const {
            return y;
        }

        bool canMove(int newX, int newY) const {
            int dx = newX - x;
            int dy = newY - y;
            if (color) {
                if (firstMove) {
                    return (dx == 0 && (dy == 1 || dy == 2));
                } else {
                    return (dx == 0 && dy == 1);
                }
            }else {
                if (firstMove) {
                    return (dx == 0 && (dy == -1 || dy == -2));
                } else {
                    return (dx == 0 && dy == -1);
                }
            }
        }

        bool canCapture(int newX, int newY) const {
            int dx = newX - x;
            int dy = newY - y;
            if (color) {
                return (std::abs(dx) == 1 && dy == 1);
            } else {
                return (std::abs(dx) == 1 && dy == -1);
            }
        }

        bool canMoveWithAnotherPawns(int newX, int newY, const std::vector<Pawn>& otherPawns) const {
            for (const auto& pawn : otherPawns) {
                if (pawn.getX() == newX && pawn.getY() == newY) {
                    return false;
                }
            }
            return true;
        }

        bool canCaptureWithAnotherPawns(int newX, int newY, const std::vector<Pawn>& otherPawns) const {
            for (const auto& pawn : otherPawns) {
                if (pawn.getX() == newX && pawn.getY() == newY) {
                    return true;
                }
            }
            return false;
        }
};

Pawn findPawnWhichCanMoveOnCoordinates(int x, int y, const std::vector<Pawn>& pawns) {
    for (const auto& pawn : pawns) {
        if (pawn.canMove(x, y)) {
            return pawn;
        }
    }
    return Pawn();
}