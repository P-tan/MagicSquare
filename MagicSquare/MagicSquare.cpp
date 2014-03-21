#include <algorithm>
#include <iostream>
#include <vector>
#include <boost/dynamic_bitset.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>

using namespace std;
using namespace boost;

bool CheckMagicSquare(const vector<int> &result, int n)
{
	const int sum = n * (n*n + 1) / 2;
	for (int i = 0; i < n; ++i)
	{
		// s 
		if (accumulate(result.begin() + i * n, result.begin() + i * n + n, 0) != sum)
		{
			return false;
		}
		// —ñ
		int s = 0;
		for (int j = 0; j < n; ++j)
		{
			s += result[j*n + i];
		}
		if (s != sum)
		{
			return false;
		}
	}
	// ‘ÎŠpü
	int diag_sum[2] = {};
	for (int i = 0; i < n; ++i)
	{
		diag_sum[0] += result[i*n + i];
		diag_sum[1] += result[i * n + n - i - 1];
	}
	return all_of(diag_sum, diag_sum + 2, [&](int s) { return s == sum; });
}

long long EnumerateMagicSquare(int n)
{
	std::vector<int>	result(n*n);
	iota(result.begin(), result.end(), 1);
	long long count = 0;
	do
	{
		if (CheckMagicSquare(result, n))
		{
			++count;
		}
	}
	while(boost::next_permutation(result));
	return count;
}

int main()
{
	cout << EnumerateMagicSquare(3);	
}