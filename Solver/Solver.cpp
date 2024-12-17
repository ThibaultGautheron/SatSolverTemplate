/**
* @author Tim Luchterhand
* @date 27.11.24
* @brief
*/

#include "Solver.hpp"
#include "util/exception.hpp"
#include <deque>
namespace sat {
    Solver::Solver(unsigned numVariables) {
        std::vector<TruthValue> m(numVariables, sat::TruthValue::Undefined);
        model = m;
    }

    bool Solver::addClause(Clause clause) {
        if (clause.empty() || clause.size() == 1 ) return false;
        auto cp = std::make_shared<Clause>(clause);
        clauses.push_back(cp);
        return true;
    }

    auto Solver::rebase() const -> std::vector<Clause> {
       std::vector<Clause> reduced;
       for (const ClausePointer clause : clauses){
            bool satisfiedClause = false;
            std::vector<Literal> finalClause = *clause;

            for(const Literal literal : *clause){
                if(satisfied(literal)) satisfiedClause = true;
                else if(falsified(literal)) finalClause.erase(std::remove(finalClause.begin(),finalClause.end(), literal), finalClause.end());
            }
            if(!satisfiedClause){
                reduced.push_back(finalClause);
            }

        }
        reduced.push_back(unitLiterals);
        return reduced;

       }
    

    TruthValue Solver::val(Variable x) const {
        return model.at(x.get());
    }

    bool Solver::satisfied(Literal l) const {
        TruthValue value = model.at(var(l).get());
        if (value == TruthValue::Undefined) return false;
        return ((value == TruthValue::True && l.sign() == 1 )||
                (value == TruthValue::False && l.sign() == -1));
    }

    bool Solver::falsified(Literal l) const {
        TruthValue value = model.at(var(l).get());
        if (value == TruthValue::Undefined) return false;
        return ((value == TruthValue::True && l.sign() == -1) ||
                (value == TruthValue::False && l.sign() == 1));
    }

    bool Solver::assign(Literal l) {
        
        if (model.at(var(l).get()) == TruthValue::True) {
            return satisfied(l);
        }

        if (model.at(var(l).get()) == TruthValue::False) {
            return falsified(l);
        }

        model.at(var(l).get()) = l.sign() == -1 ? TruthValue::False : TruthValue::True;
        return true;

    }
/*Organise clauses per literals (Clauses(l) is the set of clauses containing literal l)
keep an initially null counter #fi of false literals for each clause ci
Put all unit clauses (true literals) in a list
while There is a non-processed true literal l do
mark l as processed
foreach ci ∈ Clauses(l) do
increment #fi // at most once per literal: O(s)
if #fi = |ci | then return FAIL
if #fi = |ci | − 1 then
find the last literal and add it to the list of true literals // Θ(|ci |) at most once per clause: O(s)*/

    bool Solver::unitPropagate() {
       /* std::vector<std::size_t> counter_f;
        std::deque<Variable> truthList;
        for(std::size_t var_id = 0; var_id < model.size(); var_id++){
            
            if(model.at(var_id) == TruthValue::True){
                truthList.push_back(Variable(var_id));
            }
        }

        while(truthList.size() != 0){
            Variable v = truthList.at(0);
            truthList.pop_front();

            for(std::size_t ci = 0; ci < watchedBy.at(v.get()).size(); ci++){
                Clause clause_i = watchedBy.at(v.get()).at(ci);
                counter_f.at(v.get())++;
                if (counter_f.at(v.get()) == clause_i.size()){
                    return false;
                }
                if (counter_f.at(v.get()) == clause_i.size()-1){
                    Literal l = clause_i.at(clause_i.size()-1);
                    truthList.push_back(var(l));
                }
            }
        }
        return true;*/
    }
} // sat