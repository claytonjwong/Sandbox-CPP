// https://stackoverflow.com/questions/54262723/simple-template-class-with-overloaded-operator-fails-invalid-use-of-templat/

#pragma once

#include <iostream>
#include <string>


//class must be forward declared because it contains a friend function template
template<class T> class messageTemplate;

//friend function also must be forwards declared
template<class A> std::ostream &operator<<(std::ostream &os, messageTemplate<A> &aTemplate);

template <class T>
class messageTemplate {
public:
    messageTemplate(const std::string &topic, T data);

    template <class A>
    friend std::ostream &operator<<(std::ostream &os, messageTemplate<A> &aTemplate);

private:
    std::string topic;
    T data;
};

template<class T>
messageTemplate<T>::messageTemplate(const std::string &topic, T data):topic(topic), data(data) {};

template <class T>
std::ostream &operator<< (std::ostream &os, messageTemplate<T> &aTemplate) {
    os << "topic: " << aTemplate.topic << " data: " << aTemplate.data;
    return os;
};

