#pragma once
#include <iostream>
#include <vector>

template <typename C>
int getMinIndex(std::vector<C> &list, int last);

template <typename C>
void insertion_sort(std::vector<C> &list);


enum class Quartiles
{
	Q1 = 1,
	Q2,
	Q3
};

using DataList = std::vector<double>;

double calculateAverage(DataList &list);
//Calculates the mean

std::pair<double, bool> findMode(DataList &list);

void findAverages(DataList &list);
//Prints the mean, median and mode

double calculateQuartile(DataList &list, Quartiles q = Quartiles::Q2);//Calculates the lower quartile, mean or upper quartile

double getPercentile(double percentile, int length);
//Finds the pposition of value
//that is percentile % of the way through the distriburion

void measuresOfDispersion(DataList &list);
//Prints the lower, middle and upper quartiles, interquarile range and
//range, maximum and minimum of data set

#include "summary.cpp"
