//
// Created by leogm99 on 5/11/21.
//

#ifndef HELLO_CUCUMBER_CPP_SETOPERATOR_H
#define HELLO_CUCUMBER_CPP_SETOPERATOR_H

#include <set>
#include <vector>

template<class T>
class SetOperator {
private:
    std::set<T> first, second;
public:
    SetOperator()= default;
    // C++ gibberish
    SetOperator(const SetOperator& other) = delete;
    SetOperator& operator=(const SetOperator& other) = delete;

    // we define the sets to be operated on
    void define_sets(std::set<T>& first_set, std::set<T>& second_set) {
        first = std::move(first_set), second = std::move(second_set);
    }

    // calculates set union
    std::vector<T> calculateUnion() const {
        std::vector<T> unionResult;
        std::ranges::set_union(first, second, std::back_inserter(unionResult));
        return unionResult;
    }

    // calculates set intersection
    std::vector<T> calculateIntersection() const {
        std::vector<T> intersectionResult;
        std::ranges::set_intersection(first, second, std::back_inserter(intersectionResult));
        return intersectionResult;
    }

    // calculates set difference
    std::vector<T> calculateDifference() const {
        std::vector<T> differenceResult;
        std::ranges::set_difference(first, second, std::back_inserter(differenceResult));
        return differenceResult;
    }


    ~SetOperator()= default;
};

#endif //HELLO_CUCUMBER_CPP_SETOPERATOR_H
