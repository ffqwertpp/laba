#pragma once

export module pawn;
import std;

export class Pawn {
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
        
        int getColor() const {
            return color;
        }

        int getCoordinates() const {
            return (x, y);
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

        bool canMoveWithAnotherPawns(int newX, int newY, const std::vector<Pawn>& Pawns) const {
            for (const auto& pawn : Pawns) {
                if (pawn.getX() == newX && pawn.getY() == newY) {
                    return false;
                }
            }
            return true;
        }

        bool canCaptureWithAnotherPawns(int newX, int newY, const std::vector<Pawn>& Pawns) const {
            for (const auto& pawn : Pawns) {
                if (pawn.getX() == newX && pawn.getY() == newY && pawn.getColor() != color) {
                    return true;
                }
            }
            return false;
        }
};

export Pawn findPawnWhichCanMoveOnCoordinates(int x, int y, const std::vector<Pawn>& Pawns) {
    for (const auto& pawn : Pawns) {
        if (pawn.canMove(x, y)) {
            return pawn;
        }
    }
    return Pawn();
}