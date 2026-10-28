#pragma once

template <typename T> void swap(T &x, T &y)
{
	T temp = x;

	x = y;
	y = temp;
}

template <typename T> T min(T a, T b)
{
	return((a < b ) ? a : b);
}

template <typename T> T max(T a, T b)
{
	return((a > b ) ? a : b);
}