#ifndef FTLEXICOGRAPHICALCOMPARE_HPP
# define FTLEXICOGRAPHICALCOMPARE_HPP

namespace ft
{
	template<class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
	{
		for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
		{
			if (*first1 < *first2)
				return true;
			if (*first2 < *first1)
				return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	template<class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp)
	{
		(void)comp;
		for (; (first1 != last1) & (first2 != last2); ++first1, (void) ++first2)
		{
			if (first1->first < first2->first)
				return true;
			if (first2->first < first1->first)
				return false;
			if (first1->second < first2->second)
				return true;
			if (first2->second < first1->second)
				return false;
		}

		return ((first1 == last1) && (first2 != last2));
	}
}

#endif