#include <cucumber-cpp/autodetect.hpp>
#include <string>
#include "../../src/SetOperator.h"
#include <set>

using cucumber::ScenarioScope;

template<class T>
struct SetOperatorContext {
    SetOperator<T> setOperator;
    std::vector<T> result;
};

// NUMEROS

GIVEN("^que tengo dos conjuntos de numeros") {
    TABLE_PARAM(tabla);
    auto& aux = tabla.hashes();
    ScenarioScope<SetOperatorContext<int>> context;
    std::set<int> first;
    std::set<int> second;
    for (auto& elem : aux) {
        int elem_first_set = std::stoi(elem.at("conjunto_1"));
        int elem_second_set = std::stoi(elem.at("conjunto_2"));
        first.emplace(elem_first_set);
        second.emplace(elem_second_set);
    }
    context->setOperator.define_sets(first, second);
}

WHEN("^realizo la interseccion entre los conjuntos de numeros") {
    ScenarioScope<SetOperatorContext<int>> context;
    context->result = context->setOperator.calculateIntersection();
}

WHEN("^realizo la diferencia entre los conjuntos de numeros") {
    ScenarioScope<SetOperatorContext<int>> context;
    context->result = context->setOperator.calculateDifference();
}

WHEN("^realizo la unión entre los conjuntos de numeros") {
    ScenarioScope<SetOperatorContext<int>> context;
    context->result = context->setOperator.calculateUnion();
}

THEN("^obtengo el conjunto de numeros resultado") {
    TABLE_PARAM(tabla);
    ScenarioScope<SetOperatorContext<int>> context;
    std::vector<int> expected;
    auto& aux = tabla.hashes();

    for (auto& elem : aux) {
        int res = std::stoi(elem.at("conjunto_resultado"));
        expected.push_back(res);
    }
    //ASSERT_EQ(expected, context->result);
    std::vector<int> bad_result{1};
    ASSERT_EQ(expected, bad_result);
}

// NOMBRES

GIVEN("^que tengo dos conjuntos de nombres"){
    TABLE_PARAM(names);
    ScenarioScope<SetOperatorContext<std::string>> context;
    auto& aux = names.hashes();
    std::set<std::string> first;
    std::set<std::string> second;
    for (auto& elem : aux) {
        auto& elem_first_set = elem.at("conjunto_1");
        auto& elem_second_set = elem.at("conjunto_2");
        first.emplace(elem_first_set);
        second.emplace(elem_second_set);
    }
    context->setOperator.define_sets(first, second);
}

WHEN("^realizo la interseccion entre los conjuntos de nombres") {
    ScenarioScope<SetOperatorContext<std::string>> context;
    context->result = context->setOperator.calculateIntersection();
}

WHEN("^realizo la diferencia entre los conjuntos de nombres") {
    ScenarioScope<SetOperatorContext<std::string>> context;
    context->result = context->setOperator.calculateDifference();
}

WHEN("^realizo la unión entre los conjuntos de nombres") {
    ScenarioScope<SetOperatorContext<std::string>> context;
    context->result = context->setOperator.calculateUnion();
}

THEN("^obtengo el conjunto de nombres resultado") {
    TABLE_PARAM(names);
    ScenarioScope<SetOperatorContext<std::string>> context;
    std::vector<std::string> expected;
    auto& aux = names.hashes();

    for (auto& elem : aux) {
        auto res = elem.at("conjunto_resultado");
        expected.push_back(res);
    }

    ASSERT_EQ(expected, context->result);
}