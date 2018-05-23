#if !defined include_subject_h
#define include_subject_h
#include <functional>
#include <utility>
#include <map>
#include <vector>
using std::function;
using std::forward;
using std::map;
using std::move;
using std::vector;

// Code nearly wholly-derivative of work by user Juan Chopanza located at:
// https://juanchopanzacpp.wordpress.com/2013/02/24/simple-observer-pattern-implementation-c11/
// Article was written for the express purpose of sharing code but I am noting
// this for legal purposes and will refactor to a more standard observer
// pattern if needed.

template <typename Event>
class Subject
{
public:
    template <typename Observer>
    void RegisterObserver (Event const & event, Observer && observer)
    {
        observers_[event].push_back (forward<Observer> (observer));
    }

    template <typename Observer>
    void RegisterObserver (Event && event, Observer && observer)
    {
        observers_[move (event)].push_back (forward<Observer> (observer));
    }

    void Notify (const Event& event) const
    {
        for (const auto& obs : observers_.at (event)) obs ();
    }

private:
    map<Event, vector<function<void ()>>> observers_;
};

#endif
