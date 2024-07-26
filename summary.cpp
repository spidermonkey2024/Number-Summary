/*summary.cpp*/
#include <cmath>

template <typename C>
int getMinIndex(std::vector<C> &list, int last)
{
	int first = last - 1;
	int minIndex = first;

	while (first >= 0)
	{
		if (list[first] > list[last])
		{
			minIndex = first;
		}
		first--;
	}
	return minIndex;
} //end getMinIndex

template <typename C>
void insertion_sort(std::vector<C> &list)
{
	int firstOutOfOrder;
	int location;

	for (firstOutOfOrder = 1; firstOutOfOrder < list.size(); ++firstOutOfOrder)
	{
		int insertIndex = getMinIndex(list, firstOutOfOrder);

		if (list[insertIndex] > list[firstOutOfOrder])
		{
			auto temp = list[firstOutOfOrder];
			location = firstOutOfOrder;

			do
			{
				list[location] = list[location - 1];
				--location;
			} while (location > insertIndex);

			list[insertIndex] = temp;
		}
	}
} //end insertion_sort

double calculateAverage(DataList &list)
{
	auto sum{0.0};
	auto length{list.size()};

	for (int index = 0; index < length; ++index)
	{
		sum += list[index];
	}

	return sum / length;
} //end calculateAverages

std::pair<double, bool> findMode(DataList &list)
{
	//Keep track of number of appearances for each value
	//p.first is value, p.second is count
	std::unordered_map<double, int> seqList;
	double val;

	for (int index = 0; index < list.size(); ++index)
	{
		val = list[index];
		++seqList[val];
	}

	//Find value with maximum occurence
	auto maxOccur = DBL_MIN;
	double value;

	for (const auto &p : seqList)
	{
		if (p.second > maxOccur)
		{
			maxOccur = p.second;
			value = p.first;
		}
	}

	//Count how many times max count is found
	auto count{0};
	for (const auto &p : seqList)
	{
		if (p.second == maxOccur)
			++count;
	}

	if (count == 1)
		return std::make_pair(value, true);
	else
		return std::make_pair(-1, false);
} //end findMode


void findAverages(DataList &list)
{
	//Calculate the mean
	auto average = calculateAverage(list);
	std::cout << "\n\nMean: " << std::setprecision(4) << average << "\n";

	//Find the median
	std::cout << "Median: " << calculateQuartile(list) << "\n";

	//Find the mode
	auto mode = findMode(list);

	std::cout << "Mode: ";
	if (mode.second)
		std::cout << mode.first;
	else
		std::cout << "No mode is found.";
	std::cout << "\n";
} //end findAverages


double calculateRange(DataList &list)
{
	return list[list.size() - 1] - list[0];
} //end calculateRange

double calculateQuartile(DataList &list, Quartiles q)
{
	auto numOfElems = list.size();
	int startIndex{0};
	auto median{0.0};
	auto loopCount{1};
	int qPos;

	do
	{
		if (numOfElems % 2 == 0)
		{
			qPos = startIndex + numOfElems / 2;
			median = (list[qPos - 1] + list[qPos]) / 2;
			numOfElems = qPos;
		}
		else
		{
			qPos = startIndex + (numOfElems + 1) / 2;
			median = list[qPos - 1];
			numOfElems = qPos - 1;
		}
		if (q == Quartiles::Q3)
			startIndex += qPos;
		++loopCount;
	} while (q != Quartiles::Q2 && loopCount <= 2);

	return median;
} //end calculateQuartile

double getPercentile(double percentile, int length)
{
	return std::round(percentile / 100 * length);
}//end getPercentile

void measuresOfDispersion(DataList &list)
{
	auto lowerQuartile = calculateQuartile(list, Quartiles::Q1);

	std::cout << "\nLower Quartile: " << lowerQuartile;

	auto upperQuartile = calculateQuartile(list, Quartiles::Q3);

	std::cout << "\nUpper Quartile: " << upperQuartile;

	std::cout << "\nInterquartile Range: " << (upperQuartile - lowerQuartile);

	auto lastIndex = list.size() - 1;
	std::cout << "\n\nRange: " << list[lastIndex] - list[0];
	std::cout << "\nMaximum: " << list[lastIndex];
	std::cout << "\nMinimum: " << list[0];
} //end computeMeasuresOfDispersion