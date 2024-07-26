#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <cfloat>

#include "summary.h"

int main(int argc, char *argv[])
{
	DataList list = {52, 58, 67, 55, 61, 55, 63, 59, 50, 58,
					 66, 53, 60, 54, 57, 62, 74, 58, 51, 55,
					 51, 72, 61, 77, 65, 58, 53, 55, 61, 55};

	insertion_sort(list);
	std::cout << "List: ";
	for (const auto &elem : list)
		std::cout << elem << " ";

	findAverages(list);

	auto percentile = 90; //percentile in %
	std::cout << "\nThe " << percentile << "th percentile is the  " << getPercentile(percentile, list.size()) << "th value\n";

	measuresOfDispersion(list);
} //end main
