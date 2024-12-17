/**
* @author Tim Luchterhand
* @date 26.11.24
* @brief
*/

#include <cassert>
#include <algorithm>
#include <Iterators.hpp>

#include "Clause.hpp"
#include "util/exception.hpp"

namespace sat {
    //TODO implementation here

    // Clause::Clause(std::vector<Literal> literals) {
    //     _literals = literals;
    // }

    // short Clause::getRank(Literal l) const {
    //     if (l == watcher1) return 0;
    //     if (l == watcher2) return 1;
    //     return -1;
    // }

    // std::size_t Clause::getIndex(short rank) const {
    //     for (std::size_t i = 0; i < _literals.size(); i++){
    //         if ((rank == 0 && _literals[i] == watcher1) || (rank != 0 && _literals[i] == watcher2)) return i;
    //     }
    //     return -1;
    // }

    // bool Clause::setWatcher(Literal l, short watcherNo) {
    //     bool present = false;
    //     for (std::size_t i = 0; i < _literals.size(); i++) {
    //         if (_literals[i] == l) {
    //             present = true;
    //             break;
    //         }
    //     }
    //     if (!present) return false;

    //     if (watcherNo == 0) watcher1 = l;
    //     else watcher2 = l;
    //     return true;
    // }

    // auto Clause::begin() const -> std::vector<Literal>::const_iterator {
    //     throw NOT_IMPLEMENTED;
    // }

    // auto Clause::end() const -> std::vector<Literal>::const_iterator {
    //     throw NOT_IMPLEMENTED;
    // }

    // bool Clause::isEmpty() const {
    //     throw NOT_IMPLEMENTED;
    // }

    // Literal Clause::operator[](std::size_t index) const {
    //     throw NOT_IMPLEMENTED;
    // }

    // std::size_t Clause::size() const {
    //     throw NOT_IMPLEMENTED;
    // }

    // Literal Clause::getWatcherByRank(short rank) const {
    //     throw NOT_IMPLEMENTED;
    // }

    // bool Clause::sameLiterals(const Clause &other) const {
    //     throw NOT_IMPLEMENTED;
    // }

}
