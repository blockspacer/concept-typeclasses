#pragma once

template<typename T> struct instances {};

template<typename T> auto mempty = instances<T>::Monoid::mempty;
template<typename T> auto mappend = instances<T>::Monoid::mappend;
